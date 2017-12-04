#include <stdint.h>
#include "levels.h"

#define ____ 0x00
#pragma rodata-name(push, "LVLDAT1")
const struct LevelHeader header1 = {
    "Title Screen",
{
    // Background palette
    0x22, 0x03, 0x23, 0x30, // skyblue, dark purple, med purple, white
    0x0f, 0x11, 0x21, 0x30, // black, blue, blue, white
    0x0f, 0x07, 0x17, 0x0f, // black, brown, light brown, black
    0x0f, 0x0a, 0x1a, 0x0f, // black, green, light green, black

    // Sprite palette
    0x0F, 0x02, 0x07, 0x26, // xx, blue, brown, pink
    0x0F, 0x16, 0x2d, 0x0f, // xx, light red, gray, black
    0x0F, 0x02, 0x11, 0x20, // xx, blue, light blue, white
    0x0F, 0x2c, 0x28, 0x30, // xx, cyan, yellow, white
}, {
// In order to make the screen maps encodable in ascii, I'm using the upper
// bits to encode the palette number and the lower bits to encode the object
// type.
//
// Byte:  b7 b6 b5 b4 b3 b2 b1 b0
//
// b6 b5: Palette number (' ' thru '/' mean palette 1)
//                       ('@' thru 'O' mean palette 2)
//                       ('`' trhu 'o' mean palette 3)
// TODO: find a better encoding so palette 0 is useful too.
//
// b3 b2 b1 b0: Object number, depending on the objtables below.

    { 0, 0, 0, 0 },  // space (also blank background)
    { 0, 0, 0, 0 },  // !
    { 0, 0, 0, 0 },  // "
    { 0, 0, 0, 0 },  // #
    { 0, 0, 0, 0 },  // $
    { 0x54, 0, 0x68, 0 },  // %  Th
    { 0x65, 0, 0x20, 0 },  // &  e
    { 0x52, 0, 0x65, 0 },  // '  Re
    { 0x76, 0, 0x65, 0 },  // (  ve
    { 0x6e, 0, 0x67, 0 },  // )  ng
    { 0x65, 0, 0x21, 0 },  // *  e!
    { 0x2, 0x3, 0x4, 0x5 },  // +  LI
    { 0x2, 0x3, 0x0, 0x0 },  // ,  L
    { 0x8, 0x9, 0x4, 0x5 },  // -  DI
    { 0xc, 0xd, 0xc, 0xd },  // .  GG
    { 0xa, 0xb, 0xe, 0xf },  // /  ER
}, {
    { 0x83, 0x83, 0x83, 0x83 },  // @ (background - black)
    { 0x8a, 0x8a, 0x8b, 0x8b },  // A (ladder)
    { 0, 0, 0, 0 },  // B
    { 0, 0, 0, 0 },  // C
    { 0x84, 0x85, 0x86, 0x87 },  // D ("mario" block)
    { 0x82, 0x82, 0x82, 0x82 },  // E (bricks)
    { 0x81, 0x81, 0x81, 0x81 },  // F (dirt wall)
    { 0x80, 0x80, 0x80, 0x80 },  // G (grass)

    { 0, 0, 0, 0 },  // H
    { 0x81, 0x88, 0x81, 0x88 },  // I (dirt ceiling)
    { 0, 0, 0, 0 },  // J
    { 0, 0, 0, 0 },  // K

    { 0, 0, 0, 0 },  // L
    { 0, 0, 0, 0 },  // M
    { 0, 0, 0, 0 },  // N
    { 0, 0, 0, 0 },  // O
}, {
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,____,
    },
    1,         // start room
    0, 0,      // start position in the map (above)
    64, 128,   // pixel location in start room
    2,         // Next bank
};

const uint8_t level1[][16*16] = {
// LVLDAT1 -- screen 0
"E               "  // 0
"E               "  // 1
"E               "  // 2
"E               "  // 3
"E               "  // 4
"E               "  // 5
"E               "  // 6
"E               "  // 7
"E               "  // 8
"E               "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"\x49\x07"
"",

// LVLDAT1 -- screen 01
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"        E       "  // 4
"                "  // 5
"                "  // 6
"      EEEEE     "  // 7
"                "  // 8
"                "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"\x86\x04\xa6\x04\xe9\x03"
"",

// LVLDAT1 -- screen 02
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"                "  // 5
"                "  // 6
"   DD           "  // 7
"   DD      DD   "  // 8
"   DD      DD   "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"\x99\x01"
"",


// LVLDAT1 -- screen 03
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"                "  // 5
"                "  // 6
"    DD          "  // 7
"    DD          "  // 8
"    DD          "  // 9
"ggggggggggggg   "  // A
"FFFFFFFFFFFFF   "  // B
"FFFFFFFFFFFFF   "  // B
"",

// LVLDAT1 -- screen 04
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"             EEE"  // 4
"                "  // 5
"                "  // 6
"     EEEEEEEEEEE"  // 7
"                "  // 8
"                "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"\xe3\x04\xe6\x04",

// LVLDAT1 -- screen 05
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"EEE             "  // 4
"                "  // 5
"                "  // 6
"EEEEEEEE        "  // 7
"    E           "  // 8
"    E           "  // 9
"    Eggggggggggg"  // A
"    EFFFFFFFFFFF"  // B
"    EFFFFFFFFFFF"  // B
"\x26\x07\x13\x03"
"",

// LVLDAT1 -- screen 06
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"                "  // 5
"                "  // 6
"      D  D      "  // 7
"     DD  DD     "  // 8
"    DDD  DDD    "  // 9
"ggggggg  ggggggg"  // A
"FFFFFFF  FFFFFFF"  // B
"FFFFFFF  FFFFFFF"  // B
"\x66\x04",

// LVLDAT1 -- screen 07
"                "  // 0
"                "  // 1
"                "  // 2
"         DDD    "  // 3
"        DDDD    "  // 4
"       DDDDD    "  // 5
"      DDDDDD    "  // 6
"     DDDDDDD    "  // 7
"    DDDDDDDD    "  // 8
"   DDDDDDDDD    "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"",

// LVLDAT1 -- screen 08
"                "  // 0
"                "  // 1
"        EEEE    "  // 2
"        E@@E    "  // 3
"    E E EEEE E E"  // 4
"    EEE EEEE EEE"  // 5
"    EEEEEEEEEEEE"  // 6
"    E@EEEEEEEE@E"  // 7
"    EEEEE@@EEEEE"  // 8
"    EEEEE@@EEEEE"  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"\x29\x09",

// LVLDAT1 -- screen xx
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"                "  // 5
"                "  // 6
"                "  // 7
"                "  // 8
"                "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // B
"",


};
#pragma rodata-name(pop)
