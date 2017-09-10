#include <cstdlib>
#include <iostream>
#include "Parser.h"

void testParser(std::string filePath)
{
    Parser parser(filePath);

    std::cout << "--------- DIAGNOSTIC -----------------------------------------" << std::endl;
    const std::list<Diagnostic> & diagnostics = parser.getDiagnostics();
    for(const Diagnostic & d : diagnostics) {
        std::cout << d << std::endl;
    }

    std::cout << "--------- TOKENS ---------------------------------------------" << std::endl;
    const std::list<Token> & tokens = parser.getTokens();
    for(const Token & t : tokens) {
        std::cout << t << std::endl;
    }

    std::cout << "--------- AST NODES ------------------------------------------" << std::endl;
    const std::list<AstNode> & astNodes = parser.getAstNodes();
    for(const AstNode & node : astNodes) {
        if( path(node.location.file) == filePath ) {
            std::cout << node << std::endl;
        }
    }
}

int main(int argc, char** argv)
{
    testParser("source2.cpp");

    return EXIT_SUCCESS;
}

