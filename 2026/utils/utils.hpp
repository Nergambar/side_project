#ifndef UTILS
#define UTILS

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#include "rangedInt.hpp"
class pc;

void scenes(pc *player);
void load_player(const std::string& fname, pc& player);
void save_player(const std::string& fname, pc& player);
std::string find_line(std::string filename, std::string target);
bool    starts_with(const std::string& s, const std::string& prefix);
bool    if_closed(std::string &fname);
void    set_name(pc &player, std::string &fname, std::string line);
void    checkplayer(pc &p);
bool    replace_line_in_file(const std::string& filename,
                          const std::string& target,
                          const std::string& replacement);
int check_scene(pc *player);

int extract_int(const std::string& line);
int extract_scene_number(const std::string& scene_value);
void save_player(const std::string& fname, pc& player);
void set_scene(pc &player,std::string line);

#endif