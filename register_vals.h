#pragma once
#include <stdint.h>

typedef struct reg_vals{
    uint64_t pfr0[64];
    uint64_t pfr1[64];
    uint64_t afr0[64];
    uint64_t dfr0[64];
    uint64_t mmfr0[64];
    uint64_t mmfr1[64];
    uint64_t mmfr2[64];
    uint64_t isar0[64];
    uint64_t isar1[64];
    uint64_t isar2[64];
} reg_vals;