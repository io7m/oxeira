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

static const uint64_t u64s[] = {0ULL,
                                1ULL,
                                10ULL,
                                20ULL,
                                0xffffffffFFFFFFFFULL,
                                5485181283954110000ULL,
                                3266127300946518000ULL,
                                15560377400160367000ULL,
                                14420795447640490000ULL,
                                16599595947835245000ULL,
                                18333115156218565000ULL,
                                4194817669833912300ULL,
                                7343904181302157000ULL,
                                1437108869261734000ULL,
                                12050036385214636000ULL,
                                4830862282196529000ULL,
                                17207448523019416000ULL,
                                6927869673745814000ULL,
                                3601125847004705000ULL,
                                13493816540269339000ULL,
                                777780183627489300ULL,
                                6706285880238531000ULL,
                                17125117310830301000ULL,
                                15685898348923920000ULL,
                                5115962061741621000ULL,
                                16802111065967837000ULL,
                                13625033621986480000ULL,
                                4349147239663808500ULL,
                                17179278107330360000ULL,
                                3644673018880188400ULL,
                                13652982247162118000ULL,
                                13544958834126143000ULL,
                                13157856761001935000ULL,
                                15052864674554446000ULL,
                                3075487472642511000ULL,
                                3142208398904688600ULL,
                                2817183868661883000ULL,
                                17654548807301919000ULL,
                                4852322190899311000ULL,
                                10503046033552270000ULL,
                                4257362459873833000ULL,
                                18358430831586144000ULL,
                                11825179241547571000ULL,
                                2092086525540692000ULL,
                                8468253463497318000ULL,
                                9699505986769560000ULL,
                                18390707720620020000ULL,
                                12042005810673312000ULL,
                                2783992888463069000ULL,
                                2219165370671255600ULL,
                                16859376596416967000ULL,
                                11331627744394588000ULL,
                                6960782376265810000ULL,
                                9986737049932915000ULL,
                                11299553038019220000ULL,
                                16306883923550806000ULL,
                                15267343192006943000ULL,
                                3930708635376288000ULL,
                                7480850724034699000ULL,
                                14799125624458908000ULL,
                                2285891093232595000ULL,
                                11426107148342362000ULL,
                                4947491621404688000ULL,
                                1582006128847392800ULL,
                                8557908998905381000ULL,
                                7512588066258338000ULL,
                                16084193640042414000ULL,
                                3336211825495044000ULL,
                                10038679751728026000ULL,
                                13374606840252015000ULL,
                                7276762794077360000ULL,
                                5484456962555904ULL,
                                10612733309260760000ULL,
                                13272979509965566000ULL,
                                15560455025797886000ULL,
                                17550695569170940000ULL,
                                14615995560474378000ULL,
                                3717437253564035000ULL,
                                3485976013320487000ULL,
                                18055274846403613000ULL,
                                1612655993862582300ULL,
                                13016965777039139000ULL,
                                6757473793202196000ULL,
                                6719646528387129000ULL,
                                5931989456690971000ULL,
                                6678124940771963000ULL,
                                2203469923882287000ULL,
                                6830386095868445000ULL,
                                11089190971884319000ULL,
                                15519067101512753000ULL,
                                7640546251457016000ULL,
                                4224346767447924700ULL,
                                6464943110951371000ULL,
                                12661174283716514000ULL,
                                13035608086334337000ULL,
                                2273382647665586200ULL,
                                5450333707828113000ULL,
                                7154332912226525000ULL,
                                5510325617919812000ULL,
                                1046531640939368400ULL,
                                17338573139092849000ULL,
                                15638812622501028000ULL,
                                11114723163281584000ULL,
                                546738148134576100ULL,
                                16956977848790483000ULL};

static void run(void)
{
  printf("testFormat64\n");
  printf("--\n");

  char buffer[oxeira::formatU64Size] = {0};

  for (unsigned int index = 0; index < sizeof(u64s) / sizeof(uint64_t); ++index)
  {
    buffer[oxeira::formatU64D(buffer, u64s[index])] = 0;
    printf("%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < sizeof(u64s) / sizeof(uint64_t); ++index)
  {
    buffer[oxeira::formatU64X(buffer, u64s[index])] = 0;
    printf("0x%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < sizeof(u64s) / sizeof(uint64_t); ++index)
  {
    buffer[oxeira::formatU64O(buffer, u64s[index])] = 0;
    printf("0o%s\n", buffer);
  }

  printf("--\n");
  for (unsigned int index = 0; index < sizeof(u64s) / sizeof(uint64_t); ++index)
  {
    buffer[oxeira::formatU64B(buffer, u64s[index])] = 0;
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
