#pragma once

#include "JFLX/logging.hpp"
#include <iostream>
#include <cstdint>

//++ Data Structures
#include <array>
#include <vector>
#include <deque>

#include <SDL3/SDL.h>

#include "player.hpp"

struct Chunk;

static constexpr int CHUNKSIZE = 16;
static constexpr int TILESIZE   = 64;
static constexpr int CHUNKPIXELSIZE   = CHUNKSIZE * TILESIZE;

std::deque<Chunk*> generationQueue;
std::vector<Chunk*> allChuncks;

enum NeighbourBits : uint8_t {
    UP    = 1 << 0, // 0001
    LEFT  = 1 << 1, // 0010
    RIGHT = 1 << 2, // 0100
    DOWN  = 1 << 3  // 1000
};

/*
++ A simple Struct for Storing Index Data
*/
struct Tile {
    // Basic type flags
    bool isWall            = false;
    bool isGround          = false;
    bool isLocker          = false;
    bool isShelf           = false;

    // Interaction
    bool searchable        = false;
    bool wasSearched       = false;

    // Identity
    uint8_t tileID         = 0;

    // Texture ID
    uint8_t tilemapID      = 0;

    // Decoration
    bool hasDecor          = false;
    uint8_t decorID        = 0;

    // Items
    bool hasItem           = false;
    uint8_t itemID         = 0;
};

/*
++ The Completed Chunk with all Data
*/
struct Chunk {
    uint32_t id = 0;
    bool dirty = true;

    Tile tiles[CHUNKSIZE][CHUNKSIZE]{};
    SDL_Texture* texture = nullptr;

    explicit Chunk(uint32_t id_) : id(id_) {}

    Tile* get(int x, int y)  {
        if (x < 0 || y < 0 || x >= CHUNKSIZE || y >= CHUNKSIZE)
            return nullptr;
        return &tiles[y][x];
    }
};


inline bool isWallAt(Chunk& c, int x, int y) {
    Tile* t = c.get(x, y);
    return t && t->isWall;
}

uint8_t computeWallMask(Chunk& c, int x, int y) {
    uint8_t mask = 0;

    if (isWallAt(c, x, y - 1)) mask |= UP;
    if (isWallAt(c, x - 1, y)) mask |= LEFT;
    if (isWallAt(c, x + 1, y)) mask |= RIGHT;
    if (isWallAt(c, x, y + 1)) mask |= DOWN;

    return mask;
}

void autotileChunk(Chunk& c) {
    for (int y = 0; y < CHUNKSIZE; ++y) {
        for (int x = 0; x < CHUNKSIZE; ++x) {
            Tile& t = c.tiles[y][x];

            if (!t.isWall) {
                t.tilemapID = 9; // NONE / floor
                continue;
            }

            t.tilemapID = computeWallMask(c, x, y);
        }
    }

    c.dirty = true;
}

void rebuildChunkTexture(SDL_Renderer* renderer, SDL_Texture* tileset, Chunk& chunk) {
    if (chunk.texture)
        SDL_DestroyTexture(chunk.texture);

    chunk.texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_TARGET,
        CHUNKSIZE * TILESIZE,
        CHUNKSIZE * TILESIZE
    );

    SDL_SetTextureBlendMode(chunk.texture, SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(renderer, chunk.texture);
    SDL_RenderClear(renderer);

    float tsW, tsH;
    SDL_GetTextureSize(tileset, &tsW, &tsH);
    int tilesPerRow = int(tsW) / TILESIZE;

    for (int y = 0; y < CHUNKSIZE; ++y) {
        for (int x = 0; x < CHUNKSIZE; ++x) {
            const Tile& t = chunk.tiles[y][x];
            if (t.tilemapID == 9) continue;

            SDL_FRect src {
                float((t.tilemapID % tilesPerRow) * TILESIZE),
                float((t.tilemapID / tilesPerRow) * TILESIZE),
                float(TILESIZE),
                float(TILESIZE)
            };

            SDL_FRect dst {
                float(x * TILESIZE),
                float(y * TILESIZE),
                float(TILESIZE),
                float(TILESIZE)
            };

            SDL_RenderTexture(renderer, tileset, &src, &dst);
        }
    }

    SDL_SetRenderTarget(renderer, nullptr);
    chunk.dirty = false;
}

inline int worldToChunk(float worldPos) {
    return int(std::floor(worldPos / CHUNKPIXELSIZE));
}

inline int worldToLocalTile(float worldPos) {
    return int(std::floor(worldPos / TILESIZE));
}


void renderChunk(SDL_Renderer* renderer, const Chunk& chunk, float worldX, float worldY) {
    if (!chunk.texture) return;

    SDL_FRect dst {
        worldX,
        worldY,
        float(CHUNKSIZE * TILESIZE),
        float(CHUNKSIZE * TILESIZE)
    };

    SDL_RenderTexture(renderer, chunk.texture, nullptr, &dst);
}

struct ChunkManager {
    std::unordered_map<uint64_t, Chunk> chunks;

    inline int64_t chunkKey(int x, int y) {
        return (int64_t(x) << 32) | uint32_t(y);
    }

    /*
    ++ Get or Create Chunk at given Coordinates
    When Chunk does not exist, it will be created and returned
    */
    Chunk* getChunk(int chunkX, int chunkY) {
        int64_t key = chunkKey(chunkX, chunkY);
        auto it = chunks.find(key);
        if (it != chunks.end()) {
            return &it->second;
        } else {
            Chunk newChunk(uint32_t(chunks.size()));
            chunks[key] = newChunk;
            return &chunks[key];
        }
    }

    void update(SDL_Renderer* renderer, SDL_Texture* tileset) {
        for (auto& [key, chunk] : chunks) {
            //-> Dirty when Further than 2 chunks away from the Player
            if (chunk.dirty) {
                autotileChunk(chunk);
                rebuildChunkTexture(renderer, tileset, chunk);
            }
        }
    }

    void render(SDL_Renderer* renderer) {
        for (auto key : chunks) {
            float wx = float(key.first * CHUNKSIZE * TILESIZE);
            float wy = 0.0f;
            renderChunk(renderer, key.second, wx, wy);
        }
    }
};
