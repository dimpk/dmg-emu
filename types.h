#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;

union RegPair {
	struct {
		u8 L;
		u8 H;			
	};
	u16 pair;
};

#endif