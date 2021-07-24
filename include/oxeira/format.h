#ifndef OXEIRA_FORMAT_H
#define OXEIRA_FORMAT_H

#include <stdint.h>

namespace oxeira
{
constexpr unsigned int formatU64Size = (sizeof(uint64_t) * 8) + 1;
constexpr unsigned int formatU32Size = (sizeof(uint32_t) * 8) + 1;
constexpr unsigned int formatU16Size = (sizeof(uint16_t) * 8) + 1;
constexpr unsigned int formatU8Size = (sizeof(uint8_t) * 8) + 1;

unsigned int formatU64D(char *, uint64_t);
unsigned int formatU64X(char *, uint64_t);
unsigned int formatU64O(char *, uint64_t);
unsigned int formatU64B(char *, uint64_t);

unsigned int formatU32D(char *, uint32_t);
unsigned int formatU32X(char *, uint32_t);
unsigned int formatU32O(char *, uint32_t);
unsigned int formatU32B(char *, uint32_t);

unsigned int formatU16D(char *, uint16_t);
unsigned int formatU16X(char *, uint16_t);
unsigned int formatU16O(char *, uint16_t);
unsigned int formatU16B(char *, uint16_t);

unsigned int formatU8D(char *, uint8_t);
unsigned int formatU8X(char *, uint8_t);
unsigned int formatU8O(char *, uint8_t);
unsigned int formatU8B(char *, uint8_t);

}; // namespace oxeira

#endif // OXEIRA_FORMAT_H
