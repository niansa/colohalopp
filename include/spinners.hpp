#pragma once

#include <string_view>
#include <array>
#include <ctime>


namespace spinners {
struct Spinner {
    time_t interval; // In milliseconds
    std::array<std::string_view, 32> frames; // Max 32 frames

    constexpr size_t get_frame_count() const {
        size_t counter = 0;
        while (counter < frames.size() && !frames[counter].empty()) counter++;
        return counter-1;
    }
};

constexpr Spinner dots {80, {"\u280b", "\u2819", "\u2839", "\u2838", "\u283c", "\u2834", "\u2826", "\u2827", "\u2807", "\u280f"}};
constexpr Spinner dots2 {80, {"\u28fe", "\u28fd", "\u28fb", "\u28bf", "\u287f", "\u28df", "\u28ef", "\u28f7"}};
constexpr Spinner dots3 {80, {"\u280b", "\u2819", "\u281a", "\u281e", "\u2816", "\u2826", "\u2834", "\u2832", "\u2833", "\u2813"}};
constexpr Spinner dots4 {80, {"\u2804", "\u2806", "\u2807", "\u280b", "\u2819", "\u2838", "\u2830", "\u2820", "\u2830", "\u2838", "\u2819", "\u280b", "\u2807", "\u2806"}};
constexpr Spinner dots5 {80, {"\u280b", "\u2819", "\u281a", "\u2812", "\u2802", "\u2802", "\u2812", "\u2832", "\u2834", "\u2826", "\u2816", "\u2812", "\u2810", "\u2810", "\u2812", "\u2813", "\u280b"}};
constexpr Spinner dots6 {80, {"\u2801", "\u2809", "\u2819", "\u281a", "\u2812", "\u2802", "\u2802", "\u2812", "\u2832", "\u2834", "\u2824", "\u2804", "\u2804", "\u2824", "\u2834", "\u2832", "\u2812", "\u2802", "\u2802", "\u2812", "\u281a", "\u2819", "\u2809", "\u2801"}};
constexpr Spinner dots7 {80, {"\u2808", "\u2809", "\u280b", "\u2813", "\u2812", "\u2810", "\u2810", "\u2812", "\u2816", "\u2826", "\u2824", "\u2820", "\u2820", "\u2824", "\u2826", "\u2816", "\u2812", "\u2810", "\u2810", "\u2812", "\u2813", "\u280b", "\u2809", "\u2808"}};
constexpr Spinner dots8 {80, {"\u2801", "\u2801", "\u2809", "\u2819", "\u281a", "\u2812", "\u2802", "\u2802", "\u2812", "\u2832", "\u2834", "\u2824", "\u2804", "\u2804", "\u2824", "\u2820", "\u2820", "\u2824", "\u2826", "\u2816", "\u2812", "\u2810", "\u2810", "\u2812", "\u2813", "\u280b", "\u2809", "\u2808", "\u2808"}};
constexpr Spinner dots9 {80, {"\u28b9", "\u28ba", "\u28bc", "\u28f8", "\u28c7", "\u2867", "\u2857", "\u284f"}};
constexpr Spinner dots10 {80, {"\u2884", "\u2882", "\u2881", "\u2841", "\u2848", "\u2850", "\u2860"}};
constexpr Spinner dots11 {100, {"\u2801", "\u2802", "\u2804", "\u2840", "\u2880", "\u2820", "\u2810", "\u2808"}};
constexpr Spinner line {130, {"-", "\\", "|", "/"}};
constexpr Spinner line2 {100, {"\u2802", "-", "\u2013", "\u2014", "\u2013", "-"}};
constexpr Spinner pipe {100, {"\u2524", "\u2518", "\u2534", "\u2514", "\u251c", "\u250c", "\u252c", "\u2510"}};
constexpr Spinner simpleDots {400, {".  ", ".. ", "...", "   "}};
constexpr Spinner simpleDotsScrolling {200, {".  ", ".. ", "...", " ..", "  .", "   "}};
constexpr Spinner star {70, {"\u2736", "\u2738", "\u2739", "\u273a", "\u2739", "\u2737"}};
constexpr Spinner star2 {80, {"+", "x", "*"}};
constexpr Spinner flip {70, {"_", "_", "_", "-", "`", "`", "'", "\u00b4", "-", "_", "_", "_"}};
constexpr Spinner hamburger {100, {"\u2631", "\u2632", "\u2634"}};
constexpr Spinner growVertical {120, {"\u2581", "\u2583", "\u2584", "\u2585", "\u2586", "\u2587", "\u2586", "\u2585", "\u2584", "\u2583"}};
constexpr Spinner growHorizontal {120, {"\u258f", "\u258e", "\u258d", "\u258c", "\u258b", "\u258a", "\u2589", "\u258a", "\u258b", "\u258c", "\u258d", "\u258e"}};
constexpr Spinner balloon {140, {" ", ".", "o", "O", "@", "*", " "}};
constexpr Spinner balloon2 {120, {".", "o", "O", "\u00b0", "O", "o", "."}};
constexpr Spinner noise {100, {"\u2593", "\u2592", "\u2591"}};
constexpr Spinner bounce {120, {"\u2801", "\u2802", "\u2804", "\u2802"}};
constexpr Spinner boxBounce {120, {"\u2596", "\u2598", "\u259d", "\u2597"}};
constexpr Spinner boxBounce2 {100, {"\u258c", "\u2580", "\u2590", "\u2584"}};
constexpr Spinner triangle {50, {"\u25e2", "\u25e3", "\u25e4", "\u25e5"}};
constexpr Spinner arc {100, {"\u25dc", "\u25e0", "\u25dd", "\u25de", "\u25e1", "\u25df"}};
constexpr Spinner circle {120, {"\u25e1", "\u2299", "\u25e0"}};
constexpr Spinner squareCorners {180, {"\u25f0", "\u25f3", "\u25f2", "\u25f1"}};
constexpr Spinner circleQuarters {120, {"\u25f4", "\u25f7", "\u25f6", "\u25f5"}};
constexpr Spinner circleHalves {50, {"\u25d0", "\u25d3", "\u25d1", "\u25d2"}};
constexpr Spinner squish {100, {"\u256b", "\u256a"}};
constexpr Spinner toggle {250, {"\u22b6", "\u22b7"}};
constexpr Spinner toggle2 {80, {"\u25ab", "\u25aa"}};
constexpr Spinner toggle3 {120, {"\u25a1", "\u25a0"}};
constexpr Spinner toggle4 {100, {"\u25a0", "\u25a1", "\u25aa", "\u25ab"}};
constexpr Spinner toggle5 {100, {"\u25ae", "\u25af"}};
constexpr Spinner toggle6 {300, {"\u101d", "\u1040"}};
constexpr Spinner toggle7 {80, {"\u29be", "\u29bf"}};
constexpr Spinner toggle8 {100, {"\u25cd", "\u25cc"}};
constexpr Spinner toggle9 {100, {"\u25c9", "\u25ce"}};
constexpr Spinner toggle10 {100, {"\u3282", "\u3280", "\u3281"}};
constexpr Spinner toggle11 {50, {"\u29c7", "\u29c6"}};
constexpr Spinner toggle12 {120, {"\u2617", "\u2616"}};
constexpr Spinner toggle13 {80, {"=", "*", "-"}};
constexpr Spinner arrow {100, {"\u2190", "\u2196", "\u2191", "\u2197", "\u2192", "\u2198", "\u2193", "\u2199"}};
constexpr Spinner arrow2 {80, {"\u2b06\ufe0f ", "\u2197\ufe0f ", "\u27a1\ufe0f ", "\u2198\ufe0f ", "\u2b07\ufe0f ", "\u2199\ufe0f ", "\u2b05\ufe0f ", "\u2196\ufe0f "}};
constexpr Spinner arrow3 {120, {"\u25b9\u25b9\u25b9\u25b9\u25b9", "\u25b8\u25b9\u25b9\u25b9\u25b9", "\u25b9\u25b8\u25b9\u25b9\u25b9", "\u25b9\u25b9\u25b8\u25b9\u25b9", "\u25b9\u25b9\u25b9\u25b8\u25b9", "\u25b9\u25b9\u25b9\u25b9\u25b8"}};
constexpr Spinner bouncingBar {80, {"[    ]", "[=   ]", "[==  ]", "[=== ]", "[ ===]", "[  ==]", "[   =]", "[    ]", "[   =]", "[  ==]", "[ ===]", "[====]", "[=== ]", "[==  ]", "[=   ]"}};
constexpr Spinner bouncingBall {80, {"( \u25cf    )", "(  \u25cf   )", "(   \u25cf  )", "(    \u25cf )", "(     \u25cf)", "(    \u25cf )", "(   \u25cf  )", "(  \u25cf   )", "( \u25cf    )", "(\u25cf     )"}};
constexpr Spinner pong {80, {"\u2590\u2802       \u258c", "\u2590\u2808       \u258c", "\u2590 \u2802      \u258c", "\u2590 \u2820      \u258c", "\u2590  \u2840     \u258c", "\u2590  \u2820     \u258c", "\u2590   \u2802    \u258c", "\u2590   \u2808    \u258c", "\u2590    \u2802   \u258c", "\u2590    \u2820   \u258c", "\u2590     \u2840  \u258c", "\u2590     \u2820  \u258c", "\u2590      \u2802 \u258c", "\u2590      \u2808 \u258c", "\u2590       \u2802\u258c", "\u2590       \u2820\u258c", "\u2590       \u2840\u258c", "\u2590      \u2820 \u258c", "\u2590      \u2802 \u258c", "\u2590     \u2808  \u258c", "\u2590     \u2802  \u258c", "\u2590    \u2820   \u258c", "\u2590    \u2840   \u258c", "\u2590   \u2820    \u258c", "\u2590   \u2802    \u258c", "\u2590  \u2808     \u258c", "\u2590  \u2802     \u258c", "\u2590 \u2820      \u258c", "\u2590 \u2840      \u258c", "\u2590\u2820       \u258c"}};
constexpr Spinner shark {120, {"\u2590|\\____________\u258c", "\u2590_|\\___________\u258c", "\u2590__|\\__________\u258c", "\u2590___|\\_________\u258c", "\u2590____|\\________\u258c", "\u2590_____|\\_______\u258c", "\u2590______|\\______\u258c", "\u2590_______|\\_____\u258c", "\u2590________|\\____\u258c", "\u2590_________|\\___\u258c", "\u2590__________|\\__\u258c", "\u2590___________|\\_\u258c", "\u2590____________|\\\u258c", "\u2590____________/|\u258c", "\u2590___________/|_\u258c", "\u2590__________/|__\u258c", "\u2590_________/|___\u258c", "\u2590________/|____\u258c", "\u2590_______/|_____\u258c", "\u2590______/|______\u258c", "\u2590_____/|_______\u258c", "\u2590____/|________\u258c", "\u2590___/|_________\u258c", "\u2590__/|__________\u258c", "\u2590_/|___________\u258c", "\u2590/|____________\u258c"}};
constexpr Spinner dqpb {100, {"d", "q", "p", "b"}};
constexpr Spinner grenade {80, {"\u060c   ", "\u2032   ", " \u00b4 ", " \u203e ", "  \u2e0c", "  \u2e0a", "  |", "  \u204e", "  \u2055", " \u0df4 ", "  \u2053", "   ", "   ", "   "}};
constexpr Spinner point {125, {"\u2219\u2219\u2219", "\u25cf\u2219\u2219", "\u2219\u25cf\u2219", "\u2219\u2219\u25cf", "\u2219\u2219\u2219"}};
constexpr Spinner layer {150, {"-", "=", "\u2261"}};
}
