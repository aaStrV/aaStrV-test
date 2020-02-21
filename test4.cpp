#include "test4.h"
using namespace std;

namespace test4
{
TEST(minmaxTest, base)
{
	MinMaxPair p1(1);
	MinMaxPair p2(2);
	MinMaxPair p3(0xFFFFFFFF);
	ASSERT_EQ(0b10000000000000000000000000000000, p1.getMax());
	ASSERT_EQ(0b1, p1.getMin());

	ASSERT_EQ(0b10000000000000000000000000000000, p2.getMax());
	ASSERT_EQ(0b1, p2.getMin());

	ASSERT_EQ(0xFFFFFFFF, p3.getMax());
	ASSERT_EQ(0xFFFFFFFF, p3.getMin());
}
} // namespace test4
