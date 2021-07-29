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

#include <oxeira/boundedArray.h>
#include <stdio.h>

static void run(void)
{
  printf("testBoundedArray0\n");
  printf("--\n");

  oxeira::BoundedArray<int, 10> x(0);
  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, x.get(index));
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    x.set(index, 100);
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, x.get(index));
    int &ref = x.get(index);
    ref = 23;
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, x.get(index));
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, x.get(index));
    int &ref = x.get(index);
    ref = 24;
  }

  const oxeira::BoundedArray<int, 10> &xr = x;
  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, xr.get(index));
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, x.get(index));
    int &ref = x.get(index);
    ref = 25;
  }

  for (std::size_t index = 0; index < x.elementCount(); ++index)
  {
    printf("[%lu] %d\n", index, xr.get(index));
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
