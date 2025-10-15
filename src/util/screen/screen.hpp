#ifndef SCREEN
#define SCREEN
#include <string>

namespace screen {

    struct stext_settings {
        short foreColor;
        short backColor;
        bool italics;
        bool underline;
        bool bold;
    } typedef TextSettings;

    void clearConsole(int x, int y);

    void print(std::string s, bool newLine = false);

    void write(std::string s, TextSettings settings = {});

    std::string formatText(std::string s, TextSettings settings = {});
}

#endif