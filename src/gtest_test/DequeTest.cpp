#include "DequeTest.h"
#include "Deque.h"
#include <cassert>

void DequeTest::SetUp() 
{
    d = new Deque();
    assert(d != NULL);
}
  
void DequeTest::TearDown() {
    delete d;
    d = NULL;
}

TEST_F( DequeTest, construction)
{
	ASSERT_TRUE ( 0 == d->size() );
}

TEST_F( DequeTest, push_back)
{
    d->push_back(0);
    ASSERT_TRUE ( 1 == d->size() );
}

TEST_F( DequeTest, pop_back)
{
    d->push_back(0);
    d->push_back(1);
    ASSERT_TRUE ( 1 == d->pop_back() );
    ASSERT_TRUE ( 0 == d->pop_back() );
}

TEST_F( DequeTest, grow)
{
    for (int i = 0; i < 10; i++)
        d->push_back(i);
    d->push_back(10);
    ASSERT_TRUE ( 11 == d->size() );
    ASSERT_TRUE ( 10 == d->pop_back() );
}

TEST_F (DequeTest, push_front)
{
    d->push_front(0);
    ASSERT_TRUE ( 1 == d->size() );
}

TEST_F (DequeTest, doit)
{
    d->push_front(0);
    d->push_back(1);
    d->push_back(2);
    d->push_back(3);
    ASSERT_TRUE ( 4 == d->size() );
    ASSERT_TRUE ( 0 == d->pop_front() );
    ASSERT_TRUE ( 3 == d->pop_back() );
}

TEST_F (DequeTest, pop_front)
{
    d->push_front(0);
    ASSERT_TRUE( 1 == d->size());
    ASSERT_TRUE( 0 == d->pop_front());
    ASSERT_TRUE( 0 == d->size());
}

TEST_F (DequeTest, copy_construction)
{
    d->push_front(1);
    Deque d2 = *d;
    d->pop_front();
    ASSERT_TRUE( 1 == d2.pop_front());
}

TEST_F (DequeTest, assignment_operator)
{
    d->push_front(1);
    Deque d2;
    d2 = *d;
    d->pop_front();
    ASSERT_TRUE( 1 == d2.pop_front());
}

TEST_F (DequeTest, dont_try_suicide)
{
    d->push_front(1);
    *d = *d;
    ASSERT_TRUE( 1 == d->pop_front());
}
