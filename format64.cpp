#include <oxeira/format.h>
#include <oxeira/invariants.h>
#include <oxeira/preconditions.h>

namespace oxeira
{

unsigned int formatU64D(char *str, uint64_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint64_t quotient = x;
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

unsigned int formatU64X(char *str, uint64_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint64_t quotient = x;
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

  for (unsigned int index = length - 1; index >= 0; --index)
  {
    char ch = '0' + (x & 15);
    if (ch > '0' + 9)
    {
      ch += 'a' - '0' - 10;
    }

    str[index] = ch;
    x /= 16;
  }

  return length;
}

unsigned int formatU64O(char *str, uint64_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint64_t quotient = x;
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

  for (unsigned int index = length - 1; index >= 0; --index)
  {
    const char ch = '0' + (x % 8);
    str[index] = ch;
    x /= 8;
  }

  return length;
}

unsigned int formatU64B(char *str, uint64_t x)
{
  OXEIRA_PRECONDITION(str != nullptr);

  uint64_t quotient = x;
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

  for (unsigned int index = length - 1; index >= 0; --index)
  {
    const char ch = '0' + (x % 2);
    str[index] = ch;
    x /= 2;
  }

  return length;
}

}; // namespace oxeira
