#include <string>
#include <iostream>
#include <climits>
#include <map>
#include <sstream>

#include <stdio.h> 
#include <unistd.h>

void type(const std::string& message, double delay, bool n) {
    for (size_t i = 0; i < message.length(); ++i) {
        std::cout << message[i];
        
        // **Crucial Step: Flush the output buffer**
        // Without flushing, the character won't appear until the buffer 
        // is full or a newline is printed.
        std::cout.flush(); 
        
        // Delay the execution
        usleep(delay * 50000);
    }
    if (n)
        std::cout << "\n"; // Print a newline at the end
}

void Daisy()
{
    type("Daisy, ", 5, false);
    type("Daisy", 4.5, true);
    type("give me your answer ", 2.5, false);
    type("do", 5, false);
    type("      ", 5, true);
    type("I'm half crazy", 4.5, false);
    type(" all for the love of you", 3.3, false);
    type("      ", 1, true);
    type("It won't be a ", 2, false);
    type("stylish ", 4, false);
    type("marriage", 2.5, true);
    type("I can't afford ", 3.5, false);
    type ("a carriage", 4, true);
    type("But you'll ", 3.5, false);
    type("look sweet ", 1.5, false);
    type("upon", 5, false);
    type(" the seat", 1.5, true);
    type("of a bicycle made for ", 3, false);
    type("two", 5, true);
}

#include <ostream>
class Daisyy
{

};

std::ostream    &operator<<(std::ostream &os, const Daisyy &obj)
{
    (void)obj;
    os << "testing shit" << std::endl;
    return (os);
}


int main()
{
    // Daisyy d;
    Daisy();
    // std::cout << d;
}


/* 
Daisy, Daisy, give me your answer do
I'm half crazy all for the love of you
It won't be a stylish marriage
I can't afford a carriage
But you'll look sweet upon the seat
Of a bicycle built for two
 */