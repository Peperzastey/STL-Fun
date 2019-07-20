#include <iostream>
#include <array>
#include "sleepSort.hpp"

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
