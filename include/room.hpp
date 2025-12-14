
#include "JFLX/logging.hpp"
#include <iostream>
#include <cstdint>

//++ Data Structures
#include <array>
#include <vector>
#include <deque>

struct Chunk;

static constexpr int CHUNKSIZE = 16;

std::deque<Chunk*> generationQueue;
std::vector<Chunk*> allChuncks;

/*
++ A simple Struct for Storing Index Data
*/
struct Tile {
    // Basic type flags
    bool isWall           = false;
    bool isGround         = false;
    bool isLocker         = false;
    bool isShelf          = false;
    bool isChunkConnection = false;

    // Interaction
    bool searchable       = false;
    bool wasSearched      = false;

    // Identity
    uint8_t tileID        = 0;

    // Decoration
    bool hasDecor         = false;
    uint8_t decorID       = 0;

    // Items
    bool hasItem          = false;
    uint8_t itemID        = 0;
};

/*
++ Chunk Connection Struct
*/
struct ChunkConnection {
private:
    int rc_width = 1;
    int rc_posX  = 0;
    int rc_posY  = 0;

    Chunk* rc_Chunk0 = nullptr;
    Chunk* rc_Chunk1 = nullptr;

public:
    ChunkConnection(Chunk* c0, Chunk* c1, int width, int posX, int posY)
        : rc_width(width), rc_posX(posX), rc_posY(posY), rc_Chunk0(c0), rc_Chunk1(c1) {}

    bool isValid() const {
        return rc_Chunk0 && rc_Chunk1;
    }

    Chunk* getConnectingChunk(Chunk* current) const {
        if (current == rc_Chunk0) return rc_Chunk1;
        if (current == rc_Chunk1) return rc_Chunk0;
        return nullptr;
    }

    int getWidth() const { return rc_width; }
    int getPosX()  const { return rc_posX; }
    int getPosY()  const { return rc_posY; }

    Chunk* getChunk0() const { return rc_Chunk0; }
    Chunk* getChunk1() const { return rc_Chunk1; }
};

/*
++ The Tile layout for a Chunk
*/
struct Layout {
private:
    std::array<Tile, CHUNKSIZE * CHUNKSIZE> arrangement;

public:
    Layout() {}

    Tile& get(int x, int y) {
        return arrangement[y * CHUNKSIZE + x];
    }

    Tile* getSafe(int x, int y) {
        if (x < 0 || y < 0 || x >= CHUNKSIZE || y >= CHUNKSIZE) return nullptr;
        return &arrangement[y * CHUNKSIZE + x];
    }

    int getSizeX() const { return CHUNKSIZE; }
    int getSizeY() const { return CHUNKSIZE; }

    void fill(const Tile& preset) {
        for (int y = 0; y < CHUNKSIZE; y ++) {
            for (int x = 0; x < CHUNKSIZE; x ++) {
                arrangement[y * CHUNKSIZE + x] = preset;
            }
        }
    }
};

/*
++ The Completed Chunk with all Data
*/
struct Chunk {
private:
    Layout* c_layout = nullptr;
    std::vector<ChunkConnection*> c_connections;

public:
    uint32_t chunkID = 0;

    explicit Chunk(uint32_t id) : chunkID(id) {}

    bool setLayout(Layout* layout) {
        if (!layout) return false;
        c_layout = layout;
        return true;
    }

    Layout* getLayout() const {
        return c_layout;
    }

    void addConnection(ChunkConnection* c) {
        if (c) c_connections.push_back(c);
    }

    const std::vector<ChunkConnection*>& getConnections() const {
        return c_connections;
    }

    ChunkConnection* getConnectionTo(Chunk* other) const {
        for (auto* c : c_connections)
            if (c->getConnectingChunk(const_cast<Chunk*>(this)) == other)
                return c;
        return nullptr;
    }
};


