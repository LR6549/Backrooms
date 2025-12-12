//_ CRUSADIA - Tile HPP FILE _//_ COPYRIGHT (C) 2024 JFLX STUDIO - ALL RIGHTS RESERVED _//

#include <iostream>
#include <cstdint>
#include <vector>
#include <array>
#include <JFLX/logging.hpp>
#include "colorStruct.hpp"
#include "tileData.hpp"



struct Tile {
    TILES::BLOCKS::ID  blockID;
    TILES::WALLS::ID   wallID;
    TILES::LIQUIDS::ID liquidID;

    /*
    ++ 8-bit to represent 8 neighbours

    ++Bit Positions:
    0,  0,  0,  0,  0,  0,  0,  0,  0
    TL, TC, TR, CR, CC, CL, BL, BC, BR

    T = Top
    C = Center
    B = Bottom
    L = Left
    R = Right

    ++Neighbour Indexes:
    [0] = block Neighbours
    [1] = wall Neighbours
    [2] = liquid Neighbours
    */
    std::array<uint8_t, 3> neightbours = {
        0b00000000,
        0b00000000,
        0b00000000
    };
};


struct TileDefinition {
    bool solid;
    bool blocksLight;
    bool interactable;
    std::string name;
    // optional: texture index, drop item, sound, etc.
};

/*
    Optional uses:
    if (tileDefs[tile.id].interactable) {
        -> handle interaction
    }
*/

// {
//     AIR         = {false, false, false, "Air"},
//     CLOUD       = {false, false, false, "Cloud"},
//     GRASS       = {true,  true,  false, "Grass Block"},
//     DIRT        = {true,  true,  false, "Dirt Block"},
//     CLAY        = {true,  true,  false, "Clay Block"},
//     STONE       = {true,  true,  false, "Stone Block"},
//     DIORITE     = {true,  true,  false, "Diorite Block"},
//     ANDESITE    = {true,  true,  false, "Andesite Block"},
//     GRANITE     = {true,  true,  false, "Granite Block"},
//     KIMBERLITE  = {true,  true,  false, "Kimberlite Block"},
//     BEDROCK     = {true,  true,  false, "Bedrock"}
// };

struct Item {

};

struct Chest {
    int x, y;
    std::vector<Item> items;
};

std::string getNameById(uint16_t b_id) {
    
    return "Unknown Tile";
}

void setTileIDS(Tile& tile, TILES::BLOCKS::ID blockID = TILES::BLOCKS::ID::NOCHANGE, TILES::WALLS::ID wallID = TILES::WALLS::ID::NOCHANGE, TILES::LIQUIDS::ID liquidID = TILES::LIQUIDS::ID::NOCHANGE) {
    if (blockID  != TILES::BLOCKS::ID::NOCHANGE) {tile.blockID = blockID;}
    if (wallID   != TILES::WALLS::ID::NOCHANGE) {tile.wallID = wallID;}
    if (liquidID != TILES::LIQUIDS::ID::NOCHANGE) {tile.liquidID = liquidID;}
}
