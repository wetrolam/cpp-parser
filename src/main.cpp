#include <cstdlib>
#include <iostream>

#include <clang-c/Index.h>
#include <clang-c/Platform.h>


int main(int argc, char** argv) {
    
    std::cout << "testing clang settings" << std::endl;

    CXIndex index = clang_createIndex(0, 0);
    
    return 0;
}

