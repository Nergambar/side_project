#include "../generic/Amy.hpp"


void    who(Amy &amy, Npc &OS, User &u)
{
    amy.talking("Oh, right! where are my manners!", 1.7);
    amy.talking("I'm amy! Nice to meet you!", 1);
    u.upRel(amy, 1);
    amy.talking("do you know anyone else by any chance?", 1.4);
    std::string input;
    getline(std::cin, input);
    OS.talking("TIP: choices preceeded by '==' are not available to you.", 0.1);
    while (!input.empty())
    {
        if (u.noRel())
            std::cout << "==";
        std::cout << "1. yes\n2. no" << std::endl;
        if (input == "1" && u.noRel())
            OS.talking("input non valid, try again:", 0.001);
    }
}