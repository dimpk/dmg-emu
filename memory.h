#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "types.h"
#include "cartridge.h"

class Memory {
	std::vector<u8> WRAM;

	// Components
	Cartridge &cartridge;

public:
	Memory(Cartridge &c);
	~Memory();

	u8& operator[](const u16 addr);
};

#endif
