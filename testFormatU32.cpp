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
#include <stdio.h>

static const uint32_t numbers[] = {
    0,          1,          10,         20,         0xffffffff,

    2367313368, 40784078,   4290701461, 3317241771, 2318954094, 392365314,
    3434686079, 3434512464, 4226357965, 1967698495, 4227727137, 2587349315,
    1362153535, 858548680,  2555593270, 357852426,  1502229744, 1958943142,
    1714125112, 2214885868, 1375742722, 282950270,  1636467289, 2340118142,
    1742548308, 2230807906, 1682332335, 2409156057, 3863156465, 2950656112,
    669164801,  543180556,  3035558458, 1725484460, 3902250437, 3267334537,
    295718532,  2796304284, 255220061,  3682684397, 432569536,  2435142442,
    267160244,  373125860,  30610864,   1753226034, 3707887916, 1745205376,
    3549246000, 2760671354, 3882804252, 1095194936, 982758364,  4193840718,
    2138384787, 2895522798, 1545698883, 1136078579, 1008092260, 1562782500,
    3706494155, 3561396473, 1995270567, 3700284796, 756679667,  3323650730,
    3197230450, 2183144851, 7259515,    1736884597, 3259796337, 4035698721,
    3699833220, 480912698,  1877717242, 233550590,  1069923596, 3901892924,
    2656682243, 1660647823, 2966448110, 1376493110, 1613373695, 3741848743,
    811225927,  146496417,  1650694021, 1101084491, 1950971507, 162364788,
    548425100,  68516746,   2617192187, 3102018850, 566328474,  2585340317,
    3589722922, 3361469664, 2406013565, 2591978157};

static constexpr unsigned int numbersCount =
    sizeof(numbers) / sizeof(numbers[0]);

static void run(void)
{
  printf("testFormatU32\n");
  printf("--\n");

  char buffer[oxeira::formatU32Size] = {0};
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU32D(buffer, numbers[index])] = 0;
    printf("%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU32X(buffer, numbers[index])] = 0;
    printf("0x%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU32O(buffer, numbers[index])] = 0;
    printf("0o%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU32B(buffer, numbers[index])] = 0;
    printf("0b%s\n", buffer);
  }
}

extern "C"
{
  int main(void)
  {
    run();
    return 0;
  }
};
