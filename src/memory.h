#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include "types.h"
#include "cartridge.h"
#include "debug.h"

class Memory {
	std::vector<u8> WRAM;
	std::vector<u8> HRAM;

	// Components
	Cartridge &cartridge;

	friend class Debug;
public:
	Memory(Cartridge &c);
	~Memory();

	u8& operator[](const u16 addr);
};

#endif
