#include "DequeTest.h"
#include "Deque.h"
#include <cassert>

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( DequeTest, "alltest" );

void DequeTest::setUp()
{
    d = new Deque();
    assert(d != NULL);
}

void DequeTest::tearDown()
{
    delete d;
    d = NULL;
}

void DequeTest::testConstruction()
{
    CPPUNIT_ASSERT ( 0 == d->size() );
}

void DequeTest::testPush_back()
{
    d->push_back(0);
    CPPUNIT_ASSERT ( 1 == d->size() );
}

void DequeTest::testPop_back()
{
    d->push_back(0);
    d->push_back(1);
    CPPUNIT_ASSERT ( 1 == d->pop_back() );
    CPPUNIT_ASSERT ( 0 == d->pop_back() );
}

void DequeTest::testGrow()
{
    for (int i = 0; i < 10; i++)
        d->push_back(i);
    d->push_back(10);
    CPPUNIT_ASSERT ( 11 == d->size() );
    CPPUNIT_ASSERT ( 10 == d->pop_back() );
}

void DequeTest::testPush_front()
{
    d->push_front(0);
    CPPUNIT_ASSERT ( 1 == d->size() );
}

void DequeTest::testDoit()
{
    d->push_front(0);
    d->push_back(1);
    d->push_back(2);
    d->push_back(3);
    CPPUNIT_ASSERT ( 4 == d->size() );
    CPPUNIT_ASSERT ( 0 == d->pop_front() );
    CPPUNIT_ASSERT ( 3 == d->pop_back() );
}

void DequeTest::testPop_front()
{
    d->push_front(0);
    CPPUNIT_ASSERT( 1 == d->size());
    CPPUNIT_ASSERT( 0 == d->pop_front());
    CPPUNIT_ASSERT( 0 == d->size());
}

void DequeTest::testCopy_construction()
{
    d->push_front(1);
    Deque d2 = *d;
    d->pop_front();
    CPPUNIT_ASSERT( 1 == d2.pop_front());
}

void DequeTest::testAssignment_operator()
{
    d->push_front(1);
    Deque d2;
    d2 = *d;
    d->pop_front();
    CPPUNIT_ASSERT( 1 == d2.pop_front());
}

void DequeTest::testDont_try_suicide()
{
    d->push_front(1);
    *d = *d;
    CPPUNIT_ASSERT( 1 == d->pop_front());
}
