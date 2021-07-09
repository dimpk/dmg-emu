#include <iostream>
#include <fstream>
#include "cartridge.h"

Cartridge::Cartridge()
{
	CartridgeType[0x00] = "ROM ONLY";
	CartridgeType[0x01] = "ROM+MBC1";
	CartridgeType[0x02] = "ROM+MBC1+RAM";
	CartridgeType[0x03] = "ROM+MBC1+RAM+BATTERY";
	CartridgeType[0x05] = "ROM+MBC2";
	CartridgeType[0x06] = "ROM+MBC2+BATTERY";
	CartridgeType[0x08] = "ROM+RAM";
	CartridgeType[0x09] = "ROM+RAM+BATTERY";
	CartridgeType[0x0B] = "ROM+MMM01";
	CartridgeType[0x0C] = "ROM+MMM01+SRAM";
	CartridgeType[0x0D] = "ROM+MMM01+SRAM+BATTERY";
	CartridgeType[0x0F] = "ROM+MBC3+TIMER+BATTERY";
	CartridgeType[0x10] = "ROM+MBC3+TIMER+RAM+BATTERY";
	CartridgeType[0x11] = "ROM+MBC3";
	CartridgeType[0x12] = "ROM+MBC3+RAM";
	CartridgeType[0x13] = "ROM+MBC3+RAM+BATTERY";
	CartridgeType[0x19] = "ROM+MBC5";
	CartridgeType[0x1A] = "ROM+MBC5+RAM";
	CartridgeType[0x1B] = "ROM+MBC5+RAM+BATTERY";
	CartridgeType[0x1C] = "ROM+MBC5+RUMBLE";
	CartridgeType[0x1D] = "ROM+MBC5+RUMBLE+SRAM";
	CartridgeType[0x1E] = "ROM+MBC5+RUMBLE+SRAM+BATTERY";
	CartridgeType[0x1F] = "Pocket Camera";
	CartridgeType[0xFD] = "Bandai TAMA5";
	CartridgeType[0xFE] = "Hudson HuC-3";
	CartridgeType[0xFF] = "Hudson HuC-1";

	ROMSize[0x00] = "32KB - 2 banks";
	ROMSize[0x01] = "64KB - 4 banks";
	ROMSize[0x02] = "128KB - 8 banks";
	ROMSize[0x03] = "256KB - 16 banks";
	ROMSize[0x04] = "512KB - 32 banks";
	ROMSize[0x05] = "1MB - 64 banks";
	ROMSize[0x06] = "2MB - 128 banks";
	ROMSize[0x07] = "4MB - 256 banks";
	ROMSize[0x08] = "8KB - 512 banks";

	RAMSize[0x00] = "None";
	RAMSize[0x01] = "2KB";
	RAMSize[0x02] = "8KB - 1 bank";
	RAMSize[0x03] = "32KB - 4 banks of 8KB";
	RAMSize[0x04] = "128KB - 16 banks of 8KB";
	RAMSize[0x05] = "64KB - 8 banks of 8KB";

	DestCode[0x00] = "Japan";
	DestCode[0x01] = "World";
}

void Cartridge::PrintInfo()
{
	// 0x134 - 0x143
	// Title of the game in UPPER CASE ASCII. 
	// If it is less than 16 characters then the remaining bytes 
	// are filled with $00 bytes.
	std::cout << "Game: ";
	for (int i = 0x134; i <= 0x143; i++) {
		if (ROM[i] == 0) {
			std::cout << std::endl;
			break;
		}
		std::cout << static_cast<char>(ROM[i]);
	}

	// 0x147 
	// Cartridge Type
	std::cout << "Cartridge Type: " << CartridgeType[ROM[0x147]] << "\n";

	// 0x148
	// ROM Size	
	std::cout << "ROM Size: " << ROMSize[ROM[0x148]] << "\n";

	// 0x149
	// RAM Size
	std::cout << "RAM Size: " << RAMSize[ROM[0x149]] << "\n";

	// 0x14A
	// Destination Code
	std::cout << "Destination: " << DestCode[ROM[0x14A]] << "\n";
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

	Inserted = true;

	PrintInfo();
}

void Cartridge::Remove()
{
	if (Inserted) {
		delete[] ROM;
	//	delete[] RAM;
		
		Inserted = false;
	}
}

u8& Cartridge::operator[](u16 addr)
{
	return ROM[addr];
}
	