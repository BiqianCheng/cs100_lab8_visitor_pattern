#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "pow.hpp"
#include "op.hpp"
#include <math.h>

TEST(PowTest, PowEvaluate)
{
    Op *test1 = new Op(8);
    Op *test2 = new Op(8);
    Pow *test = new Pow(test1, test2);
    EXPECT_EQ(test->evaluate() , pow(test1->evaluate(), test2->evaluate()));
    EXPECT_EQ(test->stringify(), test1->stringify() + " ** " + test2->stringify());
}

#endif //__POW_TEST_HPP__
