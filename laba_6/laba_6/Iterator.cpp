#include "Iterator.h"

Iterator::Iterator() { elem = 0; }

void Iterator::operator--() { --elem; }
int& Iterator::operator *() const { return*elem; }
