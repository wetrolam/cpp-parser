#ifndef TOKEN_H
#define TOKEN_H

#include <clang-c/Index.h>
#include "TokenKind.h"
#include "Location.h"
#include <string>
#include <iostream>
#include <iomanip>

struct Token{
    Location location;
    size_t length;
    CXTokenKind kind;
    std::string text;
    
//    Token(Location location = Location(), CXTokenKind kind = CXToken_Punctuation, std::string text = "")
    Token(Location location, CXTokenKind kind, std::string text)
        : location(location)
        , length(text.length())
        , kind(kind)
        , text(text)
    {
    }
    
};

inline std::ostream & operator<<(std::ostream & output, const Token & token) {
    output << "location: {" << token.location << "}";
    output << ", length: " << std::setw(2) << token.length;
    output << " " << std::setw(11) << std::left << str(token.kind);
    output << " '" << token.text <<"'";
    return output;
}

#endif /* TOKEN_H */
