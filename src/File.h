#ifndef FILE_H
#define FILE_H

#include <clang-c/Index.h>
#include <string>

inline std::string path(const CXFile file) {
    std::string result;

    if(file != nullptr) {
        CXString clPath = clang_getFileName(file);
        const char * path = clang_getCString(clPath);
        if(path != nullptr) {
            result = path;
        }
        clang_disposeString(clPath);
    }
    return result;
}

inline std::ostream & operator<<(std::ostream & output, const CXFile file) {
    output << path(file);
    return output;
}

#endif /* FILE_H */
