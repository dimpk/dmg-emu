#include <fstream>
#include "memory.h"

Memory::Memory(Cartridge &c, GPU &g) : ctg(c), gpu(g)
{

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
			Debug::PrintMemoryAccess(this, "ROM", addr);
			return ctg.ROM[addr];

		// Video RAM (VRAM)
		case 0x8000:
		case 0x9000:
			return gpu.VRAM[addr & 0x1FFF];
			break;

		// External RAM
		case 0xA000:
		case 0xB000:
			return ctg.RAM[addr];

		// Work RAM (WRAM)
		case 0xC000:
		case 0xD000:
		case 0xE000:
			Debug::PrintMemoryAccess(this, "WRAM", addr);
			return WRAM[addr & 0x1FFF];

		case 0xF000:
			if (addr >= 0xFE00 && addr <= 0xFE9F)
				return gpu.OAM[addr & 0x0]; // ?
			if (addr >= 0xFF80)
				return HRAM[addr & 0x0]; // ?

		default:
			break;
	}

}

Memory::~Memory()
{

}
