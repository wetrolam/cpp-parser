#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <clang-c/Index.h>
#include "Location.h"
#include <ostream>
#include "DiagnosticSeverity.h"

struct Diagnostic {
    Location location;
    std::string description;
    CXDiagnosticSeverity severity;
};

inline std::ostream & operator<<(std::ostream & output, const Diagnostic & diagnostic) {
    output << "location: {" <<  diagnostic.location << "}";
    output << ", severity: " << diagnostic.severity;
    output << ", description: '" << diagnostic.description << "'";
    return output;
}

#endif /* DIAGNOSTIC_H */

