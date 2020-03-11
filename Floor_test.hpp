#ifndef __FLOOR_TEST_HPP__
#define __FLOOR_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "decorator.hpp"
#include "Floor.hpp"

TEST(floorTest, floorEvaluateNonZero) {
    Op* value1 = new Op(9.7);
    Floor* test = new Floor(value1);
    EXPECT_EQ(test->evaluate(), 9);
}
#endif 
