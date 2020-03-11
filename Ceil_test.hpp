#ifndef __CEIL_TEST_HPP__
#define __CEIL_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "decorator.hpp"
#include "Ceil.hpp"

TEST(ceilTest, ceilEvaluateNonZero) {
    Op* value1 = new Op(9.6);
    Ceiling* test = new Ceiling(value1);
    EXPECT_EQ(test->evaluate(), 10);
}
#endif 
