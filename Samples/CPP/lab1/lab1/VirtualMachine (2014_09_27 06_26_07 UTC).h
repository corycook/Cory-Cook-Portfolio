#pragma once
class VirtualMachine
{
public:
	VirtualMachine();
	~VirtualMachine();
private:
	static const int REG_FILE_SIZE = 4;
	static const int MEM_SIZE = 256;
	int *r;
	int *mem;
	int pc, sr, sp, clock;
	class format1 {
	public:
		unsigned UNUSED : 6;
		unsigned RS : 2;
		unsigned I : 1;
		unsigned RD : 2;
		unsigned OP : 5;
	};

	class format2 {
	public:
		unsigned ADDR : 8;
		unsigned I : 1;
		unsigned RD : 2;
		unsigned OP : 5;
	};


	class format3 {
	public:
		int CONST : 8;
		unsigned I : 1;
		unsigned RD : 2;
		unsigned OP : 5;
	};

	union instruction {
		int i;
		format1 f1;
		format2 f2;
		format3 f3;
	};

	union reg {
		int i;
		instruction ir;

	};
};

