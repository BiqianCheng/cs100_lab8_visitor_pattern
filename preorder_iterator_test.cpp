#ifndef __PREORDER_ITERATOR_TEST_HPP__
#define __PREORDER_ITERATOR_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "visitor.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "iterator.hpp"
#include "Paren.hpp"

#include <iostream>

using namespace std;

TEST(PreorderItrTest, PItrSepTest)
{
    Op *input1 = new Op(1.2);
    Op *input2 = new Op(3.4);
    Op *input3 = new Op(5.6);
    Op *input4 = new Op(7.8);
    Op *input5 = new Op(9.1);
    CountVisitor *val = new CountVisitor();
    Sub *Oprd1 = new Sub(input1, input2);
    Div *Oprd2 = new Div(Oprd1, input3);
    Mult *Oprd3 = new Mult(Oprd2, input4);
    Sub *DummyHead = new Sub(Oprd3,input5);
    cout << DummyHead ->stringify()<<endl;
    PreorderIterator *PValue = new PreorderIterator(DummyHead);
    PValue->first();
    while(!PValue->is_done())
    {
        PValue->current()->accept(val);
        PValue->next();
    }
    EXPECT_EQ(val->op_count(), 5);
    EXPECT_EQ(val->sub_count(), 1);
    EXPECT_EQ(val->div_count(),1);
    EXPECT_EQ(val->mult_count(), 1);
    cout << "Sub with dummy-head: " << val->sub_count() << endl;
    cout << "Op: " <<val->op_count() << endl;
    cout << "Div: " << val->div_count() << endl;
    cout << "Mult: " << val->mult_count() << endl;
}

#endif