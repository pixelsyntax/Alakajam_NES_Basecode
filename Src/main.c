
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


