#ifndef PLAYER
#define PLAYER

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "utils/utils.hpp"

class rangedInt;

class pc{
    private:
        std::string name;
        rangedInt reputation;
        rangedInt affection;
        rangedInt friendliness; //could be affected greatly by reputation changed but not the opposite?
    public:
        int scene;
        pc() : reputation(0, 0, 20), affection(0, 0, 20), friendliness(0,0,20) {}
        void set_name(std::string name)
        {
            this->name = name;
        }
        rangedInt get_rep() {return (reputation);}
        rangedInt get_aff() {return (affection);}
        rangedInt get_friend() {return (friendliness);}
        std::string get_name() {return (name);}
        void set_rep(rangedInt rep) {reputation = rep;}
        void set_aff(rangedInt aff) {affection = aff;}
        void set_friend(rangedInt f) { friendliness = f;}
};


#endif