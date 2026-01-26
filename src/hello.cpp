#include "hello.hpp"

#include <iostream>



Hello::Hello( std::string_view name ) {
    myName = name;
    numCalls=0;
}

void Hello::sayMyName() {
    numCalls++;
    std::cout << "My name is " << myName << std::endl;
    std::cout << "I've told you " << numCalls << " times, bitch." << std::endl;
}


