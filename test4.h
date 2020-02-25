#ifndef TEST4_H_
#define TEST4_H_

#include <iostream>
#include <gtest.h>

namespace test4 {
class MinMaxPair {
  uint32_t max;
  uint32_t min;

 public:
  MinMaxPair(uint32_t val) {
    max = 0;
    uint32_t v = val;
    min = (v & 0x1);
    max = (v & 0x1) << 31;
    for (int i = 0; i < 31; ++i) {
      v = v >> 1;
      if (v & 0x1) {
        min = min << 1;
        max = max >> 1;
        min |= 0x1;
        max |= 0x1 << 31;
      }
    }
  }
  uint32_t getMax(void) {
    return max;
  }
  uint32_t getMin(void) {
    return min;
  }
};
}  // namespace test4

#endif /* TEST4_H_ */
