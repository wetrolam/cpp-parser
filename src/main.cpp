#include <cstdlib>
#include <iostream>
#include "TokenParser.h"
#include "DiagnosticParser.h"
#include "AstParser.h"

void testTokenParser(int argc, char** argv)
{
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

void testDiagnosticParser()
{
    int argc = 2;
    const char * const argv[] = {"source2.cpp", "-I/usr/lib/llvm-3.8/lib/clang/3.8.0/include", nullptr};

    CXIndex index = clang_createIndex(0, 0);
    if(index == nullptr){
        fprintf(stderr, "error creating index\n");
        exit(EXIT_FAILURE);
    }

    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, 0, argv, argc, 0, 0, CXTranslationUnit_DetailedPreprocessingRecord);
    if(translationUnit == nullptr){
        fprintf(stderr, "error creating translationUnit\n");
        exit(EXIT_FAILURE);
    }

    std::list<Diagnostic> diagnostics = getAllDiagnostics(translationUnit);
    std::cout << "--------- DIAGNOSTIC -----------------------------------------------------" << std::endl;
    for(Diagnostic & d : diagnostics) {
        std::cout << d << std::endl;
    }

    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
}

void testAstParser()
{
    int argc = 2;
    const char * const argv[] = {"source2.cpp", "-I/usr/lib/llvm-3.8/lib/clang/3.8.0/include", nullptr};

    CXIndex index = clang_createIndex(0, 0);
    if(index == nullptr){
        fprintf(stderr, "error creating index\n");
        exit(EXIT_FAILURE);
    }

    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, 0, argv, argc, 0, 0, CXTranslationUnit_DetailedPreprocessingRecord);
    if(translationUnit == nullptr){
        fprintf(stderr, "error creating translationUnit\n");
        exit(EXIT_FAILURE);
    }

    CXCursor rootCursor = clang_getTranslationUnitCursor(translationUnit);

    std::list<AstNode> astNodes = getAllAstNodes(rootCursor);
    std::cout << "--------- AST NODES -----------------------------------------------------" << std::endl;
    for(AstNode & node : astNodes) {
        if( path(node.location.file) == "source2.cpp") {
            std::cout << node << std::endl;
        }
    }

    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
}

int main(int argc, char** argv)
{
    //testTokenParser(argc, argv);
    //testDiagnosticParser();
    testAstParser();

    return EXIT_SUCCESS;
}
