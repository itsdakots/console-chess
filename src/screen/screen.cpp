#include "screen.hpp"
#include <iostream>

#if defined(_WIN32)
#include <conio.h>
#endif

#if defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
#include <unistd.h>
#include <termios.h>
#endif

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

    // Todo: Everything after here needs to be put inside of an Input class.
    void throwUnsupported() {
        throw new std::runtime_error("Unsupported operating system.");
    }

    #if defined(_WIN32)
        char getInput() {
            char c = _getch();
            return c;
        }
    #elif defined(__unix__) || defined(__unix) || defined(__APPLE__) || defined(__MACH__)
        termios oldt;
        char getInput()
        {
            termios newt;
            tcgetattr(STDIN_FILENO, &oldt); // save old settings
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO); // disable buffering & echo
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            char c = getchar();
            return c;
        }

        // Todo: Because this always needs to happen, we need to put this in a class destructor.
        char breakDown() {
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        }
    #else
        char getInput() {
            throwUnsupported();
        }
    #endif
    
}