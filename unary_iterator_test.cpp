
#include "gtest/gtest.h"

#include "iterator.hpp"
#include "op.hpp"
#include "Ceil.hpp"

TEST(unaryIterTest, unaryIterEvaluateNonZero) {
    Op* value1 = new Op(156);
    Ceiling* test = new Ceiling(value1);
    UnaryIterator *uItr = new UnaryIterator(test);
    uItr -> first();
    EXPECT_EQ(uItr->current()->evaluate(), 156);
}

