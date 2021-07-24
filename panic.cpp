#include <oxeira/panic.h>

#include <stdlib.h>

namespace oxeira
{

static void panicCallbackDefault(const char *file, unsigned int line,
                                 const char *message)
{
  abort();
}

static PanicCallbackT panicCallback = panicCallbackDefault;

void panicSet(PanicCallbackT callback)
{
  panicCallback = callback;
}

void panic(const char *file, unsigned int line, const char *message)
{
  panicCallback(file, line, message);
}
}; // namespace oxeira
