#ifndef SEM__
#define SEM__

#include <atomic>

class CountSem {
public:
    void increment(void (*)(void*), void*);
    void decrement(void (*)(void*), void*);    
    long getCounter();

private:
    std::atomic<long> counter = {0};
};

#endif // !SEM__
