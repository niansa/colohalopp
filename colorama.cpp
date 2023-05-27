#include "colorama/initialise.hpp"

#ifdef _WIN32
#include <windows.h>
#endif


namespace colorama {
// Code ported from initialise.py
#ifdef _WIN32
void just_fix_windows_console(bool revert) {
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(handleOut, &consoleMode);
    static initial_consoleMode = consoleMode;
    if (!revert)
        consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    else
        consoleMode &= ~ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(handleOut, consoleMode);
}
#endif
}
