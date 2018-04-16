#include <vector>
#include <thread>
#include <cstdio>

#include "sem.h"
#include "sem_main.h"

void print(void *p)
{
    puts((char*)p);
}

void lock(std::shared_ptr<CountSem> sem)
{
    sem->increment( &print, "Locking---" );
}

void unlock(std::shared_ptr<CountSem> sem)
{
    sem->decrement( &print, "---Unlocking" );
}

auto main() -> int {
    std::shared_ptr<CountSem> sem ( new CountSem() );
    std::vector<std::thread> threads;
    for (int i = 0; i < 80000; ++i)
    {
        threads.push_back(std::thread(lock, sem));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    printf("Counter value: %d\n", sem->getCounter());

    threads.clear();
    for (int i = 0; i < 70000; ++i)
    {
        threads.push_back(std::thread(unlock, sem));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    printf("Counter value: %d\n", sem->getCounter());
}