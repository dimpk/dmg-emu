#ifndef DMG_H
#define DMG_H

#include <cstring>
#include "cpu.h"
#include "memory.h"
#include "cartridge.h"

class CPU;
class Cartridge;
class Memory;

class DMG {
public:
	// Components
	CPU *cpu;
	Memory *mem;
	Cartridge *ctg;
	GPU *gpu;

public:
	DMG();
	~DMG();

	void Run();

	void InsertCartridge(std::string filename);

};

#endif
