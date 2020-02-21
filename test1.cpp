#include "test1.h"
using namespace std;

namespace test1
{
bool isPrime(int num)
{
	return num == 0 ? false : num == 1 ? true : num == 2 ? true : [](int num) -> bool {
		for (int i = 2; i < num; ++i)
			if ((num % i) == 0)
				return false;
		return true;
	}(num);
}

void printPrimes(int n)
{
	cout << n << " primes: ";
	prime_gen_f prime_gen;
	for (int i = 0; i < n; ++i)
	{
		cout << prime_gen() << " ";
	}
	cout << endl;
}

TEST(isPrimeTest, base)
{
	ASSERT_EQ(false, isPrime(0));
	ASSERT_EQ(true, isPrime(1));
	ASSERT_EQ(true, isPrime(2));
	ASSERT_EQ(false, isPrime(4));
	ASSERT_EQ(false, isPrime(222226));
}

TEST(writeNPrimesTest, base)
{
	ASSERT_NO_THROW(printPrimes(2000));
	ASSERT_NO_FATAL_FAILURE(printPrimes(2000));
	ASSERT_NO_THROW(printPrimes(0));
	ASSERT_NO_FATAL_FAILURE(printPrimes(0));
	ASSERT_NO_THROW(printPrimes(-1));
	ASSERT_NO_FATAL_FAILURE(printPrimes(-1));
}
} // namespace test1
