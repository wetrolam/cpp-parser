#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "Diagnostic.h"
#include "AstNode.h"
#include <list>
#include <string>
#include <exception>

class ParserException : public std::exception {
private:
    const char * description;
public:
    ParserException(const char * description)
    : exception()
    , description(description) {
    }

    virtual const char* what() const throw() {
        return description;
    }
};

class Parser {
private:
    std::list<Diagnostic> diagnostics;
    std::list<Token> tokens;
    std::list<AstNode> astNodes;

public:
    Parser(const std::string & filePath) throw(ParserException);

    const std::list<Diagnostic> & getDiagnostics() const;
    const std::list<Token> & getTokens() const;
    const std::list<AstNode> & getAstNodes() const;
};

#endif /* PARSER_H */

