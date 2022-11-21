#ifndef __DEQUETEST_H__
#define __DEQUETEST_H__

#include "cppunit/extensions/HelperMacros.h"

class Deque;
class DequeTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(DequeTest);
  CPPUNIT_TEST(testConstruction);
  CPPUNIT_TEST(testPush_back);
  CPPUNIT_TEST(testPop_back);
  CPPUNIT_TEST(testGrow);
  CPPUNIT_TEST(testPush_front);
  CPPUNIT_TEST(testDoit);
  CPPUNIT_TEST(testPop_front);
  CPPUNIT_TEST(testCopy_construction);
  CPPUNIT_TEST(testAssignment_operator);
  CPPUNIT_TEST(testDont_try_suicide);
  CPPUNIT_TEST_SUITE_END();
   
public:
  DequeTest() : d(NULL) {}
  virtual void setUp();
  virtual void tearDown();
  
  void testConstruction();
  void testPush_back();
  void testPop_back();
  void testGrow();
  void testPush_front();
  void testDoit();
  void testPop_front();
  void testCopy_construction();
  void testAssignment_operator();
  void testDont_try_suicide();
  
private:
  Deque* d;
};

#endif