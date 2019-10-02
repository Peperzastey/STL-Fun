#include "sleepSort.hpp"
#include <array>
#include <iostream>

//TODO use gtest
int main()
{
    {
        // NOLINTNEXTLINE(readability-uppercase-literal-suffix)
        std::array testArray{1u, 3u, 0u, 2u, 3u, 1u};
        auto sorted = sleepSorted(testArray.cbegin(), testArray.cend());
        for (const auto &elem : sorted) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
    {
        using ElemT = unsigned int;
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-c-arrays, modernize-avoid-c-arrays)
        ElemT testArray[]{1, 3, 0, 2, 3, 1};
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay, cppcoreguidelines-pro-bounds-pointer-arithmetic)
        auto sorted = sleepSorted(testArray, testArray + sizeof testArray/sizeof(ElemT));
        for (const auto &elem : sorted) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
