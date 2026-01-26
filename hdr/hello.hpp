#ifndef __HELLO_HPP__
#define __HELLO_HPP__

#include <string>

class Hello {
protected:
    int numCalls;
    std::string myName;
    
public:
    Hello( std::string name ) {};
    void sayMyName();
};

#endif

