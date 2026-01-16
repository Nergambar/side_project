#include "base.hpp"



std::string type(const std::string& message, float totalTime = 1.5f, 
    bool newLine = true, std::ostream &o = std::cout)
{
    size_t length = message.length();
    float delayPerChar = totalTime / length;  // Short = bigger delay, long = smaller delay
    
    for (size_t i = 0; i < length; ++i) {
        o << message[i];
        o.flush();
        usleep(static_cast<useconds_t>(delayPerChar * 1000000));
    }
    if (newLine)
        o << "\n";
    std::string s;
    o << s;
    return (s);
}
/*
 newline is on by default
 */
std::ostream &pc::says(std::string s, float tT, std::ostream &o)
{
    o << this->get_name() + ": ";
    o << type(s, tT);
    return o;
    // return (type(this->get_name() + s, ));
}

int main()
{
    pc test;
    test.set_name("??");

    test.get_stats();
    while (-1);
}
