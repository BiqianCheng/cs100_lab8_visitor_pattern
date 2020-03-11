#ifndef __ABS_TEST_HPP__
#define __ABS_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "decorator.hpp"
#include "Abs.hpp"

TEST(absTest, absEvaluateNonZero) {
    Op* value1 = new Op(-18);
    Absolute* test = new Absolute(value1);
    EXPECT_EQ(test->evaluate(), 18);
}
#endif 
