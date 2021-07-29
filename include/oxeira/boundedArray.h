#ifndef OXEIRA_BOUNDEDARRAY_H
#define OXEIRA_BOUNDEDARRAY_H

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

#include <cstdint>
#include <cstring>
#include <oxeira/preconditions.h>

namespace oxeira
{

///
/// A very simple bounded array type that must contain at least one element.
/// @param[T] The type of elements
/// @param[N] The number of elements in the array
///

template <typename T, std::size_t N> struct BoundedArray
{
  static_assert(N > 0, "Must specify a non-zero size array");
  static_assert(sizeof(T) > 0, "Must specify a type of a non-zero size");

  ///
  /// Construct a new array, initializing every element to `identity`.
  /// @param[identity] The value to which to initialize all elements of the
  /// array
  ///

  explicit BoundedArray(T identity) : dataElements(N)
  {
    for (std::size_t index = 0; index < N; ++index)
    {
      data[index] = identity;
    }
  }

  virtual ~BoundedArray() = default;
  BoundedArray(const BoundedArray &) = delete;
  BoundedArray &operator=(BoundedArray const &) = delete;
  BoundedArray(BoundedArray &&) = delete;
  BoundedArray &operator=(BoundedArray &&) = delete;

  ///
  /// @return The number of elements that can be held in the array
  ///

  constexpr std::size_t elementCount() const noexcept
  {
    return dataElements;
  }

  ///
  /// Set the element at `index` to `value`.
  /// @param[index] The element index
  /// @param[value] The element value
  ///

  void set(std::size_t index, const T value) noexcept
  {
    OXEIRA_PRECONDITION(index < dataElements);
    data[index] = value;
  }

  ///
  /// Return the element at `index`.
  /// @param[index] The element index
  ///

  T get(std::size_t index) const noexcept
  {
    OXEIRA_PRECONDITION(index < dataElements);
    return data[index];
  }

  ///
  /// Return a reference to the element at `index`.
  /// @param[index] The element index
  ///

  T &get(std::size_t index) noexcept
  {
    OXEIRA_PRECONDITION(index < dataElements);
    return data[index];
  }

  ///
  /// Return a reference to the element at `index`.
  /// @param[index] The element index
  ///

  const T &ge(std::size_t index) const noexcept
  {
    OXEIRA_PRECONDITION(index < dataElements);
    return data[index];
  }

private:
  std::size_t dataElements;
  T data[N];
};

}; // namespace oxeira

#endif // OXEIRA_BOUNDEDARRAY_H
