#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>


#include "player.hpp"
class pc;

bool starts_with(const std::string& s, const std::string& prefix) {
    return s.size() >= prefix.size() &&
           s.compare(0, prefix.size(), prefix) == 0;
}

std::string find_line(std::string filename, std::string target)
{
    std::ifstream infile(filename.c_str());
    if (!infile) return NULL;

    std::vector<std::string> lines;
    std::string line;

    // Read all lines
    while (std::getline(infile, line)) {
        if (line == target || starts_with(line, target))
            return (line);        
    }
    infile.close();
    return NULL;
}

bool replace_line_in_file(const std::string& filename,
                          const std::string& target,
                          const std::string& replacement)
{
    std::ifstream infile(filename.c_str());
    if (!infile) return false;

    std::vector<std::string> lines;
    std::string line;

    // Read all lines
    while (std::getline(infile, line)) {
        if (line == target)
            lines.push_back(replacement); // replace
        else
            lines.push_back(line);        // keep
    }
    infile.close();

    // Rewrite file
    std::ofstream outfile(filename.c_str(), std::ios::trunc);
    if (!outfile) return false;

    for (std::vector<std::string>::iterator l = lines.begin(); l < lines.end(); l++)
        outfile << *l << '\n';

    return true;
}

bool    if_closed(std::string &fname){

    std::ifstream f(fname.c_str());
    if (!f.is_open())
    {
        std::ofstream create(fname.c_str());
        if (!create){
            std::cerr << "could not create player_data.txt\n";
            return(1);
        }
        create << "scene: intro\n";
        create << "Name:\n";
        create.close();
        std::cout << "file created\n";
        return(1);
    }
    return (0);
}

void set_name(pc &player, std::string &fname, std::string line)
{
    if (line == "Name:") {
        std::cout << "No name given.\r\nEnter your name: " << std::flush;
        std::string input;
        std::ifstream tty("/dev/tty"); // read directly from terminal
        tty >> input;
        player.set_name(input);
        replace_line_in_file(fname, "Name:", "Name: " + input);
    }
}

void checkplayer(pc &p)
{
    std::cout << p.get_name() << std::endl;
    std::cout << p.get_rep() << std::endl;
    std::cout << p.get_aff() << std::endl;
    std::cout << p.get_friend() << std::endl;
    std::cout << "scene number = " << p.scene << std::endl;
}


int main()
{
    pc player   ;
    std::string input;
    std::cin >> input;
    std::string fname = "./datas/player_data.txt";   
    std::ifstream f(fname.c_str());

    if (input == "reset"){
        if (std::remove(fname.c_str()))
            return(std::cerr << "error deleting file", -611);
        std::cout << "file deleted";}
    if (!if_closed(fname))
        f.close();
    player.scene = check_scene(&player);
    std::ifstream fread(fname.c_str());
    std::string line;
    std::getline(fread, line);
    std::getline(fread, line);
    fread.close();

    set_name(player, fname, line);

    std::ifstream display(fname.c_str());
    while (std::getline(display, line))
    {
        if (starts_with(line, "scene: ")){
            scenes(&player);
            continue;
        }
        std::cout << line << std::endl;
    }
    checkplayer(player);
}