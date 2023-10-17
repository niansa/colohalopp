#pragma once
#include "spinners.hpp"
#include "log_symbols.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <memory>
#include <functional>
#include <ctime>
#include <cassert>
#include <colorama/ansi.hpp>


class Halo {
    static constexpr time_t no_interval_magic = 0xdead5610;
    static constexpr colorama::Color neutral_color = colorama::Fore::RESET;

    std::unique_ptr<std::thread> spinner_thread;
    unsigned frame_idx;
    size_t last_text_len = 0;
    std::shared_ptr<bool> wants_stop;
    bool enabled = true;

public:
    enum Side {
        left,
        right
    };

    struct Settings {
        std::string text;
        spinners::Spinner spinner = spinners::dots;
        Side placement = left;
        colorama::Color color = colorama::Fore::CYAN;
        colorama::Color text_color = colorama::Fore::RESET;
        uint32_t interval = no_interval_magic;
        std::ostream *stream = &std::clog;
    } settings;

private:
    static void set_cursor_hidden(bool);

    void run_thread();
    void show_spinner_frame(std::string_view);
    void show_spinner();
    void show_custom_text(std::string_view);
    void show_text();
    void show();

public:
    Halo(const Settings& settings_) : settings(settings_) {
        reset();
        wants_stop = std::make_shared<bool>(false);
        if (settings.interval == 0xdead5610) {
            settings.interval = settings.spinner.interval;
        }
    }
    Halo() : Halo(Settings()) {}
    ~Halo() {
        if (is_running()) {
            stop();
        }
    }

    void pause(bool paused = true) {
        enabled = !paused;
        set_cursor_hidden(is_running()?enabled:false);
    }
    void resume() {
        pause(false);
    }

    void start() {
        *wants_stop = false;
        spinner_thread = std::make_unique<std::thread>([this] () {run_thread();});
    }
    void stop() {
        assert(wants_stop);
        *wants_stop = true;
        spinner_thread->join();
        spinner_thread.reset();
    }
    bool is_running() const {
        return spinner_thread != nullptr;
    }

    void reset() {
        frame_idx = settings.spinner.get_frame_count()-1;
    }

    void status(std::string_view, std::string_view message, colorama::Color text_color = neutral_color);
    void info(std::string_view message, colorama::Color text_color = neutral_color) {status(LogSymbols::INFO, message, text_color);}
    void success(std::string_view message, colorama::Color text_color = neutral_color) {status(LogSymbols::SUCCESS, message, text_color);}
    void warning(std::string_view message, colorama::Color text_color = neutral_color) {status(LogSymbols::WARNING, message, text_color);}
    void error(std::string_view message, colorama::Color text_color = neutral_color) {status(LogSymbols::ERROR, message, text_color);}
};
