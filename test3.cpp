#include "test3.h"
using namespace std;

namespace test3
{
TEST(listTest, base)
{
	List<int> l;
	for (int i = 0; i < 20000; ++i)
		l.cons(i);
	ASSERT_EQ(20000, l.size());
	ASSERT_EQ(19999, l.head());

	auto inc = [](int *arg) {
		*arg += 1;
	};
	l.map(inc);
	ASSERT_EQ(20000, l.head());

	List<string> ls;
	for (int i = 0; i < 20000; ++i)
		ls.cons("sefs");
	ASSERT_EQ(20000, ls.size());
}
} // namespace test3
