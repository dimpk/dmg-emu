#ifndef CPU_H
#define CPU_H

#include "types.h"

class Memory;

class CPU {
	// Registers
	RegPair rpAF, rpBC, rpDE, rpHL;
	u16 &AF = rpAF.pair;
	u16 &BC = rpBC.pair;
	u16 &DE = rpDE.pair;
	u16 &HL = rpHL.pair;
	u8 &A = rpAF.H, &F = rpAF.L;
	u8 &B = rpBC.H, &C = rpBC.L;
	u8 &D = rpDE.H, &E = rpDE.L;
	u8 &H = rpHL.H, &L = rpHL.L;
	u16 SP;
	u16 PC;

	// States
	bool HaltMode;
	bool StopMode;

	// Interrupts
	u8 IME; // Interrupt Master Enable Flag

	// There is 5 interrupt flags in IF, IE
	// Bit 0 - VBlank
	// Bit 1 - LCDSTAT
	// Bit 2 - Timer
	// Bit 3 - Serial
	// Bit 4 - Joypad
	// the others return 1 always when read

	u8 IF; // Interrupt Flags
	u8 IE; // Interrupt Enable

	enum Interrupts {
		INT_VBLANK  = 0x01,
		INT_LCDSTAT = 0x02,
		INT_TIMER   = 0x04,
		INT_SERIAL  = 0x08,
		INT_JOYPAD  = 0x10
	};

	u32 Cycles;

	// Components
	Memory &mem;

	void Init();

	void InterruptHandler();

	void Push(u8 data);
	void Pop(u8& data);
	void Push(u16 data);
	void Pop(u16& data);

public:
	CPU(Memory &m);

	void Execute();
};

#endif
