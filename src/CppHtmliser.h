#ifndef CPP_HTMLISER_H
#define CPP_HTMLISER_H

#include "Parser.h"
#include <fstream>
#include <map>

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

// TODO temporary function
inline std::string getStyle()
{
    return
        "        <style>\n"
        "            .keyword {\n"
        "                font-weight: bold;\n"
        "            }\n"
        "            .comment {\n"
        "                color: green;\n"
        "                /*color: gray;*/\n"
	"                font-style: italic;\n"
        "            }\n"
        "            .preprocessor {\n"
        "                /*color: blue;*/\n"
        "                color: #800000;\n"
        "                font-weight: bold;\n"
        "            }\n"
        "            .literal {\n"
        "                /*color: #800000;*/\n"
        "                color: blue;\n"
        "            }\n"
        "        </style>\n";
}

// TODO: move to another file
inline std::string getHtmlBeginning(std::string title)
{
    return
        "<html>\n"
        "    <head>\n"
        "        <title> " + title + " </title>\n"
        "" + getStyle() + ""
        "    </head>\n"
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

// TODO temporary function
inline std::string toHtmlClass(CXTokenKind kind) {
     switch(kind) {
        case CXToken_Punctuation:
            return "punctuation";
        case CXToken_Keyword:
            return "keyword";
        case CXToken_Identifier:
            return "identifier";
        case CXToken_Literal:
            return "literal";
        case CXToken_Comment:
            return "comment";
        default:
            return "unknown";
    }
}

inline std::string cppToHtml(std::string cppFilePath)
{
    // parse source file

    Parser parser(cppFilePath);

    std::map<unsigned, CXTokenKind> beginning;
    std::map<unsigned, CXTokenKind> ending;

    for(const Token & t : parser.getTokens()) {
        beginning[t.location.offset] = t.kind;
        ending[t.location.offset + t.length] = t.kind;
    }

    // write html file

    std::string htmlFilePath = cppFilePath + ".html";
    std::ifstream cpp(cppFilePath);
    std::ofstream html(htmlFilePath);

    html << getHtmlBeginning(cppFilePath);
    html << std::endl << "<pre><code>";

    unsigned offset = 0;
    char letter;
    while(cpp.get(letter)) {
        std::map<unsigned, CXTokenKind>::iterator it;
        it = ending.find(offset);
        if(it != ending.end() && (it->second == CXToken_Comment || it->second == CXToken_Keyword || it->second == CXToken_Literal) ) { // TODO change the condition (this is working version)
            html << "</span>";
        }

        it = beginning.find(offset);
        if(it != beginning.end() && (it->second == CXToken_Comment || it->second == CXToken_Keyword || it->second == CXToken_Literal) ) { // TODO change the condition (this is working version)
            html << "<span class=\"" << toHtmlClass(it->second) << "\">";
        }

        html << encode(letter);

        offset ++;
    }

    html << "</code><pre>" << std::endl;
    html << getHtmlEnding();

    return htmlFilePath;
}

#endif /* CPP_HTMLISER_H */

