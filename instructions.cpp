#include "cpu.h"

void CPU::opcode00() { Cycles++; }  // NOP

void CPU::opcode01() {}	// LD BC, nn

void CPU::opcode02() { mem[BC] = A; Cycles += 2; }  // LD (BC), A

void CPU::opcode03() { BC++; Cycles += 2; }	 // INC BC

void CPU::opcode04() {}  // INC B

void CPU::opcode05() {}  // DEC B

void CPU::opcode06() { B = mem[PC++]; Cycles += 2; }  // LD B, n

void CPU::opcode07() {}  // RLC A

void CPU::opcode08() {}  // LD (nn), SP

void CPU::opcode09() {}  // ADD HL, BC
	
void CPU::opcode0A() { A = mem[BC]; Cycles += 2; }  // LD A, (BC)

void CPU::opcode0B() {}  // DEC BC

void CPU::opcode0C() {}  // INC C

void CPU::opcode0D() {}  // DEC C

void CPU::opcode0E() { C = mem[PC++]; Cycles += 2; }  // LD C, n

void CPU::opcode0F() {}  // RRC

void CPU::opcode10() {}  // STOP

void CPU::opcode11() {}  // LD DE, nn

void CPU::opcode12() { mem[DE] = A; Cycles += 2; }  // LD (DE), A
				
void CPU::opcode13() { DE++; Cycles += 2; }  // INC DE

void CPU::opcode14() {}  // INC D

void CPU::opcode15() {}  // DEC D

void CPU::opcode16() { D = mem[PC++]; Cycles += 2; }  // LD D, n

void CPU::opcode17() {}  // RL A

void CPU::opcode18() {}  // JR n

void CPU::opcode19() {}  // ADD HL, DE

void CPU::opcode1A() { A = mem[DE]; Cycles += 2; }  // LD A, (DE)

void CPU::opcode1B() { DE--; Cycles += 2; }  // DEC DE
	
void CPU::opcode1C() {}  // INC E

void CPU::opcode1D() {}  // DEC E

void CPU::opcode1E() { E = mem[PC++]; Cycles += 2; }  // LD E, n

void CPU::opcode1F() {}  // RR A

void CPU::opcode20() {}  // JR NZ, n

void CPU::opcode21() {}  // LD HL, nn

void CPU::opcode22() { mem[HL++] = A; Cycles += 2; }  // LDI (HL), A

void CPU::opcode23() { HL++; Cycles += 2; }  // INC HL

void CPU::opcode24() {}  // INC H

void CPU::opcode25() {}  // DEC H

void CPU::opcode26() { H = mem[PC++]; Cycles += 2; }  // LD H, n

void CPU::opcode27() {}  // DAA

void CPU::opcode28() {}  // JR Z, n

void CPU::opcode29() {}  // ADD HL, HL

void CPU::opcode2A() { A = mem[HL++]; Cycles += 2; }  // LDI A, (HL)

void CPU::opcode2B() { HL--; Cycles += 2; }  // DEC HL
				
void CPU::opcode2C() {}  // INC L

void CPU::opcode2D() {}  // DEC L

void CPU::opcode2E() { L = mem[PC++]; Cycles += 2; }  // LD L, n

void CPU::opcode2F() {}  // CPL 1;

void CPU::opcode30() {}  // JR NC, n

void CPU::opcode31() {}  // LD SP, nn

void CPU::opcode32() { mem[HL--] = A; Cycles += 2; }  // LDD (HL), A

void CPU::opcode33() { SP++; Cycles += 2; }  // INC SP
				
void CPU::opcode34() {}  // INC (HL)

void CPU::opcode35() {}  // DEC (HL)

void CPU::opcode36() { mem[HL] = mem[PC++]; Cycles += 3; }  // LD (HL), n

void CPU::opcode37() {}  // SCF

void CPU::opcode38() {}  // JR C, n

void CPU::opcode39() {}  // ADD HL, SP

void CPU::opcode3A() { A = mem[HL--]; Cycles += 2; }  // LDD A, (HL)

void CPU::opcode3B() { SP--; Cycles += 2; }  // DEC SP

void CPU::opcode3C() {}  // INC A

void CPU::opcode3D() {}  // DEC A

void CPU::opcode3E() { A = mem[PC++]; Cycles += 2; }  // LD A, n

void CPU::opcode3F() {}  // CCF

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

void CPU::opcode76() {}  // HALT

void CPU::opcode77() { mem[HL] = A; Cycles += 2; }  // LD (HL), A

void CPU::opcode78() { A = B; Cycles++; }  // LD A, B

void CPU::opcode79() { A = C; Cycles++; }  // LD A, C

void CPU::opcode7A() { A = D; Cycles++; }  // LD A, D

void CPU::opcode7B() { A = E; Cycles++; }  // LD A, E

void CPU::opcode7C() { A = H; Cycles++; }  // LD A, H

void CPU::opcode7D() { A = L; Cycles++; }  // LD A, L

void CPU::opcode7E() { A = mem[HL]; Cycles += 2; }  // LD A, (HL) 

void CPU::opcode7F() { Cycles++; }  // LD A, A

void CPU::opcode80() {}  // ADD A, B

void CPU::opcode81() {}  // ADD A, C

void CPU::opcode82() {}  // ADD A, D

void CPU::opcode83() {}  // ADD A, E

void CPU::opcode84() {}  // ADD A, H

void CPU::opcode85() {}  // ADD A, L

void CPU::opcode86() {}  // ADD A, (HL)

void CPU::opcode87() {}  // ADD A, A

void CPU::opcode88() {}  // ADC A, B

void CPU::opcode89() {}  // ADC A, C

void CPU::opcode8A() {}  // ADC A, D

void CPU::opcode8B() {}  // ADC A, E

void CPU::opcode8C() {}  // ADC A, H

void CPU::opcode8D() {}  // ADC A, L

void CPU::opcode8E() {}  // ADC A, (HL)

void CPU::opcode8F() {}  // ADC A, A

void CPU::opcode90() {}  // SUB A, B

void CPU::opcode91() {}  // SUB A, C

void CPU::opcode92() {}  // SUB A, D

void CPU::opcode93() {}  // SUB A, E

void CPU::opcode94() {}  // SUB A, H

void CPU::opcode95() {}  // SUB A, L

void CPU::opcode96() {}  // SUB A, (HL)

void CPU::opcode97() {}  // SUB A, A

void CPU::opcode98() {}  // SBC A, B

void CPU::opcode99() {}  // SBC A, C

void CPU::opcode9A() {}  // SBC A, D

void CPU::opcode9B() {}  // SBC A, E

void CPU::opcode9C() {}  // SBC A, H

void CPU::opcode9D() {}  // SBC A, L

void CPU::opcode9E() {}  // SBC A, (HL)

void CPU::opcode9F() {}  // SBC A, A

void CPU::opcodeA0() {}  // AND B

void CPU::opcodeA1() {}  // AND C

void CPU::opcodeA2() {}  // AND D

void CPU::opcodeA3() {}  // AND E

void CPU::opcodeA4() {}  // AND H

void CPU::opcodeA5() {}  // AND L

void CPU::opcodeA6() {}  // AND (HL)

void CPU::opcodeA7() {}  // AND A

void CPU::opcodeA8() {}  // XOR B

void CPU::opcodeA9() {}  // XOR C

void CPU::opcodeAA() {}  // XOR D

void CPU::opcodeAB() {}  // XOR E

void CPU::opcodeAC() {}  // XOR H

void CPU::opcodeAD() {}  // XOR L

void CPU::opcodeAE() {}  // XOR (HL)

void CPU::opcodeAF() {}  // XOR A

void CPU::opcodeB0() {}  // OR B

void CPU::opcodeB1() {}  // OR C

void CPU::opcodeB2() {}  // OR D

void CPU::opcodeB3() {}  // OR E

void CPU::opcodeB4() {}  // OR H

void CPU::opcodeB5() {}  // OR L

void CPU::opcodeB6() {}  // OR (HL)

void CPU::opcodeB7() {}  // OR A

void CPU::opcodeB8() {}  // CP B

void CPU::opcodeB9() {}  // CP C

void CPU::opcodeBA() {}  // CP D

void CPU::opcodeBB() {}  // CP E

void CPU::opcodeBC() {}  // CP H

void CPU::opcodeBD() {}  // CP L

void CPU::opcodeBE() {}  // CP (HL)

void CPU::opcodeBF() {}  // CP A

void CPU::opcodeC0() {}  // RET NZ

void CPU::opcodeC1() {}  // POP BC

void CPU::opcodeC2() {}  // JP NZ, nn

void CPU::opcodeC3() {}  // JP nn

void CPU::opcodeC4() {}  // CALL NZ, nn

void CPU::opcodeC5() {}  // PUSH BC

void CPU::opcodeC6() {}  // ADD A, n

void CPU::opcodeC7() {}  // RST 00

void CPU::opcodeC8() {}  // RET Z

void CPU::opcodeC9() {}  // RET

void CPU::opcodeCA() {}  // JP Z, nn

void CPU::opcodeCB() {}  // CB opcode

void CPU::opcodeCC() {}  // CALL Z, nn

void CPU::opcodeCD() {}  // CALL nn

void CPU::opcodeCE() {}  // ADC A, n

void CPU::opcodeCF() {}  // RST 08

void CPU::opcodeD0() {}  // RET NC

void CPU::opcodeD1() {}  // POP DE

void CPU::opcodeD2() {}  // JP NC, nn

void CPU::opcodeD3() {}  // ?

void CPU::opcodeD4() {}  // CALL NC, nn

void CPU::opcodeD5() {}  // PUSH DE

void CPU::opcodeD6() {}  // SUB A, n

void CPU::opcodeD7() {}  // RST 10

void CPU::opcodeD8() {}  // RET C

void CPU::opcodeD9() {}  // RETI

void CPU::opcodeDA() {}  // JP C, nn

void CPU::opcodeDB() {}  // ?

void CPU::opcodeDC() {}  // CALL C, nn

void CPU::opcodeDD() {}  // ?

void CPU::opcodeDE() {}  // SBC A, n

void CPU::opcodeDF() {}  // RST 18

void CPU::opcodeE0() {}  // LDH (n), A

void CPU::opcodeE1() {}  // POP HL

void CPU::opcodeE2() {}  // LDH (C), A

void CPU::opcodeE3() {}  // ?

void CPU::opcodeE4() {}  // ?

void CPU::opcodeE5() {}  // PUSH HL

void CPU::opcodeE6() {}  // AND n

void CPU::opcodeE7() {}  // RST 20

void CPU::opcodeE8() {}  // ADD SP, n

void CPU::opcodeE9() {}  // JP (HL)

void CPU::opcodeEA() {}  // LD (nn), A

void CPU::opcodeEB() {}  // ?

void CPU::opcodeEC() {}  // ?

void CPU::opcodeED() {}  // ?

void CPU::opcodeEE() {}  // XOR n

void CPU::opcodeEF() {}  // RST 28

void CPU::opcodeF0() {}  // LDH A, (n)

void CPU::opcodeF1() {}  // POP AF

void CPU::opcodeF2() {}  // LD A, (C) 

void CPU::opcodeF3() {}  // DI

void CPU::opcodeF4() {}  // ?

void CPU::opcodeF5() {}  // PUSH AF

void CPU::opcodeF6() {}  // OR n

void CPU::opcodeF7() {}  // RST 30

void CPU::opcodeF8() {}  // LDHL SP, n

void CPU::opcodeF9() { SP = HL; Cycles += 2; }  // LD SP, HL

void CPU::opcodeFA() {}  // LD A, (nn)

void CPU::opcodeFB() {}  // EI

void CPU::opcodeFC() {}  // ?

void CPU::opcodeFD() {}  // ?

void CPU::opcodeFE() {}  // CP n

void CPU::opcodeFF() {}  // RST 38
