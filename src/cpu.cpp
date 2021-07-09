#include <iostream>
#include "cpu.h"

CPU::CPU(Memory &m) : mem(m)
{
	Init();

	IME = 1;
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
	InterruptHandler();

	Opcode = mem[PC++];

	Debug::PrintInstruction(this);
	(this->*instr[Opcode])();
	Debug::PrintRegisters(this);
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
	u8 Low, High;
	Pop(Low);
	Pop(High);

	data = High + (Low << 8);
}

void CPU::WriteMem16(const u16 data, const u16 addr)
{
	mem[addr] = (data & 0xFF);
	mem[addr+1] = (data >> 8);
}

u16 CPU::ReadMem16(const u16 addr)
{
	u16 data;
	data = mem[addr];
	data += mem[addr+1] << 8;

	return data;
}
