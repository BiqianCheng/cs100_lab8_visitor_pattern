#ifndef __PAREN_TEST_HPP__
#define __PAREN_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "decorator.hpp"
#include "Paren.hpp"

TEST(parenTest, parenEvaluateNonZero) {
    Op* value1 = new Op(7);
    Op* value2 = new Op(4);

    Sub* sb = new Sub(value1, value2);
    Paren* parenth  = new Paren(sb);
    EXPECT_EQ(parenth->stringify(), "(7.000000-4.000000)");
}
#endif 
