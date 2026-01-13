#include "../generic/Npc.hpp"
#include "../generic/Amy.hpp"

void where(gen &Amy, Npc &OS, User &u)
{
    Amy.talking("Oh, you don't know?", 1.7);
    Amy.talking("I would've guessed you're new here, have you met anyone else by chance?", 2);
    std::string input;
    getline(std::cin, input);
    OS.talking("TIP: choices preceeded by '==' are not available to you.", 0.1);
    if (u.noRel())
        std::cout << "==";
    std::cout << "1. yes\n2. no" << std::endl;
    while(!input.empty())
    {
        if (input == "1" && u.noRel())
            OS.talking("input non valid, try again:", 0.001);
    }
}