#ifndef LD39_LEVELS_H
#define LD39_LEVELS_H
#include <stdint.h>

struct LevelHeader {
    uint8_t name[16];
    // Background & Sprite Palette values
    uint8_t palette[32];

    // In order to make the screen maps encodable in ascii, I'm using the upper
    // bits to encode the palette number and the lower bits to encode the object
    // type.
    //
    // Byte:  b7 b6 b5 b4 b3 b2 b1 b0
    //
    // b6 b5: Palette number (' ' thru '/' mean palette 1)
    //                       ('@' thru 'O' mean palette 2)
    //                       ('`' trhu 'o' mean palette 3)
    // 
    // b4: subtract 1 from palette number.
    //
    // b3 b2 b1 b0: Object number, depending on the objtables below.

    // Object table 0 uses palettes 0 and 1
    uint8_t objtable0[16][4];
    // Object table 1 uses palettes 2 and 3
    uint8_t objtable1[16][4];

    uint8_t levelmap[256];
    // Starting room number
    uint8_t start_room;
    // Starting location in the levelmap
    uint8_t start_rx, start_ry;
    // Starting pixel x, y
    uint8_t start_px, start_py;
    uint8_t next_bank;
};

extern struct LevelHeader header;

extern const uint8_t level0[][16*16];
extern const struct LevelHeader header0;

extern uint8_t __fastcall__ get_screen(uint8_t scrn, uint8_t offset);

#endif // LD39_LEVELS_H
