#include <iostream>
#include "cpu.h"
#include "memory.h"

CPU::CPU(Memory &m) : mem(m)
{
	Init();
}

void CPU::Init()
{
	AF = 0x01B0;
	BC = 0x0013;
	DE = 0x00D8;
	HL = 0x014D;
	SP = 0xFFFE;
	PC = 0x0100;	  
}

void CPU::InterruptHandler()
{
	if (IF & IE & 0x1F) // checking for interruptions 
		return;
	
	if (HaltMode) {
		HaltMode = false;
		Cycles++;
	}

	if (IME) {
		IME = 0;

		Push(PC);

		if ((IF & INT_VBLANK) && (IE & INT_VBLANK)) {
			IF &= ~INT_VBLANK;
			PC = 0x40;
		} else if ((IF & INT_LCDSTAT) && (IE & INT_LCDSTAT)) {
			IF &= ~INT_LCDSTAT;
			PC = 0x48;
		} else if ((IF & INT_TIMER) && (IE & INT_TIMER)) {
			IF &= ~INT_TIMER;
			PC = 0x50;
		} else if ((IF & INT_SERIAL) && (IE & INT_SERIAL)) {
			IF &= ~INT_SERIAL;
			PC = 0x58;
		} else if ((IF & INT_JOYPAD) && (IE & INT_JOYPAD)) {
			IF &= ~INT_JOYPAD;
			PC = 0x60;
		}

		Cycles += 5; // It takes 20 clocks (5 cycles) to dispatch an interrupt.
	}
}

void CPU::Execute()
{
	u8 opcode; 

//	InterruptHandler();

	opcode = mem[PC++];

	switch (opcode) { // todo: replace with table
	// NOP
	case 0x00:
		Cycles++;
		break;

	// 8-bit Loads	
	case 0x06:
		B = mem[PC]; // LD B, n
		PC++;
		Cycles++;
		break;
	case 0x0E:
		C = mem[PC]; // LD C, n
		PC++;
		Cycles++;
		break;
	case 0x16:
		D = mem[PC]; // LD D, n
		PC++;
		Cycles++;
		break;
	case 0x1E:
		E = mem[PC]; // LD E, n
		PC++;
		Cycles++;
		break;
	case 0x26:
		H = mem[PC]; // LD H, n
		PC++;
		Cycles++;
		break;
	case 0x2E:
		L = mem[PC]; // LD L, n
		PC++;
		Cycles++;
		break;

	case 0x5D:
 		E = L;
		Cycles++;
		break;

	// Jumps
	case 0xC3:
		PC = mem[PC];
		PC++;
		break;

	default:
		std::cerr << "Unknown instruction: " << std::hex << (unsigned)opcode << "\n";
		break;
	}
}

void CPU::Push(u8 data)
{
	mem[--SP] = data;
}

void CPU::Pop(u8& data)
{
	data = mem[SP++];
}

void CPU::Push(u16 data)
{
	Push(static_cast<u8>(data & 0xFF));
	Push(static_cast<u8>(data >> 8));
}

void CPU::Pop(u16& data)
{
	u8 L, H;
	Pop(L);
	Pop(H);

	data = H + (L << 8);
}
