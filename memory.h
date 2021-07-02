#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <iostream>
#include <vector>
#include <Cartridge.h>

using u8 = uint8_t;
using u16 = uint16_t;

class Memory {
	std::vector<Byte> ROM;

public:
	void LoadROM(Cartridge ROM);

	u8& operator[](u16 addr);
};

#endif
