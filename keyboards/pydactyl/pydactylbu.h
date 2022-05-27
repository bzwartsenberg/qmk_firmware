#pragma once

#include "quantum.h"

#define XXX KC_NO

#ifndef FLIP_HALF
#define LAYOUT( \
    L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
         L31, L32,                                         R31, R32, \
                   L40, L41, L42,           R40, R41, R42, \
                        L43, L44,           R43, R44 \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, XXX, L32, L31, XXX }, \
    { L40, L41, L42, L43, L44 }, \
\
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { XXX, XXX, R32, R31, XXX }, \
    { R44, R43, R42, R41, R40 } \
}
#else
#define LAYOUT( \
    L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
         L31, L32,                                         R31, R32, \
                   L40, L41, L42,           R40, R41, R42, \
                        L43, L44,           R43, R44 \
) { \
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { XXX, XXX, R32, R31, XXX }, \
    { R44, R43, R42, R41, R40 } \
\
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, XXX, L32, L31, XXX }, \
    { L40, L41, L42, L43, L44 }, \
}
#endif
