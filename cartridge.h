#ifndef __CARTRIDGE_H__
#define __CARTRIDGE_H__

#include <iostream>
#include <vector>

using u8 = uint8_t;
using u16 = uint16_t;

class Cartridge {
	const char* cart_types[0x100];
	const char* rom_sizes[0x09];
	const char* ram_sizes[0x06];
	const char* dest_codes[0x02];

	u8 *ROM, *RAM;

	std::string GameTitle = "";
	u8 CartridgeType;
	u8 ROMSize;
	u8 RAMSize;
	u8 DestCode;

	bool Inserted;

public:
	Cartridge();
	void Insert(std::string filename);
	void Remove();

	u8 operator[](u16 addr);

	void SetInfo();
	void PrintInfo();
};

#endif