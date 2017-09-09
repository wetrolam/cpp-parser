#include <cstdlib>
#include <iostream>
#include "TokenParser.h"

void testTokenParser(int argc, char** argv) {
    CXIndex index = clang_createIndex(0, 0);
    
    if(index == 0){
        std::cerr << "error creating index" << std::endl;
        exit(EXIT_FAILURE);
    }

//    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, 0, argv, argc, 0, 0, CXTranslationUnit_None);
    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, 0, argv, argc, 0, 0, CXTranslationUnit_DetailedPreprocessingRecord);
            
    if(translationUnit == 0){
        std::cerr << "error creating translationUnit" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    CXCursor rootCursor = clang_getTranslationUnitCursor(translationUnit);

    std::list<Token> tokens = getAllTokens(translationUnit,rootCursor);
    for(Token & t : tokens) {
        std::cout << t << std::endl;
    }
    
    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
}

int main(int argc, char** argv) {

    testTokenParser(argc, argv);
    
    return EXIT_SUCCESS;
}
