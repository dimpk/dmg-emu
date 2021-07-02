#include <fstream>
#include "cartridge.h"

Cartridge::Cartridge()
{
	cart_types[0x00] = "ROM ONLY";
	cart_types[0x01] = "ROM+MBC1";
	cart_types[0x02] = "ROM+MBC1+RAM";
	cart_types[0x03] = "ROM+MBC1+RAM+BATTERY";
	cart_types[0x05] = "ROM+MBC2";
	cart_types[0x06] = "ROM+MBC2+BATTERY";
	cart_types[0x08] = "ROM+RAM";
	cart_types[0x09] = "ROM+RAM+BATTERY";
	cart_types[0x0B] = "ROM+MMM01";
	cart_types[0x0C] = "ROM+MMM01+SRAM";
	cart_types[0x0D] = "ROM+MMM01+SRAM+BATTERY";
	cart_types[0x0F] = "ROM+MBC3+TIMER+BATTERY";
	cart_types[0x10] = "ROM+MBC3+TIMER+RAM+BATTERY";
	cart_types[0x11] = "ROM+MBC3";
	cart_types[0x12] = "ROM+MBC3+RAM";
	cart_types[0x13] = "ROM+MBC3+RAM+BATTERY";
	cart_types[0x19] = "ROM+MBC5";
	cart_types[0x1A] = "ROM+MBC5+RAM";
	cart_types[0x1B] = "ROM+MBC5+RAM+BATTERY";
	cart_types[0x1C] = "ROM+MBC5+RUMBLE";
	cart_types[0x1D] = "ROM+MBC5+RUMBLE+SRAM";
	cart_types[0x1E] = "ROM+MBC5+RUMBLE+SRAM+BATTERY";
	cart_types[0x1F] = "Pocket Camera";
	cart_types[0xFD] = "Bandai TAMA5";
	cart_types[0xFE] = "Hudson HuC-3";
	cart_types[0xFF] = "Hudson HuC-1";

	rom_sizes[0x00] = "32KB - 2 banks";
	rom_sizes[0x01] = "64KB - 4 banks";
	rom_sizes[0x02] = "128KB - 8 banks";
	rom_sizes[0x03] = "256KB - 16 banks";
	rom_sizes[0x04] = "512KB - 32 banks";
	rom_sizes[0x05] = "1MB - 64 banks";
	rom_sizes[0x06] = "2MB - 128 banks";
	rom_sizes[0x07] = "4MB - 256 banks";
	rom_sizes[0x08] = "8KB - 512 banks";

	ram_sizes[0x00] = "None";
	ram_sizes[0x01] = "2KB";
	ram_sizes[0x02] = "8KB - 1 bank";
	ram_sizes[0x03] = "32KB - 4 banks of 8KB";
	ram_sizes[0x04] = "128KB - 16 banks of 8KB";
	ram_sizes[0x05] = "64KB - 8 banks of 8KB";

	dest_codes[0x00] = "Japan";
	dest_codes[0x01] = "Other";
}

void Cartridge::SetInfo()
{
	// 0x134 - 0x143
	// Title of the game in UPPER CASE ASCII. 
	// If it is less than 16 characters then the remaining bytes 
	// are filled with $00 bytes.
	for (int i = 0x134; i <= 0x143; i++) {
		if (ROM[i] == 0)
			break;
		GameTitle.push_back(ROM[i]);
	}

	// 0x147 
	// Cartridge Type
	CartridgeType = ROM[0x147];

	// 0x148
	// ROM Size
	ROMSize = ROM[0x148]; // change all this shit with pointers

	// 0x149
	// RAM Size
	RAMSize = ROM[0x149];

	// 0x14A
	// Destination Code
	DestCode = ROM[0x14A];

}

void Cartridge::PrintCLI()
{
	std::cout << "Game: " << GameTitle << "\n";
	std::cout << "Cartridge Type: " << cart_types[CartridgeType] << "\n";
	std::cout << "ROM Size: " << rom_sizes[ROMSize] << "\n";
	std::cout << "RAM Size: " << ram_sizes[RAMSize] << "\n";
	std::cout << "Destination: " << dest_codes[DestCode] << "\n";
}

void Cartridge::Insert(std::string filename)
{
	std::ifstream File(filename, std::ios::binary);
	// todo: error check

	// ROM buffer
	File.seekg(0, std::ios::end);
	int size = File.tellg();
	File.seekg(0, std::ios::beg);
	ROM = new u8[size];
	File.read((char*)ROM, size);
	File.close();

	SetInfo();

	Inserted = true;
}

void Cartridge::Remove()
{
	if (Inserted) {
		delete[] ROM;
	//	delete[] RAM;
		
		Inserted = false;
	}
}

u8 Cartridge::operator[](u16 addr)
{
	return ROM[addr];
}