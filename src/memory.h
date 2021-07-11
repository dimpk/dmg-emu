#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "types.h"
#include "cartridge.h"
#include "gpu.h"
#include "debug.h"

class Memory {
	u8 WRAM[0x2000]; // $C000 - $DFFF, 8kB Work RAM
	u8 HRAM[0x007F]; // $FF80 - $FFFE, 127B RAM

	// Components
	Cartridge &ctg;
	GPU &gpu;

	friend class Debug;
public:
	Memory(Cartridge &c, GPU &g);
	~Memory();

	u8& operator[](const u16 addr);
};

#endif
