#ifndef TOKEN_PARSER_H
#define TOKEN_PARSER_H

#include <clang-c/Index.h>
#include "Token.h"
#include <list>

std::list<Token> getAllTokens(CXTranslationUnit translationUnit,CXCursor currentCursor);

#endif /* TOKEN_PARSER_H */
