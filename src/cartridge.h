#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <cstring>
#include "types.h"

class Cartridge {
	const char* CartridgeType[0x100];
	const char* ROMSize[0x09];
	const char* RAMSize[0x06];
	const char* DestCode[0x02];

	bool Inserted;

public:
	u8 *ROM, *RAM;
	
	Cartridge();
	void Insert(std::string filename);
	void Remove();

	u8& operator[](u16 addr);

	void PrintInfo();
};

#endif
