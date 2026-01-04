#include <stdint.h>
/*
Clear frame buffer
Reset LY to 0
Set initial mode (OAM)
Initialize timing counters
*/
void ppu_init(); 


/*
Accumulate cycles
Advance PPU modes
Increment LY
Trigger rendering at the right time
Raise VBlank interrupt at LY == 144
*/
void ppu_step(int cpu_cycles);

typedef enum {
    PPU_OAM,
    PPU_TRANSFER,
    PPU_HBLANK,
    PPU_VBLANK
} ppu_mode;

void ppu_set_mode(ppu_mode mode);


/*
Render background for current LY
Render window
Render sprites
Write pixels to framebuffer
*/
void render_scanline(void);


/*
Compute tile row ((SCY + LY) / 8)
Compute pixel row inside tile
Loop over 160 pixels
Fetch tile index from tile map
Fetch tile data
Extract bitplanes
Convert to color via palette
*/
void render_background_scanline(void);


/*
Each tile row = 2 bytes
Extract bit from both bitplanes
Return color index (0–3)
*/
uint32_t apply_palette(uint8_t color);

