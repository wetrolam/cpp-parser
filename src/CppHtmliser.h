#ifndef CPP_HTMLISER_H
#define CPP_HTMLISER_H

#include "Parser.h"
#include <fstream>

inline std::string encode(char letter)
{
    switch(letter) {
        case '<':
            return "&lt;";
        case '>':
            return "&gt;";
        default:
            return std::string({letter});
    }
}

// TODO: move to another file
inline std::string getHtmlBeginning(std::string title)
{
    return
        "<html>\n"
        "    <title> " + title + " </title>\n"
        "    <body>\n"
        ;
}

// TODO: move to another file
inline std::string getHtmlEnding()
{
    return
        "    <body>\n"
        "</thml>"
        ;
}

inline std::string cppToHtml(std::string cppFilePath)
{
    std::string htmlFilePath = cppFilePath + ".html";
    std::ifstream cpp(cppFilePath);
    std::ofstream html(htmlFilePath);

    html << getHtmlBeginning(cppFilePath);
    html << std::endl << "<pre><code>";
    char letter;
    while(cpp.get(letter)) {
        html << encode(letter);
    }
    html << "</code><pre>" << std::endl;
    html << getHtmlEnding();

    return htmlFilePath;
}

#endif /* CPP_HTMLISER_H */

