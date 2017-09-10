#include "Parser.h"
#include "DiagnosticParser.h"
#include "TokenParser.h"
#include "AstParser.h"

Parser::Parser(const std::string & filePath) throw(ParserException)
{
    const char * const cmdArgv[] = {filePath.c_str(), "-I/usr/lib/llvm-3.8/lib/clang/3.8.0/include", nullptr}; // TODO: include path configuration
    const int cmdArgc = sizeof(cmdArgv)/sizeof(cmdArgv[0]) - 1;

    CXIndex index = clang_createIndex(0, 0);
    if(index == nullptr){
        throw ParserException("error creating index");
    }

    CXTranslationUnit translationUnit = clang_parseTranslationUnit(index, 0, cmdArgv, cmdArgc, 0, 0, CXTranslationUnit_DetailedPreprocessingRecord);
    if(translationUnit == nullptr){
        throw ParserException("error creating translationUnit");
    }

    diagnostics = getAllDiagnostics(translationUnit);

    CXCursor rootCursor = clang_getTranslationUnitCursor(translationUnit);

    tokens = getAllTokens(translationUnit,rootCursor);

    astNodes = getAllAstNodes(rootCursor);

    clang_disposeTranslationUnit(translationUnit);
    clang_disposeIndex(index);
}

const std::list<Diagnostic> & Parser::getDiagnostics() const
{
    return diagnostics;
}

const std::list<Token> & Parser::getTokens() const
{
    return tokens;
}

const std::list<AstNode> & Parser::getAstNodes() const
{
    return astNodes;
}

