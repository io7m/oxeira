#ifndef OXEIRA_PRECONDITIONS_H
#define OXEIRA_PRECONDITIONS_H

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

namespace oxeira
{

///
/// Check the given precondition, calling {@link panic} if the condition is
/// false. This function can be called, conveniently, via the
/// OXEIRA_PRECONDITION macro.
///
/// @param[condition] The condition
/// @param[file] The source file (typically __FILE__)
/// @param[line] The source line (typically __LINE__)
/// @param[message] The condition as a string
///

void preconditionCheck(bool condition, const char *file, unsigned int line,
                       const char *message);

}; // namespace oxeira

///
/// A macro that calls {@link oxeira::preconditionCheck}.
///

#ifndef OXEIRA_PRECONDITION
#define OXEIRA_PRECONDITION(c)                                                 \
  (oxeira::preconditionCheck((c), __FILE__, __LINE__, #c))
#endif

#endif // OXEIRA_PRECONDITIONS_H
