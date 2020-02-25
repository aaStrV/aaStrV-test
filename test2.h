#ifndef TEST2_H_
#define TEST2_H_

#include <gtest.h>
#include <iostream>
#include <map>
#include <string>

namespace test2 {
bool isLetter(const wchar_t c);
void countWords(std::map<int, int> &m, std::string &s);
void printWords(std::map<int, int> &m);
}  // namespace test2

#endif /* TEST2_H_ */
