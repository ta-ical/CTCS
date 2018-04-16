#ifndef SEM__
#define SEM__

class CountSem {
public:
    virtual void increment() final;
    virtual void decrement() final;

private:
    long counter = 0;
};

#endif // !SEM__
