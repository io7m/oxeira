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

#include <oxeira/format.h>
#include <oxeira/invariants.h>
#include <oxeira/preconditions.h>

namespace oxeira
{

unsigned int formatU32D(char *str, uint32_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint32_t quotient = x;
  unsigned int length = 1;

  /*
   * Determine the number of digits.
   */

  while (quotient > 9)
  {
    ++length;
    quotient /= 10;
  }

  OXEIRA_INVARIANT(length >= 1);

  /*
   * Render digits.
   */

  unsigned int index = length - 1;
  for (;;)
  {
    const char ch = '0' + (x % 10);
    str[index] = ch;
    x /= 10;

    if (index == 0)
    {
      break;
    }
    --index;
  }

  return length;
}

static constexpr const char HEX[] = "0123456789abcdef";

unsigned int formatU32X(char *str, uint32_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint32_t quotient = x;
  unsigned int length = 1;

  /*
   * Determine the number of digits.
   */

  while (quotient > 15)
  {
    ++length;
    quotient /= 16;
  }

  OXEIRA_INVARIANT(length >= 1);

  /*
   * Render digits.
   */

  unsigned int index = length - 1;
  for (;;)
  {
    const char ch = HEX[x & 15];
    str[index] = ch;
    x /= 16;

    if (index == 0)
    {
      break;
    }
    --index;
  }

  return length;
}

unsigned int formatU32O(char *str, uint32_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint32_t quotient = x;
  unsigned int length = 1;

  /*
   * Determine the number of digits.
   */

  while (quotient > 7)
  {
    ++length;
    quotient /= 8;
  }

  OXEIRA_INVARIANT(length >= 1);

  /*
   * Render digits.
   */

  unsigned int index = length - 1;
  for (;;)
  {
    const char ch = '0' + (x % 8);
    str[index] = ch;
    x /= 8;

    if (index == 0)
    {
      break;
    }
    --index;
  }

  return length;
}

unsigned int formatU32B(char *str, uint32_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint32_t quotient = x;
  unsigned int length = 1;

  /*
   * Determine the number of digits.
   */

  while (quotient > 1)
  {
    ++length;
    quotient /= 2;
  }

  OXEIRA_INVARIANT(length >= 1);

  /*
   * Render digits.
   */

  unsigned int index = length - 1;
  for (;;)
  {
    const char ch = '0' + (x % 2);
    str[index] = ch;
    x /= 2;

    if (index == 0)
    {
      break;
    }
    --index;
  }

  return length;
}

}; // namespace oxeira
