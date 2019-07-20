#include <iostream>
#include <vector>
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
            [&writeLock, &result](const ValueT &elem) { 
                std::this_thread::sleep_for(std::chrono::milliseconds{elem * 10});
                std::lock_guard<std::mutex> lock{writeLock};
                result.push_back(elem);
            },
            std::cref(*first)
        );
    }
    
    for (auto&& thread : threads)
        thread.join();
    
    return result;
}

int main()
{
    {
        std::array testArray{1u, 3u, 0u, 2u, 3u, 1u};
        auto sorted = sleepSorted(testArray.cbegin(), testArray.cend());
        for (const auto &elem : sorted) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
    {
        using ElemT = unsigned int;
        ElemT testArray[]{1, 3, 0, 2, 3, 1};
        auto sorted = sleepSorted(testArray, testArray + sizeof testArray/sizeof(ElemT));
        for (const auto &elem : sorted) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
