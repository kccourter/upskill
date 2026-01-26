#include "hello.hpp"
#include <iostream>


int main( void ) {

    std::cout << "entering main" << std::endl;

    Hello howdy( "Heisenberg" );

    howdy.sayMyName();

    return 0;
}