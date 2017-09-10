#ifndef FILE_H
#define FILE_H

#include <sstream>
#include <iomanip>

inline std::ostream & operator<<(std::ostream & output, const CXFile file) {
    if(file != nullptr) {
        CXString fileName = clang_getFileName(file);
        output << clang_getCString(fileName);
        clang_disposeString(fileName);
    }
    return output;
}

inline std::string path(const CXFile file) {
    if(file == nullptr) {
        return "";
    }
    else {
        CXString clPath = clang_getFileName(file);
        std::string path = clang_getCString(clPath);
        clang_disposeString(clPath);
        return path;
    }
}

#endif /* FILE_H */
