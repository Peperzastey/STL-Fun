#ifndef SLEEP_SORT_HPP__
#define SLEEP_SORT_HPP__

#include <iterator>
#include <thread>
#include <chrono>
#include <mutex>
#include <functional>

template <typename InputIt>
auto sleepSorted(InputIt first, InputIt last) {
    using ValueT = typename std::iterator_traits<InputIt>::value_type;
    
    std::mutex writeLock;
    std::vector<ValueT> result;
    std::vector<std::thread> threads;
    
    for (; first != last; first = std::next(first)) {
        threads.emplace_back(
            [&writeLock, &result](auto&& elem) { 
                std::this_thread::sleep_for(std::chrono::milliseconds{elem * 10}); // elem is l-value
                std::lock_guard<std::mutex> lock{writeLock};
                result.push_back(std::forward<decltype(elem)>(elem));
            },
            std::cref(*first) // dereferencing of move_iterator returns r-value
        );
    }
    
    for (auto&& thread : threads)
        thread.join();
    
    return result;
}

#endif // SLEEP_SORT_HPP__
