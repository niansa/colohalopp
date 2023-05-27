#include "halo.hpp"
#include "colorama.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#ifdef _WIN32
#include <windows.h>
#endif



void Halo::set_cursor_hidden(bool hidden) {
#ifdef _WIN32
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = !hidden;
    SetConsoleCursorInfo(out, &cursorInfo);
#else
    std::cout << "\033[?25" << (hidden?'l':'h') << std::flush;
#endif
}

void Halo::show_spinner_frame(std::string_view frame) {
    // Set color
    *settings.stream << settings.color;
    // Show frame
    *settings.stream << frame;
}

void Halo::show_spinner() {
    // Increment frame index
    assert(!settings.spinner.frames[0].empty());
    if (++frame_idx > settings.spinner.get_frame_count()) {
        frame_idx = 0;
    }
    // Show frame
    show_spinner_frame(settings.spinner.frames[frame_idx]);
}

void Halo::show_custom_text(std::string_view text) {
    // Set color
    *settings.stream << settings.text_color;
    // Calculate text length difference
    ssize_t diff = last_text_len - text.size();
    // Print text (TODO: Add animations)
    *settings.stream << text;
    last_text_len = text.size();
    // Make sure to overwrite old text
    if (diff > 0) {
        std::string placeholder;
        placeholder.resize(diff, ' ');
        *settings.stream << placeholder << colorama::Cursor::BACK(diff);
    }
}

void Halo::show_text() {
    show_custom_text(settings.text);
}

void Halo::show() {
    // Don't run if disabled
    if (!enabled) return;
    // Show spinner and text, in the correct order
    *settings.stream << std::flush;
    if (settings.placement == left) {
        show_spinner();
        *settings.stream << ' ';
    }
    show_text();
    if (settings.placement == right) {
        *settings.stream << ' ';
        show_spinner();
    }
    *settings.stream << '\r' << std::flush;
    // Reset color
    *settings.stream << colorama::Fore::RESET;
}

void Halo::status(std::string_view frame, std::string_view message, colorama::Color text_color) {
    // Set custom color
    auto color_bak = settings.text_color;
    if (text_color != neutral_color) {
        settings.text_color = text_color;
    }
    // Show given spinner frame and text, in the correct order
    *settings.stream << std::flush;
    if (settings.placement == left) {
        show_spinner_frame(frame);
        *settings.stream << ' ';
    }
    show_custom_text(message);
    if (settings.placement == right) {
        *settings.stream << ' ';
        show_spinner_frame(frame);
    }
    *settings.stream << std::endl;
    // Reset color
    *settings.stream << colorama::Fore::RESET;
    // Restore color
    settings.text_color = color_bak;
}

void Halo::run_thread() {
    auto stop_req = wants_stop;
    set_cursor_hidden(true);
    while (!*stop_req) {
        show();
        std::this_thread::sleep_for(std::chrono::milliseconds(settings.interval));
    }
    set_cursor_hidden(false);
}
