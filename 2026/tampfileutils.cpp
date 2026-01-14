#include "player.hpp"


int extract_int(const std::string& line) {
    size_t colon = line.find(':');
    if (colon == std::string::npos) return 0;
    size_t start = line.find_first_not_of(" \t", colon + 1);
    return atoi(line.c_str() + start);
}

int extract_scene_number(const std::string& scene_value) {
    size_t last_space = scene_value.find_last_of(' ');
    if (last_space != std::string::npos) {
        return atoi(scene_value.c_str() + last_space + 1);
    }
    return 0; // No space found, default to 0
}