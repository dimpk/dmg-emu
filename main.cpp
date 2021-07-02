#include <iostream>
#include "cartridge.h"

int main ()
{
	std::cout << "Gameboy Emulator\n";

	Cartridge C;
	C.Insert("PokemonRed.gb");
	C.PrintInfo();
	return 0;
}
