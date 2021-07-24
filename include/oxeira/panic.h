#ifndef OXEIRA_PANIC_H
#define OXEIRA_PANIC_H

namespace oxeira
{

typedef void (*PanicCallbackT)(const char *, unsigned int, const char *);

void panicSet(PanicCallbackT);
void panic(const char *file, unsigned int line, const char *message);

}; // namespace oxeira

#endif
