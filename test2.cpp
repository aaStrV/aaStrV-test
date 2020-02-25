#include "test2.h"
using namespace std;

namespace test2 {
bool isLetter(char c);
bool isLetter(char c) {
  return c >= 'a' && c <= 'z' ? true : c >= 'A' && c <= 'Z' ? true : false;
}

void countWords(map<int, int> &m, string &s) {
  string::iterator i_str, end;
  int len_count = 0;
  for (i_str = s.begin(), end = s.end(); i_str != end; ++i_str) {
    if (isLetter(*i_str)) {
      len_count += 1;
    } else {
      m[len_count] += 1;
      len_count = 0;
    }
  }
  m.erase(0);
}

void printWords(map<int, int> &m) {
  for (auto i : m) {
    cout << "Len: " << i.first << ", number = " << i.second << endl;
  }
}

TEST(countWords, base) {
  map<int, int> m;
  string s1 = "";
  string s2 = "жшгрфсгф\0\a\n\r\"";
  string s3 = "жшpifagorсгф\0\a\n\r\"";
  countWords(m, s1);
  ASSERT_TRUE(m.empty());
  countWords(m, s2);
  ASSERT_TRUE(m.empty());
  countWords(m, s3);
  ASSERT_EQ(1, m[7]);
  ASSERT_EQ(m[0], 0);
}
}  // namespace test2
