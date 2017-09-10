#ifndef DIAGNOSTIC_PARSER_H
#define DIAGNOSTIC_PARSER_H

#include "Diagnostic.h"
#include <list>

std::list<Diagnostic> getAllDiagnostics(CXTranslationUnit translationUnit);

#endif /* DIAGNOSTIC_PARSER_H */

