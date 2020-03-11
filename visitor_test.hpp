#ifndef __VISITOR_TEST_HPP__
#define __VISITOR_TEST_HPP__

#include "gtest/gtest.h"

#include "sub.hpp"
#include "op.hpp"
#include "Abs.hpp"
#include "add.hpp"
#include "Ceil.hpp"
#include "div.hpp"
#include "Floor.hpp"    
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"
#include "Trunc.hpp"
#include "visitor.hpp"
#include <iostream>

TEST(SubGroupTest, SubVisitorEvaluate)
{
    Op *test1 = new Op(8);
    Op *test2 = new Op(8);
    Sub *test = new Sub(test1, test2);
    CountVisitor *val = new CountVisitor();
    test->accept(val);
    EXPECT_EQ(val->sub_count(), 1);
}

TEST(AddGroupTest, AddVisitorEvaluate)
{
    Op *test1 = new Op(1);
    Op *test2 = new Op(2);
    Add *test = new Add(test1, test2);

    Op *test3 = new Op(3);
    Op *test4 = new Op(4);
    Add *test5 = new Add(test3, test4);
    CountVisitor *val = new CountVisitor();
    test->accept(val);
    test5->accept(val);
    EXPECT_EQ(val->add_count(), 2);
}

TEST(PowGroupTest, PowVisitorEvaluate)
{
    Op *test1 = new Op(2);
    Op *test2 = new Op(3);
    Sub *test_1 = new Sub(test1, test2);

    Op *test3 = new Op(4);
    Op *test4 = new Op(4);
    Sub *test_2 = new Sub(test1, test2);

    Op *test5 = new Op(3);
    Op *test6 = new Op(2);
    Sub *test_3 = new Sub(test1, test2);


    CountVisitor *val = new CountVisitor();
    test_1->accept(val);
    test_2->accept(val);
    test_3->accept(val);
    EXPECT_EQ(val->sub_count(), 3);
}

TEST(AbsGroupTest, AbsVisitorEvaluate)
{
    Op *test1 = new Op(8);
    Absolute *test = new Absolute(test1);
    CountVisitor *val = new CountVisitor();
    test->accept(val);
    EXPECT_EQ(val->abs_count(), 1);
}





#endif //__VISTOR_TEST_HPP__
