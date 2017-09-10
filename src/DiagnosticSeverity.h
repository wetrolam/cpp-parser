#ifndef DIAGNOSTIC_SEVERITY_H
#define DIAGNOSTIC_SEVERITY_H

#include <clang-c/Index.h>
#include <ostream>

inline std::ostream & operator<< (std::ostream & output, CXDiagnosticSeverity diagnosticSeverity) {
    switch(diagnosticSeverity) {
        case CXDiagnostic_Ignored:
            output << "ignored";
            break;
        case CXDiagnostic_Note:
            output << "note";
            break;
        case CXDiagnostic_Warning:
            output << "warning";
            break;
        case CXDiagnostic_Error:
            output << "error";
            break;
        case CXDiagnostic_Fatal:
            output << "fatal";
            break;
        default:
            output << "unknown";
    }
    return output;
}

#endif /* DIAGNOSTIC_SEVERITY_H */

