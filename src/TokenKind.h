#ifndef TOKENKIND_H
#define TOKENKIND_H

#include <clang-c/Index.h>
#include <string>

inline std::string str(CXTokenKind kind) {
    switch(kind) {
        case CXToken_Punctuation:
            return "punctuation";
        case CXToken_Keyword:
            return "keyword";
        case CXToken_Identifier:
            return "identifier";
        case CXToken_Literal:
            return "literal";
        case CXToken_Comment:
            return "comment";
        default:
            return "unknown";
    }
}

#endif /* TOKENKIND_H */
