#include "TokenParser.h"

std::list<Token> getAllTokens(CXTranslationUnit translationUnit,CXCursor currentCursor)
{
    CXToken *tokens;
    unsigned int numTokens;
    CXSourceRange srcRange;
    
    srcRange = clang_getCursorExtent(currentCursor);
    
    clang_tokenize(translationUnit, srcRange, &tokens, &numTokens); //Tokenize the source code described by the given range into raw lexical tokens
    
    std::list<Token> result;
    
    for (int i = 0; i < numTokens; ++i) {
        CXSourceLocation location = clang_getTokenLocation(translationUnit, tokens[i]);
    
        CXString clText = clang_getTokenSpelling(translationUnit, tokens[i]);
        std::string text = clang_getCString(clText);
        clang_disposeString(clText);
    
        CXTokenKind kind = clang_getTokenKind(tokens[i]);

        result.push_back(Token(location, kind, text));
    }
    
    clang_disposeTokens(translationUnit,tokens,numTokens);

    return result;
}
