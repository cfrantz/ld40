#include <stdio.h>
#include <stdint.h>

#include "nesutil.h"
#include "levels.h"

uint8_t ppu_macro_len;
uint8_t ppu_macro[64];

void prepare_ppu_macro(uint8_t xx, uint8_t pal) {
    static uint8_t scrn, x0, x, y, i, a, t, attr;
    static uint16_t addr;

    ppu_macro_len = 0xff;
    scrn = xx >> 4;
    if (pal == 0) {
        x0 = xx & 0xf;
        addr = 0x2080 | (x0 << 1) | ((scrn & 1) ? 0x0400 : 0x0000);
        for(x=i=0; x<2; ++x, ++addr, i^=2) {
            ppu_macro[++ppu_macro_len] = addr >> 8;
            ppu_macro[++ppu_macro_len] = addr;
            ppu_macro[++ppu_macro_len] = 0x80 | 26;
            for(y=0; y<13; y++,x0+=16) {
                //a = get_screen(scrn, y*16 + x0);
                a = get_screen(scrn, x0);
                t = (a & 0x60);
                a &= 15;
                switch(t) {
                    case (1 << 5):
                        ppu_macro[++ppu_macro_len] = header0.objtable0[a][i + 0];
                        ppu_macro[++ppu_macro_len] = header0.objtable0[a][i + 1];
                        break;
                    case (2 << 5):
                    case (3 << 5):
                        ppu_macro[++ppu_macro_len] = header0.objtable1[a][i + 0];
                        ppu_macro[++ppu_macro_len] = header0.objtable1[a][i + 1];
                        break;
                    default:
                        ppu_macro[++ppu_macro_len] = 0;
                        ppu_macro[++ppu_macro_len] = 0;
                }
            }
            x0 -= 0xd0;
            if (i) ++x0;
        }
    } else {
        x0 = xx & 0xe;
        addr = 0x23c8 | (x0>>1) | ((scrn & 1) ? 0x0400 : 0x0000);
        for(y=0; y<13; y+=2, addr+=8) {
            ppu_macro[++ppu_macro_len] = addr >> 8;
            ppu_macro[++ppu_macro_len] = addr;
            ppu_macro[++ppu_macro_len] = 1;

            attr = 0;
            t = get_screen(scrn, x0);
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 0);

            x0 += 1;
            t = get_screen(scrn, x0);
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 2);

            x0 += 15;
            t = get_screen(scrn, x0);
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 4);

            x0 += 1;
            t = get_screen(scrn, x0);
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 6);
            ppu_macro[++ppu_macro_len] = attr;

            x0 += 15;
        }
    }
    ppu_macro[++ppu_macro_len] = 0;
}

void copy_to_vram_simple(uint8_t scrn, uint8_t nt) {
    static uint8_t x, y, i, a, t;

    // Draw all of the tile IDs to PPU ram
    vram_put_addr(0x2080 | (nt ? 0x400 : 0));
    for(y=0; y<13; y++) {
        for(i=0; i<2; i++) {
            for(x=0; x<16; x++) {
//                a = level0[scrn][y*16+x];
                a = get_screen(scrn, y*16+x);
                t = (a & 0x60) >> 5;
                a &= 15;
                switch(t) {
                    case 1:
                        vram_put_data(header0.objtable0[a][i + 0]);
                        vram_put_data(header0.objtable0[a][i + 2]);
                        break;
                    case 2:
                    case 3:
                        vram_put_data(header0.objtable1[a][i + 0]);
                        vram_put_data(header0.objtable1[a][i + 2]);
                        break;
                    default:
                        vram_put_data(0);
                        vram_put_data(0);

                }
            }

        }
    }

    // Put all of the palette values to PPU ram
    vram_put_addr(0x23c8 | (nt ? 0x400 : 0));
    for(y=0; y<13; y+=2) {
        for(x=0; x<16; x+=2) {
            uint8_t attr = 0;
            t = level0[scrn][(y+0)*16+(x+0)];
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 0);

            t = level0[scrn][(y+0)*16+(x+1)];
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 2);

            t = level0[scrn][(y+1)*16+(x+0)];
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 4);

            t = level0[scrn][(y+1)*16+(x+1)];
            a = ((t & 0x60) >> 5) ; //- ((t & 0x10) >> 4);
            attr |= (a << 6);
            vram_put_data(attr);
        }
    }

}

uint8_t __fastcall__ basic_collision(uint16_t x, uint8_t y) {
    // Rearange things so the 'y' value contains the x and y tile coordinates:
    //     y3 y3 y1 y0 x3 x2 x1 x0
    // and so that 'x' contains the screen number.
    y = (y & 0xF0) - 0x20;
    y += (x/16) & 0x0F;
    x = x / 256;
    return get_screen(x, y) & 0x0C;
}

uint8_t __fastcall__ screen_tile(uint16_t x, uint8_t y) {
    // Rearange things so the 'y' value contains the x and y tile coordinates:
    //     y3 y3 y1 y0 x3 x2 x1 x0
    // and so that 'x' contains the screen number.
    y = (y & 0xF0) - 0x20;
    y += (x/16) & 0x0F;
    x = x / 256;
    return get_screen(x, y) & 0x0F;
}

