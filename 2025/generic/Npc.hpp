#ifndef NPC

#define NPC


#include <string>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>

#include <stdio.h>    // For fflush
#include <unistd.h>   // For usleep (Unix/Linux/macOS)

class Amy;

void type(const std::string& message, float delay, bool newLine);

class Npc {
    protected:
        std::string     name;
        bool            is_in_Room;
        unsigned char   rel;
        std::map<std::string, int> relWithNpc;
        short int       healthPoints;
        std::map<std::string, unsigned char> obj;
    public:
        virtual ~Npc();
        void            setName(std::string name) {this->name = name;}
        Npc() : name(""), is_in_Room(false), healthPoints(100)
        {};
        void            isPresent(bool b) {is_in_Room = b;}
        void            upRel(Npc &n,int delta);
        int             getRel(Npc &n)
        {
            std::string name = n.getName();
            return (relWithNpc[name]);
        };
        std::string    getName()
        {
            return name;
        };
        void            talking(std::string what, double i)
        {
            if (!getName().empty())
                std::cout << this->getName() << ": ";
            usleep(50000);
            type(what, i, true);
        };
};


class User : public Npc {
    private:
        std::string name;
    public:
        std::string getName() {return(name);};
        void        setName(std::string name) {this->name = name;}
        std::map<std::string, int> relWithNpc;
        bool        noRel() {if (this->relWithNpc.size() == 1) return true; return false;}
};
typedef Amy gen;


void    where(gen &Amy, Npc &OS, User &u);
void    who(Amy &amy, Npc &OS, User &u);

#endif