
#include "JFLX/logging.hpp"
#include <iostream>
#include <cstdint>
#include <vector>

/*
++ A simple Struct for Storing Index Data
*/
struct Tile {
    //-> Basic types
    bool isWall             = false;
    bool isGround           = false;
    bool isLocker           = false;
    bool isShelf            = false;
    bool isRoomConnection   = false;

    //-> Interactions
    bool searchable         = false;
    bool wasSearched        = false;

    //-> Identity
    uint8_t tileID          = 0;

    //-> Decoration
    bool hasDecor           = false;
    uint8_t decorID         = 0;

    //-> items
    bool hasItem            = false;
    uint8_t itemID          = 0;
};

struct Room;

/*
++ Room Connection Struct
* 
*/
struct RoomConnection {
private:
    int   rc_width = 1;
    int   rc_posX  = 0;
    int   rc_posY  = 0;

    Room* rc_Room0 = nullptr;
    Room* rc_Room1 = nullptr;

public:
    RoomConnection(Room* room0, Room* room1, int width, int posX, int posY)
        : rc_width(width), rc_posX(posX), rc_posY(posY), rc_Room0(room0), rc_Room1(room1) {}

    Room* getConnectingRoom(Room* currentRoom) {
        if (currentRoom == rc_Room0) return rc_Room1;
        if (currentRoom == rc_Room1) return rc_Room0;
        return nullptr;
    }

    bool setRoom0(Room* newRoom) {
        if (newRoom == nullptr) return false;
        rc_Room0 = newRoom;
        return true;
    }

    bool setRoom1(Room* newRoom) {
        if (newRoom == nullptr) return false;
        rc_Room1 = newRoom;
        return true;
    }

    int getWidth() const { return rc_width; }
    int getPosX() const { return rc_posX; }
    int getPosY() const { return rc_posY; }

    Room* getRoom0() const { return rc_Room0; }
    Room* getRoom1() const { return rc_Room1; }
};

/*
++ The Layout for a Room
* Use: Layout<sizeX, sizeY>();
*/
struct Layout {
private:
    int l_sizeX = 0;
    int l_sizeY = 0;

    std::vector<std::vector<Tile>> arrangement;

public:
    Layout(int sizeX, int sizeY)
        : l_sizeX(sizeX), l_sizeY(sizeY)
    {
        arrangement.resize(l_sizeY, std::vector<Tile>(l_sizeX));
    }

    Tile& get(int x, int y) {
        return arrangement[y][x];
    }

    const Tile& get(int x, int y) const {
        return arrangement[y][x];
    }

    Tile* getSafe(int x, int y) {
        if (x < 0 || y < 0 || x >= l_sizeX || y >= l_sizeY) return nullptr;
        return &arrangement[y][x];
    }

    int getSizeX() const { return l_sizeX; }
    int getSizeY() const { return l_sizeY; }

    std::vector<std::vector<Tile>>& getArrangement() { return arrangement; }

    const std::vector<std::vector<Tile>>& getArrangement() const { return arrangement; }

    // Procedural helper
    void fill(Tile preset) {
        for (auto& row : arrangement)
            for (auto& t : row)
                t = preset;
    }
};



/*
++ The Completed Room with all Data
*/
struct Room {
private:
    Layout* r_Layout = nullptr;
    std::vector<RoomConnection*> r_connections;

public:
    uint32_t roomID = 0;

    Room(int ID) : roomID(ID) {

    } 

    bool setLayout(Layout* newLayout) {
        if (!newLayout) return false;
        r_Layout = newLayout;
        return true;
    }

    bool hasLayout() const {
        return r_Layout != nullptr;
    }

    Layout* getLayout() const {
        return r_Layout;
    }

    void addConnection(RoomConnection* c) {
        if (c) r_connections.push_back(c);
    }

    const std::vector<RoomConnection*>& getConnections() const {
        return r_connections;
    }

    int getConnectionCount() const {
        return static_cast<int>(r_connections.size());
    }

    RoomConnection* getConnectionTo(Room* other) {
        for (auto* c : r_connections) {
            if (c->getConnectingRoom(this) == other) 
                return c;
        }
        return nullptr;
    }
};

