#ifndef AST_PARSER_H
#define AST_PARSER_H

#include "AstNode.h"
#include <list>

std::list<AstNode> getAllAstNodes(CXCursor rootCursor);

#endif /* AST_PARSER_H */

