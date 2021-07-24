#include <oxeira/invariants.h>
#include <oxeira/panic.h>

namespace oxeira
{

void invariant(bool condition, const char *file, unsigned int line,
               const char *message)
{
  if (!condition)
  {
    panic(file, line, message);
  }
}

}; // namespace oxeira
