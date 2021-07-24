#include <oxeira/panic.h>
#include <oxeira/preconditions.h>

namespace oxeira
{

void precondition(bool condition, const char *file, unsigned int line,
                  const char *message)
{
  if (!condition)
  {
    panic(file, line, message);
  }
}

}; // namespace oxeira
