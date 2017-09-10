#include "DiagnosticParser.h"

std::list<Diagnostic> getAllDiagnostics(CXTranslationUnit translationUnit) 
{
    std::list<Diagnostic> result;

    int nbDiag = clang_getNumDiagnostics(translationUnit);
    for (unsigned int currentDiag = 0; currentDiag < nbDiag; ++currentDiag) {
        
        CXDiagnostic diagnostic = clang_getDiagnostic(translationUnit, currentDiag); 

        //location
        CXSourceLocation location = clang_getDiagnosticLocation(diagnostic);

        //diagnostics text description
        CXString clDescription = clang_getDiagnosticSpelling(diagnostic);
        std::string description = clang_getCString(clDescription);
        clang_disposeString(clDescription);

        //diagnostic error/warning/..... message
        //CXString message = clang_formatDiagnostic(diagnostic,clang_defaultDiagnosticDisplayOptions());
        //std::cout << "err: '" << clang_getCString(message) << std::endl;
        //clang_disposeString(message);
        
        //severity
        CXDiagnosticSeverity severity = clang_getDiagnosticSeverity(diagnostic);

        //category
        //CXString category = clang_getDiagnosticCategoryText(diagnostic);
        //std::cout << "category: '" << clang_getCString(category) << "'" << std::endl;
        //clang_disposeString(category);

        clang_disposeDiagnostic(diagnostic);

        result.push_back(Diagnostic{location, description, severity});
    }

    return result;
}
