#include <cstdio>

#include "sem.h"

void CountSem::increment(void (*fun)(void*), void *param) 
{
    this->counter++;
    if (this->counter == 1)
    {
        fun(param);
    }
}

void CountSem::decrement(void (*fun)(void*), void *param)
{
    this->counter--;    
    if (this->counter == 0)
    {
        fun(param);
    }
}

long CountSem::getCounter()
{
    return this->counter.load();
}