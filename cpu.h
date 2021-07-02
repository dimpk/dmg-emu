#ifndef __CPU_H__
#define __CPU_H__

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;


class Memory;

class CPU {
	union RegPair {
		struct {
			u8 L;
			u8 H;			
		};
		u16 pair;
	} rpAF, rpBC, rpDE, rpHL;

	// Registers
	u16 &AF = rpAF.pair;
	u16 &BC = rpBC.pair;
	u16 &DE = rpDE.pair;
	u16 &HL = rpHL.pair;
	u8 &A = rpAF.H;
	u8 &F = rpAF.L;
	u8 &B = rpBC.H;
	u8 &C = rpBC.L;
	u8 &D = rpDE.H;
	u8 &E = rpDE.L;
	u8 &H = rpHL.H;
	u8 &L = rpHL.L;
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
	Memory &MMU;

	void Init();
	void Execute();

	void InterruptHandler();

	void Push(u8 data);
	void Pop(u8& data);
	void Push(u16 data);
	void Pop(u16& data);

public:


};

#endif
