#pragma once

#include <string_view>


namespace LogSymbols {
#ifdef _WIN32
constexpr std::string_view INFO = "ℹ",
                  SUCCESS = "v",
                  WARNING = "!!",
                  ERROR = "×";
#else
constexpr std::string_view INFO = "ℹ",
                  SUCCESS = "✔",
                  WARNING = "⚠",
                  ERROR = "✖";
#endif
}
