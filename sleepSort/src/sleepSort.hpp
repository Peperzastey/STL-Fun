#ifndef SLEEPSORT_HPP__
#define SLEEPSORT_HPP__

#include <chrono>
#include <functional>
#include <iterator>
#include <mutex>
#include <thread>
#include <vector>

// NOLINTNEXTLINE(readability-uppercase-literal-suffix)
constexpr auto SLEEP_TIME_MULTIPLIER = 10u;

template <typename InputIt>
auto sleepSorted(InputIt first, InputIt last) {
    using ValueT = typename std::iterator_traits<InputIt>::value_type;
    
    std::mutex writeLock;
    std::vector<ValueT> result;
    std::vector<std::thread> threads;
    
    for (; first != last; first = std::next(first)) {
        threads.emplace_back(
            [&writeLock, &result](auto&& elem) { 
                std::this_thread::sleep_for(std::chrono::milliseconds{elem * SLEEP_TIME_MULTIPLIER}); // elem is l-value
                std::lock_guard<std::mutex> lock{writeLock};
                result.push_back(std::forward<decltype(elem)>(elem));
            },
            std::cref(*first) // dereferencing of move_iterator returns r-value
        );
    }
    
    for (auto&& thread : threads) {
        thread.join();
    }
    
    return result;
}

#endif // SLEEPSORT_HPP__
