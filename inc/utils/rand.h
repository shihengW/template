#pragma once

#include <assert.h>
#include <stdint.h>

#define RANDOM_GENERATOR_MULTIPLIER (1103515245ull)
#define RANDOM_GENERATOR_INCREMENT (12345ull)
#define RANDOM_GENERATOR_MOD (1ull << 31)

typedef int32_t rand_t;

/****************************************************************
 * Random number generator.
 * Usage:
 *     Rand a(12);
 *     int32_t rand_num = a.generate();
 ****************************************************************/

#ifdef __cplusplus
class Rand {
  public:
    Rand(int32_t seed) { rand_init(&_rand, seed); }
    int32_t generate() { return rand_gen(&_rand); }
    void reset(int32_t seed) { rand_init(&_rand, seed);}
  private:
    rand_t _rand;
    Rand() {}
#endif

    static inline void rand_init(rand_t *r, int32_t seed) {
        // Won't accept -1 like the system rand.
        assert(seed > 0);
        *r = seed;
    }

    static inline int32_t rand_gen(rand_t *r) {
        assert(*r > 0);
        // Following LCG algorithm: X(n+1) = (a * X(n) + c) mod m
        // See wikipedia for more information.
        uint64_t res = (uint64_t)(*r) * RANDOM_GENERATOR_MULTIPLIER +
                       RANDOM_GENERATOR_INCREMENT;
        *r = (int)(res % RANDOM_GENERATOR_MOD);
        return *r;
    }
#ifdef __cplusplus
};
#endif