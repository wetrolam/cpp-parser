#ifndef LOCATION_H
#define LOCATION_H

#include <clang-c/Index.h>
#include "File.h"

struct Location {
    CXFile file;
    unsigned line;
    unsigned column;
    unsigned offset;
    
    Location(CXSourceLocation cxlocation) {
        clang_getExpansionLocation(cxlocation, &file, &line, &column, &offset);
    }
};

inline std::ostream & operator<<(std::ostream & output, const Location & location) {
    output << "file: "     << std::setw(10) << location.file;
    output << ", line: "   << std::setw( 4) << std::right << location.line;
    output << ", column: " << std::setw( 3) << location.column;
    output << ", offset: " << std::setw( 5) << location.offset;
    return output;
}

#endif /* LOCATION_H */
