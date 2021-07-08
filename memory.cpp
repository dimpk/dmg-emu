#include <fstream>
#include "memory.h"

Memory::Memory(Cartridge &c) : cartridge(c)
{
	WRAM = std::vector<u8>(0xFFFF);
}

u8& Memory::operator[](const u16 addr)
{
	switch (addr & 0xF000) {
		// ROM
		case 0x0000:
		case 0x1000:
		case 0x2000:
		case 0x3000:

		// Switchable ROM
		case 0x4000:
		case 0x5000:
		case 0x6000:
		case 0x7000:
			return cartridge[addr];
			break;

		// Video RAM (VRAM)
		case 0x8000:
		case 0x9000:

		// External RAM
		case 0xA000:
		case 0xB000:

		// Work RAM (WRAM)
		case 0xC000:
		case 0xD000:
		case 0xE000:
		case 0xF000:
		default:
			return WRAM[addr];
	}

}

Memory::~Memory()
{

}
