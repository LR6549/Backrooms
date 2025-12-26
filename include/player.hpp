#pragma once

#include "room.hpp"
#include "objectMapping.hpp"

struct Player {
    // World-space position in pixels
    float x = 0.0f;
    float y = 0.0f;

    // Velocity (optional)
    float vx = 0.0f;
    float vy = 0.0f;

    // Size in pixels
    float width  = 64.0f;
    float height = 64.0f;

    // Inventory (object IDs)
    std::array<objectIDs, 10> inventory = {objectIDs::EMPTY};
};

Player player;

bool isWallAtWorld(ChunkManager& mgr, float worldX, float worldY) {
    int chunkX = worldToChunk(worldX);
    int chunkY = worldToChunk(worldY);

    Chunk* c = mgr.getChunk(chunkX, chunkY);
    if (!c) return true; // not loaded = solid

    int tx = worldToLocalTile(worldX);
    int ty = worldToLocalTile(worldY);

    Tile* t = c->get(tx, ty);
    return t && t->isWall;
}
