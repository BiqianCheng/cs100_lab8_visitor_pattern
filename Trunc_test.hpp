#ifndef __TRUNC_TEST_HPP__
#define __TRUNC_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "sub.hpp"
#include "decorator.hpp"
#include "Trunc.hpp"

TEST(truncTest, TruncEvaluateNonZero) {
    Op* value1 = new Op(7);
    Op* value2 = new Op(4);

    Sub* sb = new Sub(value1, value2);
    Trunc* truncate  = new Trunc(sb);
    EXPECT_EQ(truncate->stringify(), "3.000000");
}
#endif 
