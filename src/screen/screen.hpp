#ifndef SCREEN
#define SCREEN
#include <string>

namespace screen {

    struct stext_settings {
        short foreColor = 0;
        short backColor = 0;
        bool italics = false;
        bool underline = false;
        bool bold = false;
        bool blink = false;
    } typedef TextSettings;

    void clearConsole(int x, int y);

    void print(std::string s, bool newLine = false);

    void write(std::string s, TextSettings settings = {});

    std::string formatText(std::string s, TextSettings settings = {});
}

#endif