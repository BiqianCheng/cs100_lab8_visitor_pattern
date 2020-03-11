#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"

TEST(SubTest, SubEvaluate)
{
    Op *test1 = new Op(8);
    Op *test2 = new Op(8);
    Sub *test = new Sub(test1, test2);
    EXPECT_EQ(test->evaluate() , test1->evaluate() - test2->evaluate());
    EXPECT_EQ(test->stringify(), test1->stringify() + " - " + test2->stringify());
}

#endif //__ADD_TEST_HPP__
