#include <iostream>
#include "cpu.h"
#include "memory.h"

CPU::CPU(Memory &MMU) : MMU(MMU)
{

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
	Byte opcode; 

	InterruptHandler();

	opcode = MMU[PC++];

	switch (opcode) { // todo: replace with table
	// 8-bit Loads	
	case 0x06:
		B = MMU[PC]; // LD B, n
		PC++;
		Cycles++;
		break;
	case 0x0E:
		C = MMU[PC]; // LD C, n
		PC++;
		Cycles++;
		break;
	case 0x16:
		D = MMU[PC]; // LD D, n
		PC++;
		Cycles++;
		break;
	case 0x1E:
		E = MMU[PC]; // LD E, n
		PC++;
		Cycles++;
		break;
	case 0x26:
		H = MMU[PC]; // LD H, n
		PC++;
		Cycles++;
		break;
	case 0x2E:
		L = MMU[PC]; // LD L, n
		PC++;
		Cycles++;
		break;

	default:
		std::cerr << "Unknown instruction: " << hex << opcode;
		break;
}

void CPU::Push(u8 data)
{
	MMU[--SP] = data;
}

void CPU::Pop(u8& data)
{
	data = MMU[SP++];
}

void CPU::Push(u16 data)
{
	Push(static_cast<Byte>(data & 0xFF));
	Push(static_cast<Byte>(data >> 8));
}

void CPU::Pop(u16& data)
{
	u8 L, H;
	Pop(L);
	Pop(H);

	data = H + (L << 8);
}
