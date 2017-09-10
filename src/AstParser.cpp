#include "AstParser.h"

CXChildVisitResult cursorVisitor(CXCursor cursor, CXCursor parent, CXClientData clientData)
{
    CXSourceLocation location = clang_getCursorLocation(cursor);

    CXCursorKind kind = clang_getCursorKind(cursor);

    CXString clName = clang_getCursorSpelling(cursor);
    std::string name = clang_getCString(clName);
    clang_disposeString(clName);

    std::list<AstNode> * elements = (std::list<AstNode> *) clientData;
    elements->push_back(AstNode{location, kind, name});

    return CXChildVisit_Recurse;
}

std::list<AstNode> getAllAstNodes(CXCursor rootCursor)
{
    std::list<AstNode> astNodes;
    unsigned int res = clang_visitChildren(rootCursor, cursorVisitor, (CXClientData) & astNodes);
    return astNodes;
}
