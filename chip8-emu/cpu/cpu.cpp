#include "cpu.h"

CPU::CPU() {
	PC = START_ADDRESS;

	for (unsigned int i = 0; i < FONTSET_SIZE; i++) {
		memory[FONTSET_START_ADDRESS + i] = fontset[i];
	}
}

void CPU::LoadRom(const char* filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if (file.is_open()) {
		std::streampos size = file.tellg();
		char* buffer = new char[size];

		file.seekg(0, std::ios::beg);
		file.read(buffer, size);
		file.close();

		for (long i = 0; i < size; i++) {
			memory[START_ADDRESS + i] = buffer[i];
		}

		delete[] buffer;
	}
}

// ------------
// Instructions
// ------------

void CPU::INST_00E0() {
	memset(display, 0, sizeof(display));
}

void CPU::INST_00EE() {
	--SP;
	PC = stack[SP];
}

void CPU::INST_1NNN() {
	PC = NNN;
}

void CPU::INST_2NNN() {
	++SP;
	stack[SP] = PC;
	PC = NNN;
}

void CPU::INST_3XNN() {
	uint8_t VX = X >> 8u;

	if (registers[VX] == NN)
		PC += 2;
}