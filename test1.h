#ifndef TEST1_H_
#define TEST1_H_

#include <iostream>
#include <gtest.h>

namespace test1 {
bool isPrime(int num);
void printPrimes(int n);

class prime_gen_f : public std::unary_function<int, bool> {
  int last;

 public:
  prime_gen_f(void)
      :
      last(0) {
  }
  int operator()(void) {
    while (true) {
      last += 1;
      if (isPrime(last)) {
        return last;
      }
    }
  }
};
}  // namespace test1

#endif /* TEST1_H_ */
