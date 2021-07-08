#include <iostream>
#include "dmg.h"

int main ()
{
	std::cout << "Gameboy Emulator\n";

	DMG Emulator;
	Emulator.InsertCartridge("Dr.Mario.gb");

	Emulator.Run();
	
	return 0;
}
