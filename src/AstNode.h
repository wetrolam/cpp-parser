#ifndef AST_NODE_H
#define AST_NODE_H

#include <clang-c/Index.h>
#include "Location.h"
#include <string>
#include <iostream>
#include <iomanip>

struct AstNode {
    Location location;
    CXCursorKind kind;
    std::string text;
};

inline std::ostream & operator<<(std::ostream & output, const AstNode & astNode) {
    output << "location: {" << astNode.location << "}";
    output << ", kind: " << std::setw(3) << astNode.kind;
    output << ", text: '" << astNode.text << "'";
    return output;
}

#endif /* AST_NODE_H */

