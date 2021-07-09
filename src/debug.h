#ifndef DEBUG_H
#define DEBUG_H

#include "types.h"

class CPU;
class Memory;

class Debug {
	static const char* Instructions[0x100];

public:
	static void PrintRegisters(CPU *cpu);
	static void PrintInstruction(CPU *cpu);

	static void PrintMemoryAccess(Memory *mem, const char* region, u16 addr);
};

#endif