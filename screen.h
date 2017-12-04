#ifndef LD39_SCREEN_H
#define LD39_SCREEN_H

extern uint8_t ppu_macro_len;
extern uint8_t ppu_macro[64];

#define ppu_macro_reset() (ppu_macro_len = 0)
void ppu_macro_addr(uint16_t addr, uint8_t len);
#define ppu_macro_data(b_) (  ppu_macro[ppu_macro_len++] = b_ )


void prepare_ppu_macro(uint8_t xx, uint8_t pal);
void copy_to_vram_simple(uint8_t scrn, uint8_t nt);
uint8_t __fastcall__ basic_collision(uint16_t x, uint8_t y);
uint8_t __fastcall__ screen_tile(uint16_t x, uint8_t y);


#endif // LD39_SCREEN_H
