#include "player.hpp"

void set_scene(pc &player,std::string line)
{
    size_t colon = line.find(':');
    size_t start = line.find_first_not_of(" \t", colon + 1);
    if (start != std::string::npos && line[start] == '\"') {
        size_t first_quote = start;
        size_t last_quote = line.find('\"', first_quote + 1);
        if (last_quote != std::string::npos) {
            std::string scene_value = line.substr(first_quote + 1, last_quote - first_quote - 1);
            player.scene = extract_scene_number(scene_value);
        }
    }  else {
        // Scene is just a number
        player.scene = extract_int(line);
    }
}


void load_player(const std::string& fname, pc& player) {
    std::ifstream infile(fname.c_str());
    if (!infile) return;

    std::string line;
    while (std::getline(infile, line)) {
        if (line.find("\"name\":") != std::string::npos) {
            size_t first = line.find_first_of('\"', line.find(':'));
            size_t last = line.find_last_of('\"');
            if (first != std::string::npos && last != std::string::npos && first != last) {
                player.set_name(line.substr(first + 1, last - first - 1));
            }
        }
        else if (line.find("\"scene\":") != std::string::npos) {
            set_scene(player, line);
        }
        else if (line.find("\"reputation\":") != std::string::npos) 
            player.set_rep(rangedInt(extract_int(line), 0, 20));
        else if (line.find("\"affection\":") != std::string::npos) 
            player.set_aff(rangedInt(extract_int(line), 0, 20));
        else if (line.find("\"friendliness\":") != std::string::npos) 
            player.set_friend(rangedInt(extract_int(line), 0, 20));
    }
    infile.close();
}


void save_player(const std::string& fname, pc& player) {
    // Read the current scene name from the file
    std::string current_scene_name = "intro"; // default
    std::string scene_line = find_line(fname, "\"scene\"");
    if (!scene_line.empty()) {
        size_t colon = scene_line.find(':');
        size_t start = scene_line.find_first_not_of(" \t", colon + 1);
        if (start != std::string::npos && scene_line[start] == '\"') {
            // It's a string format
            size_t first_quote = start;
            size_t last_quote = scene_line.find('\"', first_quote + 1);
            if (last_quote != std::string::npos) {
                std::string full_scene = scene_line.substr(first_quote + 1, last_quote - first_quote - 1);
                size_t last_space = full_scene.find_last_of(' ');
                if (last_space != std::string::npos) {
                    current_scene_name = full_scene.substr(0, last_space);
                }
            }
        }
        // else: it's a number format, just use default "intro"
    }
    
    std::ofstream file(fname.c_str());
    file << "{\n";
    file << "  \"name\": \"" << player.get_name() << "\",\n";
    file << "  \"scene\": \"" << current_scene_name << " " << player.scene << "\",\n";
    file << "  \"reputation\": " << player.get_rep() << ",\n";
    file << "  \"affection\": " << player.get_aff() << ",\n";
    file << "  \"friendliness\": " << player.get_friend() << "\n";
    file << "}";
    file.close();
}