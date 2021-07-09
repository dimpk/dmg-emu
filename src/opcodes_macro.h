#ifndef OP_MACRO_H
#define OP_MACRO_H


#define OP(NUM) \
	&CPU::opcode##NUM##0, &CPU::opcode##NUM##1, &CPU::opcode##NUM##2, &CPU::opcode##NUM##3, \
	&CPU::opcode##NUM##4, &CPU::opcode##NUM##5, &CPU::opcode##NUM##6, &CPU::opcode##NUM##7, \
	&CPU::opcode##NUM##8, &CPU::opcode##NUM##9, &CPU::opcode##NUM##A, &CPU::opcode##NUM##B, \
	&CPU::opcode##NUM##C, &CPU::opcode##NUM##D, &CPU::opcode##NUM##E, &CPU::opcode##NUM##F

#define OPCODES \
	OP(0), OP(1), OP(2), OP(3), OP(4), OP(5), OP(6), OP(7), \
	OP(8), OP(9), OP(A), OP(B), OP(C), OP(D), OP(E), OP(F)


#define OP_FUN(NUM) \
	void opcode##NUM##0(); void opcode##NUM##1(); void opcode##NUM##2(); void opcode##NUM##3(); \
	void opcode##NUM##4(); void opcode##NUM##5(); void opcode##NUM##6(); void opcode##NUM##7(); \
	void opcode##NUM##8(); void opcode##NUM##9(); void opcode##NUM##A(); void opcode##NUM##B(); \
	void opcode##NUM##C(); void opcode##NUM##D(); void opcode##NUM##E(); void opcode##NUM##F()

#define OPCODES_FUN \
	OP_FUN(0); OP_FUN(1); OP_FUN(2); OP_FUN(3); OP_FUN(4); OP_FUN(5); OP_FUN(6); OP_FUN(7); \
	OP_FUN(8); OP_FUN(9); OP_FUN(A); OP_FUN(B); OP_FUN(C); OP_FUN(D); OP_FUN(E); OP_FUN(F)

/*
#define CB_OPCODES \
	opcodeCB00, \

#define CB_OPCODES_FUN \
	void opcodeCB00() \
*/

#endif
