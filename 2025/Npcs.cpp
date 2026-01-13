#include "generic/Npc.hpp"
#include "generic/Amy.hpp"

void type(const std::string& message, float delay, bool newLine) {
    for (size_t i = 0; i < message.length(); ++i) {
        std::cout << message[i];
        std::cout.flush(); 
        
        // Delay the execution
        usleep(delay * 50000);
    }
    if (newLine)
        std::cout << "\n"; // Print a newline at the end
}

std::string    Amy::getInRoom()
{
    if (this->is_in_Room)
        return("present!");
    return ("absent!");
}


void            Npc::upRel(Npc &n, int delta)
{
    const int MIN = 0;
    const int MAX = 255;
    std::string name = n.getName();

    // get current relation (creates entry if absent)
    int current = 0;
    std::map<std::string,int>::iterator it = relWithNpc.find(n.getName());
    if (it == relWithNpc.end())
    {
        current = 50;
        relWithNpc[name] = current;
    }
    else
        current = it->second;

    long newVal = (long)current + (long)delta;

    if (newVal < MIN) {
        std::cout << "relation would underflow; clamping to " << MIN << std::endl;
        newVal = MIN;
    } else if (newVal > MAX) {
        std::cout << "relation would overflow; clamping to " << MAX << std::endl;
        newVal = MAX;
    }
    if (dynamic_cast<User*>(this) == NULL) {
        // This block executes ONLY if the caller is an Npc or another derived class, BUT NOT User.
        if (delta > 0)
            std::cout << getName() << " will remember that\n";
        else
            std::cout << "this action will have consequences" << std::endl;
    }    
    relWithNpc[name] = (int)newVal;
    std::ostringstream oss;
    oss << "relationship changed by " << delta << "\nIt is now " << relWithNpc[name];
    type(oss.str(), 1, true);
}