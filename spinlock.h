
#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <atomic>

// use like `std::lock_guard<spinlock> lk(spinlock_instance);`
class spinlock {
    std::atomic_flag locked = ATOMIC_FLAG_INIT;

public:
    void lock() noexcept;

    void unlock() noexcept;
};

#endif //SPINLOCK_H
