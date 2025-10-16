#include "screen.hpp"
#include <iostream>

namespace screen {
    void clearConsole(int x, int y) {
        std::cout << "\033[" << x << ";" << y << "H" << "\033[J";
    }

    void print(std::string s, bool newLine) {
        std::cout << s;
        if (newLine)
            std::cout << '\n';
    }

    void write(std::string s, TextSettings settings) {
        auto result = formatText(s, settings);

        print(result);
    }

    std::string formatText(std::string s, TextSettings settings) {
        std::string result = "\033[";
        if (settings.bold) {
            result += "1;";
        }

        if (settings.italics) {
            result += "3;";
        }

        if (settings.underline) {
            result += "4;";
        }

        if (settings.blink) {
            result += "5;";
        }

        if (settings.foreColor != 0) {
            result += std::to_string(settings.foreColor) + ";";
        }

        if (settings.backColor != 0) {
            result += std::to_string(settings.backColor) + ";";
        }

        if (result.length() > 2) {
            result.pop_back();
            result += "m";
        }

        result += s + "\033[0m";

        return result;
    }
}