#pragma once

#ifdef __cplusplus // CPP version.

#include <chrono> // wall timer
#include <ctime>  // cpu timer
#include <unistd.h>

/****************************************************************
 * Provides both wall timer and cpu timer.
 * The difference is wall timer counting the absolute time which 
 * includes the effect of multi-threading, while cpu timer not.
 * 
 * The usage is simple:
 *     auto tick = *_timer::now();
 *     ...
 *     auto tock = *_timer::now();
 *     printf("Takes %.4f seconds.", *_timer::dura_s(tock - tick));
 * ****************************************************************/

namespace wall_timer {
typedef std::chrono::steady_clock::time_point timer_t;
typedef std::chrono::nanoseconds dura_t;

inline wall_timer::timer_t now() { return std::chrono::steady_clock::now(); }

inline long long dura_ms(wall_timer::dura_t ns) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(ns).count();
}

inline float dura_s(wall_timer::dura_t ns) {
    return static_cast<float>(dura_ms(ns)) / 1e3f;
}

} // namespace wall_timer

namespace cpu_timer {

typedef clock_t timer_t;
typedef unsigned long dura_t;

inline cpu_timer::timer_t now() { return clock(); }

inline float dura_s(cpu_timer::dura_t dura) {
    return static_cast<float>(dura) / CLOCKS_PER_SEC;
}
} // namespace cpu_timer

#else // C version.

#include <time.h>

typedef clock_t timer_t;
typedef unsigned long dura_t;

static inline timer_t now() { return clock(); }

static inline float dura_s(cpu_timer::dura_t dura) {
    return (float)dura / CLOCKS_PER_SEC;
}

#endif