/*
 * This library generates ANSI character codes to printing colors to terminals.
 * See: http://en.wikipedia.org/wiki/ANSI_escape_code
 */
#pragma once

#include <string>
#include <string_view>
#include <array>
#include <fmt/compile.h>


namespace colorama {
// Some boilerplate code
namespace detail {
constexpr size_t Color_maxlen = 16;
using ColorBase = std::array<char, Color_maxlen>;
}

struct Color : public detail::ColorBase {
    using detail::ColorBase::ColorBase;

    constexpr operator const char *() const {
        return data();
    }
    constexpr operator std::string_view() const {
        return data();
    }
    operator std::string() const {
        return data();
    }
};

// Code ported from ansi.py
constexpr auto CSI = "\033[",
               OSC = "\033]",
               BEL = "\a";


constexpr Color code_to_chars(unsigned code) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}m"), CSI, code);
    return fres;
}

constexpr Color set_title(std::string_view title) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}2;{}{}"), OSC, title, BEL);
    return fres;
}

constexpr Color clean_screen(unsigned mode = 2) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}J"), CSI, mode);
    return fres;
}

constexpr Color clear_line(unsigned mode = 2) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}K"), CSI, mode);
    return fres;
}


namespace Cursor {
constexpr Color UP(unsigned n = 1) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}A"), CSI, n);
    return fres;
}
constexpr Color DOWN(unsigned n = 1) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}B"), CSI, n);
    return fres;
}
constexpr Color FORWARD(unsigned n = 1) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}C"), CSI, n);
    return fres;
}
constexpr Color BACK(unsigned n = 1) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{}D"), CSI, n);
    return fres;
}
constexpr Color POS(unsigned x = 1, unsigned y = 1) {
    auto fres = Color();
    fmt::format_to(fres.data(), FMT_COMPILE("{}{};{}H"), CSI, y, x);
    return fres;
}
}

#define COLORAMA_CODE(name, code) constexpr Color name = code_to_chars(code)

namespace Fore {
COLORAMA_CODE(BLACK, 30);
COLORAMA_CODE(RED, 31);
COLORAMA_CODE(GREEN, 32);
COLORAMA_CODE(YELLOW, 33);
COLORAMA_CODE(BLUE, 34);
COLORAMA_CODE(MAGENTA, 35);
COLORAMA_CODE(CYAN, 36);
COLORAMA_CODE(WHITE, 37);
COLORAMA_CODE(RESET, 39);

COLORAMA_CODE(LIGHTBLACK_EX, 90);
COLORAMA_CODE(LIGHTRED_EX, 91);
COLORAMA_CODE(LIGHTGREEN_EX, 92);
COLORAMA_CODE(LIGHTYELLOW_EX, 93);
COLORAMA_CODE(LIGHTBLUE_EX, 94);
COLORAMA_CODE(LIGHTMAGENTA_EX, 95);
COLORAMA_CODE(LIGHTCYAN_EX, 96);
COLORAMA_CODE(LIGHTWHITE_EX, 97);
}

namespace Back {
COLORAMA_CODE(BLACK, 40);
COLORAMA_CODE(RED, 41);
COLORAMA_CODE(GREEN, 42);
COLORAMA_CODE(YELLOW, 43);
COLORAMA_CODE(BLUE, 44);
COLORAMA_CODE(MAGENTA, 45);
COLORAMA_CODE(CYAN, 46);
COLORAMA_CODE(WHITE, 47);
COLORAMA_CODE(RESET, 49);

COLORAMA_CODE(LIGHTBLACK_EX, 100);
COLORAMA_CODE(LIGHTRED_EX, 101);
COLORAMA_CODE(LIGHTGREEN_EX, 102);
COLORAMA_CODE(LIGHTYELLOW_EX, 103);
COLORAMA_CODE(LIGHTBLUE_EX, 104);
COLORAMA_CODE(LIGHTMAGENTA_EX, 105);
COLORAMA_CODE(LIGHTCYAN_EX, 106);
COLORAMA_CODE(LIGHTWHITE_EX, 107);
}

namespace Style {
COLORAMA_CODE(BRIGHT, 1);
COLORAMA_CODE(DIM, 2);
COLORAMA_CODE(NORMAL, 22);
COLORAMA_CODE(RESET_ALL, 0);
}
}
