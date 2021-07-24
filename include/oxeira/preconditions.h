#ifndef OXEIRA_PRECONDITIONS_H
#define OXEIRA_PRECONDITIONS_H

namespace oxeira
{

void precondition(bool, const char *, unsigned int, const char *);

};

#ifndef OXEIRA_PRECONDITION
#define OXEIRA_PRECONDITION(c)                                                 \
  (oxeira::precondition((c), __FILE__, __LINE__, #c))
#endif

#endif // OXEIRA_PRECONDITIONS_H
