#include "dmg.h"
#include <unistd.h>

DMG::DMG()
{
	cartridge = new Cartridge;
	mem = new Memory(*cartridge);
	cpu = new CPU(*mem);
}

void DMG::Run()
{
	for (int i = 0; i < 16; i++) {
		cpu->Execute();
	}
}

void DMG::InsertCartridge(std::string filename)
{
	cartridge->Insert(filename);
}

DMG::~DMG()
{
	delete cpu;
	delete mem;
	delete cartridge;
}
