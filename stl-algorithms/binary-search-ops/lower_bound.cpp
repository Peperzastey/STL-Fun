#include <algorithm>
#include <vector>
#include <gtest/gtest.h>

namespace {
//TODO move to common header file
class BinarySearchOpsTest : public testing::Test {
protected:
	using ElemT = int;

protected:
	std::vector<ElemT> _sortedVec = {0, 1, 2, 3, 4, 5};
	std::vector<ElemT> _sortedVecWithDuplicates = {0, 0, 1, 2, 3, 3, 3, 4, 4, 5, 5};
};

TEST_F(BinarySearchOpsTest, LowerBoundReturnsIterToElemWhenFound) {
	constexpr ElemT VAL = 4;
	auto iter = std::lower_bound(_sortedVec.cbegin(), _sortedVec.cend(), VAL);
	EXPECT_EQ(*iter, VAL);
}

} // namespace
