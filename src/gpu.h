#ifndef GPU_H
#define GPU_H

#include <vector>
#include "types.h"

class GPU {
	enum LCDModes {
		LCD_HBLANK,
		LCD_VBLANK,
		LCD_OAM,
		LCD_OAMVRAM
	};

	u8 LCDC; // LCD Control
	u8 STAT; // LCD Status
	u8 SCY, SCX; 
	u8 LY;
	u8 LYC;
	u8 WY, WX; 

public:
	u8 VRAM[0x2000]; // $8000 - $9FFF, 8kB Video RAM
	u8 OAM[0x00A0];  // $FE00 - $FE9F, Sprite attribute table

	void Update();
};

#endif