namespace colorama {
#ifndef _WIN32
inline static
#endif
void just_fix_windows_console(bool = false)
#ifdef _WIN32
    ;
#else
    {}
#endif

inline void init() {just_fix_windows_console();}
inline void deinit() {just_fix_windows_console(true);}
[[deprecated("Calling reinit() is never required ")]]
inline void reinit() {deinit(); init();}
}
