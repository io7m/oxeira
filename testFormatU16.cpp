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

static const uint16_t numbers[] = {
    0,     1,     10,    20,    0xffff,

    38390, 53083, 30865, 41036, 17543,  41958, 49398, 28635, 45830, 11184,
    25530, 29262, 6421,  1885,  37287,  14278, 44621, 29161, 32103, 25968,
    37972, 9152,  59874, 38174, 17320,  2295,  28670, 64890, 9712,  33563,
    54267, 58898, 2101,  49942, 24895,  52192, 11412, 12766, 13533, 16138,
    10136, 51346, 39857, 60912, 28683,  60744, 51621, 57326, 2112,  42279,
    35331, 28157, 59292, 15512, 13396,  55956, 15362, 47264, 16967, 50952,
    5129,  49964, 41862, 62070, 51847,  62209, 3223,  57855, 10018, 57576,
    43964, 56968, 46854, 10164, 16183,  3977,  4370,  12733, 63035, 61360,
    18570, 47169, 28311, 50068, 16483,  30308, 18052, 4298,  12043, 4227,
    38357, 17218, 8150,  19374, 13861,  39086, 3538,  50070, 7665,  39274};

static constexpr unsigned int numbersCount =
    sizeof(numbers) / sizeof(numbers[0]);

static void run(void)
{
  printf("testFormatU16\n");
  printf("--\n");

  char buffer[oxeira::formatU32Size] = {0};

  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU16D(buffer, numbers[index])] = 0;
    printf("%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU16X(buffer, numbers[index])] = 0;
    printf("0x%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU16O(buffer, numbers[index])] = 0;
    printf("0o%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < numbersCount; ++index)
  {
    buffer[oxeira::formatU16B(buffer, numbers[index])] = 0;
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
