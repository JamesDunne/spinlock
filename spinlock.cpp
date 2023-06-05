
#ifdef __WIN32__
#include <windows.h>
#endif

#include "spinlock.h"

void spinlock::lock() noexcept {
    while (locked.test_and_set(std::memory_order_acquire)) {
#ifdef __WIN32__
        // we only want to pause the CPU core here to save power; we do not want to yield our thread to the scheduler
        YieldProcessor();
#endif
    }
}

void spinlock::unlock() noexcept {
    locked.clear(std::memory_order_release);
}
