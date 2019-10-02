#include <algorithm>
#include <functional> // std::greater
#include <iterator> // std::make_reverse_iterator
#include <list>
#include <memory> // std::addressof
#include <gtest/gtest.h>

namespace {

// underlying base iterator for reverse_iterator must be at least Bidirectional Iterator
TEST(LinearSearchOpsAdjacentFind, WorksForReverseIteratorCreatedFromBidirIterator) {
    std::list testInput {1, 2, 3, 5, 5, 4, 3, 2, 1};
    auto rbegin = std::make_reverse_iterator(testInput.cend());
    auto rend = std::make_reverse_iterator(testInput.cbegin());
    ASSERT_EQ(testInput.crbegin(), rbegin); //TODO test with rbegin() (without const)
    ASSERT_EQ(testInput.crend(), rend); //TODO test with rend() (without const)
    
    auto rfound = std::adjacent_find(rbegin, rend, std::greater{});
    
    auto rexpectedIt = std::next(testInput.crbegin(), 5); //TODO test with rbegin() (without const)
    ASSERT_NE(rend, rfound); // found such element
    EXPECT_EQ(rexpectedIt, rfound); // iterators match
    EXPECT_EQ(*rexpectedIt, *rfound); // elements pointed to by iterators match
    EXPECT_EQ(5, *rfound);
    EXPECT_EQ(std::addressof(*rexpectedIt), std::addressof(*rfound)); // iterators point to the same element
    ASSERT_NE(rend, std::next(rfound));
    EXPECT_EQ(3, *std::next(rfound));
}

} // namespace
