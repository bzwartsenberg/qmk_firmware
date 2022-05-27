#pragma once

#include "quantum.h"

#define XXX KC_NO
// F7 -> Brown        -> row0
// B1 -> Orange       -> row1
// B3 -> Black        -> row2
// B2 -> Purple       -> row3
// B6 -> Brown/Yel    -> row4
// Columns (for both sides!)
// C6 -> Yellow       -> col4
// C7 -> red          -> col3  (row of UJM)
// E6 -> green        -> col2
// B4 -> blue         -> col1
// B5 -> yellow/black -> col0
#ifndef FLIP_HALF
#define LAYOUT( \
    L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
         L32, L33,                                         R32, R33, \
                   L40, L41, L42,           R40, R41, R42, \
                        L43, L44,           R43, R44 \
) {								 \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { XXX, XXX, L32, L33, XXX }, \
    { L40, L41, L42, L43, L44 }, \
\
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { XXX, R33, R32, XXX, XXX }, \
    { R42, R41, R40, R44, R43 } \
}
#else
#define LAYOUT( \
    L00, L01, L02, L03, L04,                     R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,                     R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,                     R20, R21, R22, R23, R24, \
         L32, L33,                                         R32, R33, \
                   L40, L41, L42,           R40, R41, R42, \
                        L43, L44,           R43, R44 \
) { \
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { XXX, R33, R32, XXX, XXX }, \
    { R44, R43, R42, R41, R40 } \
\
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { XXX, R33, R32, XXX, XXX }, \
    { R42, R41, R40, R44, R43 } \
}
#endif
