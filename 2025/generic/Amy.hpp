#ifndef AMY
#define AMY



#include "Npc.hpp"

/*
bool            is_in_Room;
std::map<std::string, int> relWithNpc;
short int       healthPoints;
std::map<std::string, unsigned char> obj;
void            setName(std::string name) {this->name = name;}
void            isPresent(bool b);
void            upRel(std::string name,int delta);
int             getRel(std::string name)
std::string     getName();
void            talking(std::string what, double i) */
class Amy : public Npc
{
    public:
    Amy() : Npc() {name = "Amy"; obj["half_necklace"] = 10; is_in_Room = true;}
    std::string    getInRoom();
};
typedef Amy gen;

#endif