#include "generic/Amy.hpp"


void where(gen &Amy, Npc &OS, User &u);


void start(gen &amy, Npc &OS, User &u, std::string input)
{
    while (1)
    {
        OS.talking("you wake up", 2);
        sleep(1);
        OS.talking("You look around and notice that you are somewhere you don't recognise, ", 2);
        sleep(1);
        OS.talking("with nobody you know, ", 1.5);
        sleep(1);
        OS.talking("which is the worst kind of alone.", 1.5);
        sleep(1);
        OS.talking("You look around, and notice someone in the distance", 1.4);
        sleep(1);
        OS.talking("\nYou approach her", 1.4);
        sleep(1);
        u.upRel(amy, 50);
        OS.talking("Amy added to found people            ", 0.2);
        amy.talking("oh, hey! Didn't see you there! How can I help you?", 2);
        std::cout << "1. Where am I?\n2. Who are you?\n3. Who am I?" << std::endl;
        getline(std::cin, input);
        while(!input.empty())
        {
            if (input == "1")
                where(amy, OS, u);
            else if (input == "2")
                who(amy, OS, u);
            OS.talking("input non valid, try again:", 0.001);
        }
    }
}



int main()
{
    Npc OS;
    User u;
    OS.setName("");
    gen amy;
    gen mark;
    std::string input;
    start(amy, OS, u, input);

}