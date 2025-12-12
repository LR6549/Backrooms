//_ "Terraria" MAIN CPP FILE _//_ COPYRIGHT (C) 2024 JFLX STUDIO - ALL RIGHTS RESERVED _//

#include <iostream>
#include <cstdint>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <string>
#include <memory>
#include <cmath>
#include <nlohmann/json.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL3_image/SDL_image.h>
#include <SDL3/SDL3_mixer/SDL_mixer.h>
#include <SDL3/SDL3_ttf/SDL_ttf.h>
#include <SDL3/SDL3_rtf/SDL_rtf.h>
#include <SDL3/SDL3_net/SDL_net.h>
#include <JFLX/logging.hpp>
#include <JFLX/jsonFunctionality.hpp>
#include <JFLX/collision.hpp>
#include "mouseButtons.hpp"
#include "buttonStruct.hpp"
#include "colorStruct.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;
json settings, progress;

std::string path = fs::current_path().string() + "/";
