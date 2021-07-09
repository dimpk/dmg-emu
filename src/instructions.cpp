#include <iostream>
#include "cpu.h"

#define F_Z(BOOL) \
	(BOOL) ? F |= F_Z : F &= ~F_Z

#define F_N(BOOL) \
	(BOOL) ? F |= F_N : F &= ~F_Z

#define F_H(BOOL) \
	(BOOL) ? F |= F_H : F &= ~F_H

#define F_C(BOOL) \
	(BOOL) ? F |= F_C : F &= ~F_C

// INC, DEC operations used only for byte values
#define DEC(VAL) \
	VAL--; \
	F_Z(VAL == 0); \
	F_N(true); \
	F_H((VAL & 0xF) == 0xF) 

#define INC(VAL) \
	VAL++; \
	F_Z(VAL == 0); \
	F_N(false); \
	F_H((VAL & 0xF) == 0x0) 

#define SUB(VAL) \
	F_Z(A == VAL); \
	F_N(true);; \
	F_H((A & 0xF) < (VAL & 0xF)); \
	F_C(A < VAL); \
	A -= VAL;

#define CP(VAL) \
	F_Z(A == VAL); \
	F_N(true);; \
	F_H((A & 0xF) < (VAL & 0xF)); \
	F_C(A < VAL); \

#define JR(BOOL) \
	(BOOL) ? PC += (int8_t)mem[PC] : false; \
	PC++

void CPU::opcode00() { Cycles++; }  // NOP

void CPU::opcode01() { BC = ReadMem16(PC); PC += 2; Cycles += 3; }  // LD BC, nn

void CPU::opcode02() { mem[BC] = A; Cycles += 2; }  // LD (BC), A

void CPU::opcode03() { BC++; Cycles += 2; }	 // INC BC

void CPU::opcode04() { INC(B); Cycles++; }  // INC B

void CPU::opcode05() { DEC(B); Cycles++; }  // DEC B

void CPU::opcode06() { B = mem[PC++]; Cycles += 2; }  // LD B, n

void CPU::opcode07() { std::cout << "Unimplemented\n"; exit(1); }  // RLC A

void CPU::opcode08() { std::cout << "Unimplemented\n"; exit(1); }  // LD (nn), SP

void CPU::opcode09() { std::cout << "Unimplemented\n"; exit(1); }  // ADD HL, BC
	
void CPU::opcode0A() { A = mem[BC]; Cycles += 2; }  // LD A, (BC)

void CPU::opcode0B() { BC--; Cycles+=2; }  // DEC BC

void CPU::opcode0C() { INC(C); Cycles++; }  // INC C

void CPU::opcode0D() { DEC(C); Cycles++; }  // DEC C

void CPU::opcode0E() { C = mem[PC++]; Cycles += 2; }  // LD C, n

void CPU::opcode0F() { std::cout << "Unimplemented\n"; exit(1); }  // RRC

void CPU::opcode10() { std::cout << "Unimplemented\n"; exit(1); }  // STOP

void CPU::opcode11() { std::cout << "Unimplemented\n"; exit(1); }  // LD DE, nn

void CPU::opcode12() { mem[DE] = A; Cycles += 2; }  // LD (DE), A
				
void CPU::opcode13() { DE++; Cycles += 2; }  // INC DE

void CPU::opcode14() { INC(D); Cycles++; }  // INC D

void CPU::opcode15() { DEC(D); Cycles++; }  // DEC D

void CPU::opcode16() { D = mem[PC++]; Cycles += 2; }  // LD D, n

void CPU::opcode17() { std::cout << "Unimplemented\n"; exit(1); }  // RL A

void CPU::opcode18() { JR(true); Cycles +=2; }  // JR n

void CPU::opcode19() { std::cout << "Unimplemented\n"; exit(1); }  // ADD HL, DE

void CPU::opcode1A() { A = mem[DE]; Cycles += 2; }  // LD A, (DE)

void CPU::opcode1B() { DE--; Cycles += 2; }  // DEC DE
	
void CPU::opcode1C() { INC(E); Cycles++; }  // INC E

void CPU::opcode1D() { DEC(E); Cycles++; }  // DEC E

void CPU::opcode1E() { E = mem[PC++]; Cycles += 2; }  // LD E, n

void CPU::opcode1F() { std::cout << "Unimplemented\n"; exit(1); }  // RR A

void CPU::opcode20() { JR(~F & F_Z); ~F & F_Z ? Cycles += 2 : Cycles++; }  // JR NZ, n

void CPU::opcode21() { HL = ReadMem16(PC); PC += 2; Cycles +=3; }  // LD HL, nn

void CPU::opcode22() { mem[HL++] = A; Cycles += 2; }  // LDI (HL), A

void CPU::opcode23() { HL++; Cycles += 2; }  // INC HL

void CPU::opcode24() { INC(H); Cycles++; }  // INC H

void CPU::opcode25() { DEC(H); Cycles++; }  // DEC H

void CPU::opcode26() { H = mem[PC++]; Cycles += 2; }  // LD H, n

void CPU::opcode27() { std::cout << "Unimplemented\n"; exit(1); }  // DAA

void CPU::opcode28() {JR(F & F_Z); F & F_Z ? Cycles += 2 : Cycles++; }  // JR Z, n

void CPU::opcode29() { std::cout << "Unimplemented\n"; exit(1); }  // ADD HL, HL

void CPU::opcode2A() { A = mem[HL++]; Cycles += 2; }  // LDI A, (HL)

void CPU::opcode2B() { HL--; Cycles += 2; }  // DEC HL
				
void CPU::opcode2C() { INC(L); Cycles++; }  // INC L

void CPU::opcode2D() { DEC(L); Cycles++; }  // DEC L

void CPU::opcode2E() { L = mem[PC++]; Cycles += 2; }  // LD L, n

void CPU::opcode2F() { std::cout << "Unimplemented\n"; exit(1); }  // CPL 1;

void CPU::opcode30() { JR(~F & F_C); ~F & F_C ? Cycles += 2 : Cycles++; }  // JR NC, n

void CPU::opcode31() { std::cout << "Unimplemented\n"; exit(1); }  // LD SP, nn

void CPU::opcode32() { mem[HL--] = A; Cycles += 2; }  // LDD (HL), A

void CPU::opcode33() { SP++; Cycles += 2; }  // INC SP
				
void CPU::opcode34() { INC(mem[HL]); Cycles += 3; }  // INC (HL)

void CPU::opcode35() { DEC(mem[HL]); Cycles += 3; }  // DEC (HL)

void CPU::opcode36() { mem[HL] = mem[PC++]; Cycles += 3; }  // LD (HL), n

void CPU::opcode37() { std::cout << "Unimplemented\n"; exit(1); }  // SCF

void CPU::opcode38() { JR(F & F_C); F & F_C ? Cycles += 2 : Cycles++; }  // JR C, n

void CPU::opcode39() { std::cout << "Unimplemented\n"; exit(1); }  // ADD HL, SP

void CPU::opcode3A() { A = mem[HL--]; Cycles += 2; }  // LDD A, (HL)

void CPU::opcode3B() { SP--; Cycles += 2; }  // DEC SP

void CPU::opcode3C() { std::cout << "Unimplemented\n"; exit(1); }  // INC A

void CPU::opcode3D() { DEC(A); Cycles++; }  // DEC A

void CPU::opcode3E() { A = mem[PC++]; Cycles += 2; }  // LD A, n

void CPU::opcode3F() { std::cout << "Unimplemented\n"; exit(1); }  // CCF

void CPU::opcode40() { Cycles++; }  // LD B, B

void CPU::opcode41() { B = C; Cycles++; }  // LD B, C

void CPU::opcode42() { B = D; Cycles++; }  // LD B, D

void CPU::opcode43() { B = E; Cycles++; }  // LD B, E

void CPU::opcode44() { B = H; Cycles++; }  // LD B, H

void CPU::opcode45() { B = L; Cycles++; }  // LD B, L

void CPU::opcode46() { B = mem[HL]; Cycles += 2; }  // LD B, (HL)

void CPU::opcode47() { B = A; Cycles++; }  // LD B, A

void CPU::opcode48() { C = B; Cycles++; }  // LD C, B

void CPU::opcode49() { Cycles++; }  // LD C, C

void CPU::opcode4A() { C = D; Cycles++; }  // LD C, D

void CPU::opcode4B() { C = E; Cycles++; }  // LD C, E

void CPU::opcode4C() { C = H; Cycles++; }  // LD C, H

void CPU::opcode4D() { C = L; Cycles++; }  // LD C, L

void CPU::opcode4E() { C = mem[HL]; Cycles+= 2; }  // LD C, (HL)

void CPU::opcode4F() { C = A; Cycles++; }  // LD C, A

void CPU::opcode50() { D = B; Cycles++; }  // LD D, B

void CPU::opcode51() { D = C; Cycles++; }  // LD D, C

void CPU::opcode52() { Cycles++; }  // LD D, D

void CPU::opcode53() { D = E; Cycles++; }  // LD D, E

void CPU::opcode54() { D = H; Cycles++; }  // LD D, H

void CPU::opcode55() { D = L; Cycles++; }  // LD D, L

void CPU::opcode56() { D = mem[HL]; Cycles += 2; }  // LD D, (HL)

void CPU::opcode57() { D = A; Cycles++; }  // LD D, A

void CPU::opcode58() { E = B; Cycles++; }  // LD E, B

void CPU::opcode59() { E = C; Cycles++; }  // LD E, C

void CPU::opcode5A() { E = D; Cycles++; }  // LD E, D

void CPU::opcode5B() { Cycles++; }  // LD E, E

void CPU::opcode5C() { E = H; Cycles++; }  // LD E, H

void CPU::opcode5D() { E = L; Cycles++; }  // LD E, L

void CPU::opcode5E() { E = mem[HL]; Cycles += 2; }  // LD E, (HL)

void CPU::opcode5F() { E = A; Cycles++; }  // LD E, A

void CPU::opcode60() { H = B; Cycles++; }  // LD H, B

void CPU::opcode61() { H = C; Cycles++; }  // LD H, C

void CPU::opcode62() { H = D; Cycles++; }  // LD H, D

void CPU::opcode63() { H = E; Cycles++; }  // LD H, E

void CPU::opcode64() { Cycles++; }  // LD H, H

void CPU::opcode65() { H = L; Cycles++; }  // LD H, L

void CPU::opcode66() { H = mem[HL]; Cycles += 2; }  // LD H, (HL)

void CPU::opcode67() { H = A; Cycles++; }  // LD H, A

void CPU::opcode68() { L = B; Cycles++; }  // LD L, B

void CPU::opcode69() { L = C; Cycles++; }  // LD L, C

void CPU::opcode6A() { L = D; Cycles++; }  // LD L, D

void CPU::opcode6B() { L = E; Cycles++; }  // LD L, E

void CPU::opcode6C() { L = H; Cycles++; }  // LD L, H

void CPU::opcode6D() { Cycles++; }  // LD L, L

void CPU::opcode6E() { L = mem[HL]; Cycles += 2; }  // LD L, (HL)

void CPU::opcode6F() { L = A; Cycles++; }  // LD L, A

void CPU::opcode70() { mem[HL] = B; Cycles += 2; }  // LD (HL), B

void CPU::opcode71() { mem[HL] = C; Cycles += 2; }  // LD (HL), C

void CPU::opcode72() { mem[HL] = D; Cycles += 2; }  // LD (HL), D

void CPU::opcode73() { mem[HL] = E; Cycles += 2; }  // LD (HL), E

void CPU::opcode74() { mem[HL] = H; Cycles += 2; }  // LD (HL), H

void CPU::opcode75() { mem[HL] = L; Cycles += 2; }  // LD (HL), L

void CPU::opcode76() { std::cout << "Unimplemented\n"; exit(1); }  // HALT

void CPU::opcode77() { mem[HL] = A; Cycles += 2; }  // LD (HL), A

void CPU::opcode78() { A = B; Cycles++; }  // LD A, B

void CPU::opcode79() { A = C; Cycles++; }  // LD A, C

void CPU::opcode7A() { A = D; Cycles++; }  // LD A, D

void CPU::opcode7B() { A = E; Cycles++; }  // LD A, E

void CPU::opcode7C() { A = H; Cycles++; }  // LD A, H

void CPU::opcode7D() { A = L; Cycles++; }  // LD A, L

void CPU::opcode7E() { A = mem[HL]; Cycles += 2; }  // LD A, (HL)

void CPU::opcode7F() { Cycles++; }  // LD A, A

void CPU::opcode80() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, B

void CPU::opcode81() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, C

void CPU::opcode82() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, D

void CPU::opcode83() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, E

void CPU::opcode84() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, H

void CPU::opcode85() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, L

void CPU::opcode86() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, (HL)

void CPU::opcode87() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, A

void CPU::opcode88() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, B

void CPU::opcode89() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, C

void CPU::opcode8A() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, D

void CPU::opcode8B() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, E

void CPU::opcode8C() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, H

void CPU::opcode8D() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, L

void CPU::opcode8E() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, (HL)

void CPU::opcode8F() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, A

void CPU::opcode90() { SUB(B); Cycles++; }  // SUB A, B

void CPU::opcode91() { SUB(C); Cycles++; }  // SUB A, C

void CPU::opcode92() { SUB(D); Cycles++; }  // SUB A, D

void CPU::opcode93() { SUB(E); Cycles++; }  // SUB A, E

void CPU::opcode94() { SUB(H); Cycles++; }  // SUB A, H

void CPU::opcode95() { SUB(L); Cycles++; }  // SUB A, L

void CPU::opcode96() { SUB(mem[HL]); Cycles += 2; }  // SUB A, (HL)

void CPU::opcode97() { SUB(A); Cycles++; }  // SUB A, A

void CPU::opcode98() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, B

void CPU::opcode99() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, C

void CPU::opcode9A() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, D

void CPU::opcode9B() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, E

void CPU::opcode9C() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, H

void CPU::opcode9D() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, L

void CPU::opcode9E() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, (HL)

void CPU::opcode9F() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, A

void CPU::opcodeA0() { A &= B; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND B

void CPU::opcodeA1() { A &= C; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND C

void CPU::opcodeA2() { A &= D; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND D

void CPU::opcodeA3() { A &= E; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND E

void CPU::opcodeA4() { A &= H; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND H

void CPU::opcodeA5() { A &= L; A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND L

void CPU::opcodeA6() { A &= mem[HL]; A == 0 ? F = F_Z : false; F_H(true); Cycles += 2; }  // AND (HL)

void CPU::opcodeA7() { A == 0 ? F = F_Z : false; F_H(true); Cycles++; }  // AND A

void CPU::opcodeA8() { A ^= B; A == 0 ? F = F_Z : false; Cycles++; }  // XOR B

void CPU::opcodeA9() { A ^= C; A == 0 ? F = F_Z : false; Cycles++; }  // XOR C

void CPU::opcodeAA() { A ^= D; A == 0 ? F = F_Z : false; Cycles++; }  // XOR D

void CPU::opcodeAB() { A ^= E; A == 0 ? F = F_Z : false; Cycles++; }  // XOR E

void CPU::opcodeAC() { A ^= H; A == 0 ? F = F_Z : false; Cycles++; }  // XOR H

void CPU::opcodeAD() { A ^= L; A == 0 ? F = F_Z : false; Cycles++; }  // XOR L

void CPU::opcodeAE() { A ^= mem[HL]; A == 0 ? F = F_Z : false; Cycles += 2; }  // XOR (HL)

void CPU::opcodeAF() { A = 0; F = F_Z; Cycles++; }  // XOR A

void CPU::opcodeB0() { A |= B; A == 0 ? F = F_Z : false; Cycles++; }  // OR B

void CPU::opcodeB1() { A |= C; A == 0 ? F = F_Z : false; Cycles++; }  // OR C

void CPU::opcodeB2() { A |= D; A == 0 ? F = F_Z : false; Cycles++; }  // OR D

void CPU::opcodeB3() { A |= E; A == 0 ? F = F_Z : false; Cycles++; }  // OR E

void CPU::opcodeB4() { A |= H; A == 0 ? F = F_Z : false; Cycles++; }  // OR H

void CPU::opcodeB5() { A |= L; A == 0 ? F = F_Z : false; Cycles++; }  // OR L

void CPU::opcodeB6() { A |= mem[HL]; A == 0 ? F = F_Z : false; Cycles += 2; }  // OR (HL)

void CPU::opcodeB7() { A == 0 ? F = F_Z : false; Cycles++; }  // OR A

void CPU::opcodeB8() { CP(B); Cycles++; }  // CP B

void CPU::opcodeB9() { CP(C); Cycles++; }  // CP C

void CPU::opcodeBA() { CP(D); Cycles++; }  // CP D

void CPU::opcodeBB() { CP(E); Cycles++; }  // CP E

void CPU::opcodeBC() { CP(H); Cycles++; }  // CP H

void CPU::opcodeBD() { CP(L); Cycles++; }  // CP L

void CPU::opcodeBE() { CP(mem[HL]); Cycles += 2; }  // CP (HL)

void CPU::opcodeBF() { CP(A); Cycles++; }  // CP A

void CPU::opcodeC0() { std::cout << "Unimplemented\n"; exit(1); }  // RET NZ

void CPU::opcodeC1() { Pop(BC); Cycles += 3; }  // POP BC

void CPU::opcodeC2() { std::cout << "Unimplemented\n"; exit(1); }  // JP NZ, nn

void CPU::opcodeC3() { PC = ReadMem16(PC); Cycles += 3;}  // JP nn

void CPU::opcodeC4() { std::cout << "Unimplemented\n"; exit(1); }  // CALL NZ, nn

void CPU::opcodeC5() { Push(BC); Cycles += 4; }  // PUSH BC

void CPU::opcodeC6() { std::cout << "Unimplemented\n"; exit(1); }  // ADD A, n

void CPU::opcodeC7() { std::cout << "Unimplemented\n"; exit(1); }  // RST 00

void CPU::opcodeC8() { std::cout << "Unimplemented\n"; exit(1); }  // RET Z

void CPU::opcodeC9() { std::cout << "Unimplemented\n"; exit(1); }  // RET

void CPU::opcodeCA() { std::cout << "Unimplemented\n"; exit(1); }  // JP Z, nn

void CPU::opcodeCB() { std::cout << "Unimplemented\n"; exit(1); }  // CB opcode

void CPU::opcodeCC() { std::cout << "Unimplemented\n"; exit(1); }  // CALL Z, nn

void CPU::opcodeCD() { std::cout << "Unimplemented\n"; exit(1); }  // CALL nn

void CPU::opcodeCE() { std::cout << "Unimplemented\n"; exit(1); }  // ADC A, n

void CPU::opcodeCF() { std::cout << "Unimplemented\n"; exit(1); }  // RST 08

void CPU::opcodeD0() { std::cout << "Unimplemented\n"; exit(1); }  // RET NC

void CPU::opcodeD1() { Pop(DE); Cycles += 3; }  // POP DE

void CPU::opcodeD2() { std::cout << "Unimplemented\n"; exit(1); }  // JP NC, nn

void CPU::opcodeD3() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeD4() { std::cout << "Unimplemented\n"; exit(1); }  // CALL NC, nn

void CPU::opcodeD5() { Push(DE); Cycles += 4; }  // PUSH DE

void CPU::opcodeD6() { std::cout << "Unimplemented\n"; exit(1); }  // SUB A, n

void CPU::opcodeD7() { std::cout << "Unimplemented\n"; exit(1); }  // RST 10

void CPU::opcodeD8() { std::cout << "Unimplemented\n"; exit(1); }  // RET C

void CPU::opcodeD9() { std::cout << "Unimplemented\n"; exit(1); }  // RETI

void CPU::opcodeDA() { std::cout << "Unimplemented\n"; exit(1); }  // JP C, nn

void CPU::opcodeDB() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeDC() { std::cout << "Unimplemented\n"; exit(1); }  // CALL C, nn

void CPU::opcodeDD() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeDE() { std::cout << "Unimplemented\n"; exit(1); }  // SBC A, n

void CPU::opcodeDF() { std::cout << "Unimplemented\n"; exit(1); }  // RST 18

void CPU::opcodeE0() { mem[0xFF + mem[PC]] = A; PC++; Cycles +=3; }  // LDH (n), A

void CPU::opcodeE1() { Pop(HL); Cycles += 3; }  // POP HL

void CPU::opcodeE2() { std::cout << "Unimplemented\n"; exit(1); }  // LDH (C), A

void CPU::opcodeE3() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeE4() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeE5() { Push(HL); Cycles += 4; }  // PUSH HL

void CPU::opcodeE6() { std::cout << "Unimplemented\n"; exit(1); }  // AND n

void CPU::opcodeE7() { std::cout << "Unimplemented\n"; exit(1); }  // RST 20

void CPU::opcodeE8() { std::cout << "Unimplemented\n"; exit(1); }  // ADD SP, n

void CPU::opcodeE9() { std::cout << "Unimplemented\n"; exit(1); }  // JP (HL)

void CPU::opcodeEA() { mem[ReadMem16(PC)] = A; PC += 2; Cycles += 4; }  // LD (nn), A

void CPU::opcodeEB() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeEC() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeED() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeEE() { std::cout << "Unimplemented\n"; exit(1); }  // XOR n

void CPU::opcodeEF() { std::cout << "Unimplemented\n"; exit(1); }  // RST 28

void CPU::opcodeF0() { A = mem[0xFF + mem[PC]]; PC++; Cycles += 3; }  // LDH A, (n)

void CPU::opcodeF1() { Pop(AF); Cycles += 3; }  // POP AF

void CPU::opcodeF2() { std::cout << "Unimplemented\n"; exit(1); }  // LD A, (C)

void CPU::opcodeF3() { IME = 0; Cycles++; }  // DI

void CPU::opcodeF4() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeF5() { Push(AF); Cycles += 4; }  // PUSH AF

void CPU::opcodeF6() { std::cout << "Unimplemented\n"; exit(1); }  // OR n

void CPU::opcodeF7() { std::cout << "Unimplemented\n"; exit(1); }  // RST 30

void CPU::opcodeF8() { std::cout << "Unimplemented\n"; exit(1); }  // LDHL SP, n

void CPU::opcodeF9() { SP = HL; Cycles += 2; }  // LD SP, HL

void CPU::opcodeFA() { std::cout << "Unimplemented\n"; exit(1); }  // LD A, (nn)

void CPU::opcodeFB() { std::cout << "Unimplemented\n"; exit(1); }  // EI

void CPU::opcodeFC() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeFD() { std::cout << "Unimplemented\n"; exit(1); }  // ?

void CPU::opcodeFE() { CP(mem[PC]); PC++; Cycles +=2; }  // CP n

void CPU::opcodeFF() { std::cout << "Unimplemented\n"; exit(1); }  // RST 38
