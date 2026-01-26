#pragma once

#include <string>

class Hello {
protected:
    int numCalls;
    std::string myName;
    
public:
    Hello( std::string_view name );
    void sayMyName();
};


