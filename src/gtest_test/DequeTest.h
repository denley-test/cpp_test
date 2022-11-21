#ifndef __DEQUETEST_H__
#define __DEQUETEST_H__

#include "gtest/gtest.h"

class Deque;
class DequeTest : public testing::Test {
public:
  DequeTest() : d(NULL) {}
protected:
  virtual void SetUp();
  virtual void TearDown();
  
protected:
  Deque* d;
};

#endif