#ifndef OXEIRA_INVARIANTS_H
#define OXEIRA_INVARIANTS_H

namespace oxeira
{

void invariant(bool, const char *, unsigned int, const char *);

};

#ifndef OXEIRA_INVARIANT
#define OXEIRA_INVARIANT(c) (oxeira::invariant((c), __FILE__, __LINE__, #c))
#endif

#endif // OXEIRA_INVARIANTS_H
