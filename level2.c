#include <stdint.h>
#include "levels.h"

#define ____ 0x00
#pragma rodata-name(push, "LVLDAT2")
const struct LevelHeader header2 = {
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
    64, 48,   // pixel location in start room
    1,         // Next bank
};

const uint8_t level2[][16*16] = {
// LVLDAT2 -- screen 0
"E             ee"  // 0
"E             ee"  // 1
"E             ee"  // 2
"ggggggggg     gg"  // 3
"FFFFFFFFF@@@@@FF"  // 4
"FFFFFFFFF@@@@@FF"  // 5
"FFFFFFFF@@@@@@FF"  // 6
"FFFFFFF@@@@@@@FF"  // 7
"FFFFFF@@@@@@@@FF"  // 8
"FFFFF@@@@@@@@@@@"  // 9
"FFFF@@@@@@@@@@@@"  // A
"FFFF@@@@@@@@@@@@"  // B
"FFFFFFFFFFFFFFFF"  // C
"\x42\x07"
"",

// LVLDAT2 -- screen 01
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"@@@@@@@@@@@@@@@@"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"@@@@@@@@@@@@e@@@"  // 7
"@@@@@@@@@@d@@@d@"  // 8
"@@@@@@@@d@d@@@d@"  // 9
"@@@@@@d@d@d@@@d@"  // A
"GGGGGGGGGGGGGGGG"  // B
"FFFFFFFFFFFFFFFF"  // C
"\xCA\x03\xC6\x04",

// LVLDAT2 -- screen 02 
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"@@@@@@@@@@@eeeee"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"@@@@@@@@@eeeeeee"  // 7
"@@@@@@@@@@@@@@@@"  // 8
"d@@@@@@@@@@@@@@@"  // 9
"d@d@@@@@@@@@@@@@"  // A
"GGGGGGGGGGGGGGGG"  // B
"FFFFFFFFFFFFFFFF"  // C
"",
// LVLDAT2 -- screen 03 
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"eeeeeeeeeeeeeee@"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"eeeeeeeeeeeeeee@"  // 7
"@@@@@@@@@@@@@@@@"  // 8
"@@@@@@@@@@@@@@@@"  // 9
"@@@@@@@@@@@@@@@@"  // A
"GGGGGG@GGGGGGGGG"  // B
"FFFFFF@FFFFFFFFF"  // C
"\x06\x03\x5a\x01",
// LVLDAT2 -- screen 04 
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"@@@@@@@@@@@@@@@@"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"@@@@@@@@@@@@@@@@"  // 7
"@@@@@@@@@@@@@@@@"  // 8
"@@@@@eeee@@@@@@@"  // 9
"@@@@@@@@@@@@@@@@"  // A
"GGGG@@@@@@GGGGGG"  // B
"FFFF@@@@@@FFFFFF"  // C
"\x49\x04\x99\x04",
// LVLDAT2 -- screen 05 
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"@@@@@@@@@@@@@@@@"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"@@@@@@@@@@@@@@@@"  // 7
"@@@@@@@@@@@@@@@@"  // 8
"@@@@d@@@@d@@@@@@"  // 9
"@@@@d@@@@d@@@@@@"  // A
"GGG@G@GGGGGGGGGG"  // B
"FFF@F@FFFFFFFFFF"  // C
"\x0a\x07\x8a\x01",

// LVLDAT2 -- screen 06 
"eeeeeeg         "  // 0
"@@@@@@Ig        "  // 1
"@@@@@@@Ig       "  // 2
"@@@@@@@@Ig      "  // 3
"@@@@@@@@@IgggAgg"  // 4
"@@@@@@@@@@IIIAIF"  // 5
"@@@@@@@@@@@@@A@F"  // 6
"@@@@@@@@@@@@@A@F"  // 7
"@@@@@@@@@@@@@A@F"  // 8
"@@@@@@@@@@@@@A@F"  // 9
"@@@@@@@@@@@@@A@F"  // A
"GGGGGGGGGGGGGGGF"  // B
"FFFFFFFFFFFFFFFF"  // C
"\x2a\x03\x81\x04",

// LVLDAT2 -- screen 07
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"gggg            "  // 5
"FFFFgg          "  // 6
"FFFFFFgg        "  // 7
"FFFFFFFFgg      "  // 8
"FFFFFFFFFFgg    "  // 9
"FFFFFFFFFFFFgggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // C
"",

// LVLDAT2 -- screen 08
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
"FFFFFFFFFFFFFFFF"  // C
"\x59\x03",

// LVLDAT2 -- screen 08
"                "  // 0
"                "  // 1
"                "  // 2
"                "  // 3
"                "  // 4
"                "  // 5
"       e e e    "  // 6
"       eeeee    "  // 7
"       ee@ee    "  // 8
"       ee@ee    "  // 9
"gggggggggggggggg"  // A
"FFFFFFFFFFFFFFFF"  // B
"FFFFFFFFFFFFFFFF"  // C
"\x59\x09",





// LVLDAT2 -- screen xx 
"eeeeeeeeeeeeeeee"  // 0
"@@@@@@@@@@@@@@@@"  // 1
"@@@@@@@@@@@@@@@@"  // 2
"@@@@@@@@@@@@@@@@"  // 3
"@@@@@@@@@@@@@@@@"  // 4
"@@@@@@@@@@@@@@@@"  // 5
"@@@@@@@@@@@@@@@@"  // 6
"@@@@@@@@@@@@@@@@"  // 7
"@@@@@@@@@@@@@@@@"  // 8
"@@@@@@@@@@@@@@@@"  // 9
"@@@@@@@@@@@@@@@@"  // A
"GGGGGGGGGGGGGGGG"  // B
"FFFFFFFFFFFFFFFF"  // C
"",





};
#pragma rodata-name(pop)
