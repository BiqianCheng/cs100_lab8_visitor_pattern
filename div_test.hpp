#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"

#include "div.hpp"
#include "op.hpp"

TEST(DivTest, DivEvaluate)
{
    Op *test1 = new Op(8);
    Op *test2 = new Op(4);
    Div *test = new Div(test1, test2);
    EXPECT_EQ(test->evaluate() , test1->evaluate() / test2->evaluate());
    EXPECT_EQ(test->stringify(), test1->stringify() + " / " + test2->stringify());
}

#endif //__DIV_TEST_HPP__
