#ifndef OXEIRA_PANIC_H
#define OXEIRA_PANIC_H

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
/// The type of panic callbacks. The function receives a file, a source line,
/// and a message.
///

typedef void (*PanicCallbackT)(const char *file, unsigned int line,
                               const char *message);

///
/// Set the global panic callback that will be executed when {@link panic} is
/// called.
///
/// @param[callback] The callback that will be called before aborting
///

void panicSet(PanicCallbackT callback);

///
/// Call the global panic callback. The function terminates the
/// program.
///
/// @param[file] The file calling this function
/// @param[line] The line of code calling this function
/// @param[message] The termination reason
///

[[noreturn]] void panic(const char *file, unsigned int line,
                        const char *message);

}; // namespace oxeira

#endif
