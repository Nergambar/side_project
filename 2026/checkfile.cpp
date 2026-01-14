#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "player.hpp"
class pc;

std::string find_line(std::string filename, std::string target)
{
    std::ifstream infile(filename.c_str());
    if (!infile) return "";

    std::vector<std::string> lines;
    std::string line;

    // Read all lines
    while (std::getline(infile, line))
    {
        if (line.find(target) != std::string::npos)
            return (line);
    }

    infile.close();
    return "";
}


bool starts_with(const std::string& s, const std::string& prefix) {
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

int writein(std::string &fname)
{
    std::ofstream create(fname.c_str());
    if (!create){
        std::cerr << "could not create player_data.json\n";
        return(1);
    }
    create << "{\n";
    create << "  \"name\": \"\",\n";
    create << "  \"scene\": \"intro 0\",\n";
    create << "  \"reputation\": 0,\n";
    create << "  \"affection\": 0,\n";
    create << "  \"friendliness\": 0\n";
    create << "}";
    create.close();
    std::cout << "file created\n";
    return (1);
}

bool    if_closed(std::string &fname){

    std::ifstream f(fname.c_str());
    if (!f.is_open())
    {
        return(writein(fname));
    }
    return (0);
}

void set_name(pc &player, const std::string &fname) {
    std::string input;
    std::cout << "No name given." << std::endl;
    std::cout << "Enter your name: " << std::flush;
    
    // Get the name from the user
    std::cin >> input; 
    player.set_name(input);

    // Now just call the save function to overwrite the file with the new data
    save_player(fname, player);
    
    std::cout << "Player data updated!" << std::endl;
}

void checkplayer(pc &p)
{
    std::cout << p.get_name() << std::endl;
    std::cout << p.get_rep() << std::endl;
    std::cout << p.get_aff() << std::endl;
    std::cout << p.get_friend() << std::endl;
    std::cout << "scene number = " << p.scene << std::endl;
}



int main() {
    pc player;
    std::string fname = "./datas/player_data.json";
    
    // 1. If the file doesn't exist at all, create an empty JSON structure
    if_closed(fname); 

    // 2. LOAD the existing data from the file into our 'player' object
    load_player(fname, player);

    // 3. ONLY ask for a name if the player object's name is still empty
    if (player.get_name() == "" || player.get_name() == "None") {
        set_name(player, fname);
    } else {
        std::cout << "Welcome back, " << player.get_name() << "!" << std::endl;
        player.scene = check_scene(&player);
        if (player.scene == 0)
            player.scene = 0;

    }

    // 4. Update the screen
    checkplayer(player);

    return 0;
}