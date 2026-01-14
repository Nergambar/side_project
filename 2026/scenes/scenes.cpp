#include "../player.hpp"
#include "../utils/utils.hpp"

void scenes(pc *player){
    if (player->scene == 0)
        std::cout << "introductory scene" << std::endl;
    else 
        std::cout << "scene not written yet" << std::endl;
}