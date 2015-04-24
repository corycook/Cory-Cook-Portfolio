#pragma once

struct int16 {
	char low;
	char high;
	int16() { }
	int16(int i) {
		high = i >> 8;
		low = i;
	}
	operator int() {
		return low | high << 8;
	}
};

struct f1 {
	unsigned : 6;
	unsigned source : 2;
	unsigned immediate : 1;
	unsigned destination : 2;
	unsigned operation : 5;
};

struct f2 {
	unsigned constant : 8;
	unsigned immediate : 1;
	unsigned destination : 2;
	unsigned operation : 5;
};

struct f3 {
	unsigned address : 8;
	unsigned immediate : 1;
	unsigned destination : 2;
	unsigned operation : 5;
};

union instruction {
	int i;
	f1 format1;
	f2 format2;
	f3 format3;
};

struct sr {
	unsigned : 11;
	unsigned overflow : 1;
	unsigned less : 1;
	unsigned equal : 1;
	unsigned greater : 1;
	unsigned carry : 1;
};

class VirtualMachine
{
	static const int REG_FILE_SIZE = 4;
	static const int MEM_SIZE = 256;
	int16 *r, *mem, pc, ir, sr, sp, base, limit, clock;
public:
	VirtualMachine();
	~VirtualMachine();

	// load
	// loadi
	// store
	// add
	// addi
	// addc
	// addci
	// sub
	// subi
	// subc
	// subci
	// and
	// andi
	// xor
	// xori
	// compl
	// shl
	// shla
	// shr
	// shra
	// compr
	// compri
	// getstat
	// putstat
	// jump
	// jumpl
	// jumpe
	// jumpg
	// call
	// return
	// write
	// halt
	// noop
};

