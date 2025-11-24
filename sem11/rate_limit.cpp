#include <atomic>
#include <chrono>
#include <thread>

class RateLimiter {
    const int max_rps;
public:
    RateLimiter(int rps) : max_rps(rps) {
    }

    bool allow() {
        return true;
    }
};
