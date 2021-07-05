#ifndef DMG_H
#define DMG_H

#include "cpu.h"
#include "memory.h"
#include "cartridge.h"

class CPU;
class Cartridge;
class Memory;

class DMG {
public:
	CPU *cpu;
	Memory *mem;

public:
	DMG();
	~DMG();

	Cartridge *cartridge;
};

#endif
