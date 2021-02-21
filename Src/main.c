
/*
Bank-switching using the MMC3 mapper.
We use a special linker config that sets up
64 KB of PRG ROM and 64 KB of CHR ROM.
Macros are used to set MMC3 registers and switch banks.
CC65 #pragma directives are used to put things in various
PRG ROM segments (CODE0-CODE6, CODE).
*/

// bank-switching configuration
// #define NES_MAPPER 4        // Mapper 4 (MMC3)
// #define NES_PRG_BANKS 4     // # of 16KB PRG banks
// #define NES_CHR_BANKS 8     // # of 8KB CHR banks

#include <peekpoke.h>
#include <string.h>
#include "neslib.h"

// link the pattern table into CHR ROM
//#link "chr_voxel.s"

#define MMC_MODE 0x00
#define TEXT_MSG "VOXEL'S ALAKAJAM 11 BASECODE"

void main(void)
{
  // set palette colors
  pal_col(1,0x0A);
  pal_col(2,0x03);
  pal_col(3,0x30);

  vram_adr(NTADR_A(2,2));
  vram_write( TEXT_MSG, 28 );
  ppu_on_all();
  while(1);//do nothing, infinite loop
}


