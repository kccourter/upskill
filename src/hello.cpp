#include "hello.hpp"

#include <iostream>



Hello::Hello( std::string name ) {
    myName = name;
    numCalls=0;
}

void Hello::sayMyName() {
    std::cout << "My name is " << myName << std::endl;
    numCalls++;
}


