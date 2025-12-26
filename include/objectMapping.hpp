#pragma once

#include <string>
#include <cstdint>

//-> Objects Based on: https://backrooms-wiki.wikidot.com/objects
enum class objectIDs : uint16_t {
    EMPTY,
    ALMONDWATER,

    Count,
    UNKNOWN = UINT16_MAX
};

objectIDs getObjectID(std::string objectName) {
    if (objectName == "EMPTY")          return objectIDs::EMPTY;
    if (objectName == "Almond Water")   return objectIDs::ALMONDWATER;


    
    // if (objectName == "")  return objectIDs::;
    return objectIDs::UNKNOWN;
}

std::string getObjectName(uint16_t objectID) {
    if (objectID == static_cast<uint16_t>(objectIDs::EMPTY)) return "Empty";
    if (objectID == static_cast<uint16_t>(objectIDs::ALMONDWATER)) return "Almond Water";



    // if (objectID == static_cast<uint16_t>(objectIDs::)) return "";
    return "Unknown";
}
