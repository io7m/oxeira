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
#include <oxeira/panic.h>
#include <stdio.h>

static void panic(const char *file, unsigned int line, const char *message)
{
  printf("PANIC: %s:%u: %s\n", file, line, message);
  fflush(stdout);
}

static void run(void)
{
  printf("testBoundedArray2\n");
  printf("--\n");

  oxeira::BoundedArray<int, 1> x(0);
  oxeira::panicSet(&panic);

  int &z = x.get(1);
  printf("z: %d\n", z);
}

extern "C"
{
  int main(void)
  {
    run();
    return 0;
  }
};
