#include <spinners.hpp>
#include <colorama/ansi.hpp>
#include <halo.hpp>

#include <iostream>
#include <chrono>
#include <thread>


int main() {
    using namespace std::chrono_literals;

    Halo halo({.text="Doing something very complicated...", .spinner=spinners::dots, .text_color=colorama::Fore::GREEN});
    halo.start();
    std::this_thread::sleep_for(5s);
    halo.success("It worked!");
    halo.settings.text = "Doing something error-prone...";
    halo.settings.text_color = colorama::Fore::YELLOW;
    std::this_thread::sleep_for(2s);
    halo.stop();
    halo.error("Oops!", colorama::Fore::RED);
}
