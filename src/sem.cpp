#include "sem.h"

void CountSem::increment() 
{
    this->counter++;
}

void CountSem::decrement()
{
    this->counter--;
}