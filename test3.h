#ifndef TEST3_H_
#define TEST3_H_

#include <iostream>
#include <gtest.h>

namespace test3 {
template<typename T>
struct List {
 private:
  T _head;
  List<T> *_tail = nullptr;

 public:
  void cons(T val) {
    List<T> *newList = new List();
    newList->_tail = _tail;
    newList->_head = _head;
    _tail = newList;
    _head = val;
  }
  T head(void) {
    return _head;
  }
  List<T>* tail(void) {
    return _tail;
  }
  bool empty(void) {
    return _tail == nullptr ? true : false;
  }
  void remove(void) {
    if (empty())
      return;
    List<T> *oldList = _tail;
    _tail = oldList->_tail;
    _head = oldList->_head;
    delete oldList;
  }
  void map(void f(T*)) {
    List<T> *p = this;
    while (!p->empty()) {
      f(&(p->_head));
      p = p->tail();
    }
  }
  int size(void) {
    List<T> *p = this;
    int s = 0;
    while (!p->empty()) {
      s += 1;
      p = p->tail();
    }
    return s;
  }
};

template<typename T>
void dropEvery5th(List<T> &l) {
  int counter = 0;
  List<T> *p = &l;
  while (!p->empty()) {
    counter += 1;
    if (counter % 5 == 0) {
      p->remove();
      continue;
    }
    p = p->tail();
  }
}
}  // namespace test3

#endif /* TEST3_H_ */
