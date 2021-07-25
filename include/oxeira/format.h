#ifndef OXEIRA_FORMAT_H
#define OXEIRA_FORMAT_H

/*
 * Copyright © 2021 Mark Raynsford <code@io7m.com> https://www.io7m.com
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdint.h>

namespace oxeira
{
/// The maximum number of bytes required to format a 64-bit number in base-16,
/// plus a null terminator
constexpr unsigned int formatU64SizeBase16 = 16 + 1;

/// The maximum number of bytes required to format a 32-bit number in base-16,
/// plus a null terminator
constexpr unsigned int formatU32SizeBase16 = 8 + 1;

/// The maximum number of bytes required to format a 16-bit number in base-16,
/// plus a null terminator
constexpr unsigned int formatU16SizeBase16 = 4 + 1;

/// The maximum number of bytes required to format an 8-bit number in base-16,
/// plus a null terminator
constexpr unsigned int formatU8SizeBase16 = 2 + 1;

/// The maximum number of bytes required to format a 64-bit number in base-10,
/// plus a null terminator
constexpr unsigned int formatU64SizeBase10 = 20 + 1;

/// The maximum number of bytes required to format a 32-bit number in base-10,
/// plus a null terminator
constexpr unsigned int formatU32SizeBase10 = 10 + 1;

/// The maximum number of bytes required to format a 16-bit number in base-10,
/// plus a null terminator
constexpr unsigned int formatU16SizeBase10 = 5 + 1;

/// The maximum number of bytes required to format an 8-bit number in base-10,
/// plus a null terminator
constexpr unsigned int formatU8SizeBase10 = 3 + 1;

/// The maximum number of bytes required to format a 64-bit number in base-8,
/// plus a null terminator
constexpr unsigned int formatU64SizeBase8 = 23 + 1;

/// The maximum number of bytes required to format a 32-bit number in base-8,
/// plus a null terminator
constexpr unsigned int formatU32SizeBase8 = 12 + 1;

/// The maximum number of bytes required to format a 16-bit number in base-8,
/// plus a null terminator
constexpr unsigned int formatU16SizeBase8 = 7 + 1;

/// The maximum number of bytes required to format an 8-bit number in base-8,
/// plus a null terminator
constexpr unsigned int formatU8SizeBase8 = 4 + 1;

/// The maximum number of bytes required to format a 64-bit number in base-2,
/// plus a null terminator
constexpr unsigned int formatU64SizeBase2 = 64 + 1;

/// The maximum number of bytes required to format a 32-bit number in base-2,
/// plus a null terminator
constexpr unsigned int formatU32SizeBase2 = 32 + 1;

/// The maximum number of bytes required to format a 16-bit number in base-2,
/// plus a null terminator
constexpr unsigned int formatU16SizeBase2 = 16 + 1;

/// The maximum number of bytes required to format an 8-bit number in base-2,
/// plus a null terminator
constexpr unsigned int formatU8SizeBase2 = 8 + 1;

/// The maximum number of bytes required to format a 64-bit number in any base,
/// plus a null terminator
constexpr unsigned int formatU64Size = formatU64SizeBase2;

/// The maximum number of bytes required to format a 32-bit number in any base,
/// plus a null terminator
constexpr unsigned int formatU32Size = formatU32SizeBase2;

/// The maximum number of bytes required to format a 16-bit number in any base,
/// plus a null terminator
constexpr unsigned int formatU16Size = formatU16SizeBase2;

/// The maximum number of bytes required to format a 8-bit number in any base,
/// plus a null terminator
constexpr unsigned int formatU8Size = formatU8SizeBase2;

///
/// Format a 64-bit value in base-10.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU64D(char *str, uint64_t x);

///
/// Format a 64-bit value in base-16.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU64X(char *str, uint64_t x);

///
/// Format a 64-bit value in base-8.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU64O(char *str, uint64_t x);

///
/// Format a 64-bit value in base-2.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU64B(char *str, uint64_t x);

///
/// Format a 32-bit value in base-10.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU32D(char *str, uint32_t x);

///
/// Format a 32-bit value in base-16.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU32X(char *str, uint32_t x);

///
/// Format a 32-bit value in base-8.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU32O(char *str, uint32_t x);

///
/// Format a 32-bit value in base-2.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU32B(char *str, uint32_t x);

///
/// Format a 16-bit value in base-10.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU16D(char *str, uint16_t x);

///
/// Format a 16-bit value in base-16.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU16X(char *str, uint16_t x);

///
/// Format a 16-bit value in base-8.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU16O(char *str, uint16_t x);

///
/// Format a 16-bit value in base-2.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU16B(char *str, uint16_t x);

///
/// Format a 8-bit value in base-10.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU8D(char *str, uint8_t x);

///
/// Format a 8-bit value in base-8.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU8X(char *str, uint8_t x);

///
/// Format a 8-bit value in base-8.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU8O(char *str, uint8_t x);

///
/// Format a 8-bit value in base-2.
/// @param[str] The output string
/// @param[x] The input value
/// @return The number of characters written
///

unsigned int formatU8B(char *str, uint8_t x);

}; // namespace oxeira

#endif // OXEIRA_FORMAT_H
