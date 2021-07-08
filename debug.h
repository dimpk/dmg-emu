#ifndef DEBUG_H
#define DEBUG_H

class CPU;

class Debug {
	static const char* Instructions[0x100];

public:
	static void PrintRegisters(CPU *cpu);
	static void PrintInstruction(CPU *cpu);
};

#endif