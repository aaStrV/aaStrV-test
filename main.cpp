#include <iostream>
#include <gtest.h>
#include <string>
#include <vector>
#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "test4.h"
#include "test5.h"
using namespace std;
using namespace test1;
using namespace test2;
using namespace test3;
using namespace test4;
using namespace test5;

int main(int argc, char **argv) {
  cout << "Test 1: Writing first N primes" << endl;
  printPrimes(7);

  cout << endl;
  cout << "Test 2: Number of words" << endl;
  map<int, int> m;
  string s("[----------] 1 test from ,write,NP,rimesTest (2 ms total)");
  cout << "Test string: \"" << s << "\"" << endl;
  countWords(m, s);
  printWords(m);

  cout << endl;
  cout << "Test 3: Drop each fifth element in list" << endl;
  List<int> l;
  for (int i = 30; i > 0; --i) {
    l.cons(i);
  }
  auto printList = [](int *arg) {
    cout << *arg << " ";
  };
  l.map(printList);
  cout << endl;
  dropEvery5th(l);
  l.map(printList);
  cout << endl;

  cout << endl;
  cout << "Test 4: Write a function that takes a 32-bit unsigned integer "
       << endl << "number and returns the maximum and minimum 32-bit " << endl
       << "unsigned integer numbers which can be obtained using " << endl
       << "the same number of bits set to 1 as in the taken number" << endl;
  int32_t a = 255 - 1 + 256;
  MinMaxPair p1(a);
  int32_t max = p1.getMax();
  int32_t min = p1.getMin();
  cout << hex << "a = " << a << endl;
  cout << "min = " << min << endl;
  cout << "max = " << max << endl << dec << endl;

  cout << "Test 5: " << endl;
  /**
   * 											                      level
   * 	n0-----\									                  1
   * 	n1-\	  n2-----------------\				        2
   * 	n3	0	  n4---------\		    n5-\			      3
   * 	00		  n6-----\	  0		    n7	n10----\	  4
   * 			    n8-\	  0			      00	n11-\	  0	  5
   * 			    0	  n9					        n12	 0		  6
   * 				      00					        00
   *
   *	n0	n1	n3	n2	n4	n6	n8 	n9	n5	n7
   */
  TreeNode n12 = { 12 };
  TreeNode n11 = { 11, &n12, nullptr };
  TreeNode n10 = { 10, &n11, nullptr };
  TreeNode n9 = { 9 };
  TreeNode n8 = { 8, nullptr, &n9 };
  TreeNode n7 = { 7 }, n6 = { 6, &n8, nullptr };
  TreeNode n5 = { 5, &n7, &n10 }, n4 = { 4, &n6, nullptr }, n3 = { 3 };
  TreeNode n2 = { 2, &n4, &n5 }, n1 = { 1, &n3, nullptr };
  TreeNode n0 = { 0, &n1, &n2 };
  acc_vv_t vv;
  foldToVector(&n0, vv, allPathesFinder);
  printPathesLen(vv);
  dropLessPathes(vv);
  cout << "Longest pathes: " << endl;
  printPathes(vv);

  return 0;
}
