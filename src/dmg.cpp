#include "dmg.h"
#include <unistd.h>

DMG::DMG()
{
	ctg = new Cartridge;
	gpu = new GPU;
	mem = new Memory(*ctg, *gpu);
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
	ctg->Insert(filename);
}

DMG::~DMG()
{
	delete cpu;
	delete mem;
	delete ctg;
}
