#include "utils.hpp"
#include "../player.hpp"

int check_scene(pc *player) {
    std::string scene = find_line("./datas/player_data.json", "\"scene\"");
    std::cout << "SCENE:" << scene << std::flush;
    if (scene.empty()) return -1;
    
    size_t colon_pos = scene.find(':');
    if (colon_pos == std::string::npos) return -1;
    
    size_t first_quote = scene.find('\"', colon_pos);
    if (first_quote != std::string::npos) {
        size_t second_quote = scene.find('\"', first_quote + 1);
        if (second_quote != std::string::npos) {
            std::string scene_value = scene.substr(first_quote + 1, second_quote - first_quote - 1);
            size_t space_pos = scene_value.find(' ');
            if (space_pos != std::string::npos) {
                // Format: "intro 0"
                player->scene = atoi(scene_value.c_str() + space_pos + 1);
                return player->scene;
            } else {
                // Format: just "intro" with no number - default to 0
                player->scene = 0;
                return 0;
            }
        }
    }
    
    // Couldn't parse - check if it's a plain number
    size_t start = scene.find_first_not_of(" \t", colon_pos + 1);
    if (start != std::string::npos && isdigit(scene[start])) {
        player->scene = atoi(scene.c_str() + start);
        return player->scene;
    }
    
    return -1;
}