#include <iostream>
#include "dmg.h"

int main ()
{
	std::cout << "Gameboy Emulator\n";

	DMG Emulator;
	Emulator.cartridge->Insert("Dr.Mario.gb");
	for (int i = 0; i < 4; i++)
		Emulator.cpu->Execute();

	return 0;
}
