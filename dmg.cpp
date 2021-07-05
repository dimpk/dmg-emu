#include "dmg.h"

DMG::DMG()
{
	cartridge = new Cartridge;
	mem = new Memory(*cartridge);
	cpu = new CPU(*mem);
}

DMG::~DMG()
{
	delete cpu;
	delete mem;
	delete cartridge;
}
