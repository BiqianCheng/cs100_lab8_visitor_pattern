
#include "gtest/gtest.h"

#include "iterator.hpp"
#include "op.hpp"
#include "add.hpp"

TEST(binIterTest, binIterEvaluateNonZero) {
    Op* value1 = new Op(8.66);
    Op *value2 = new Op(7.62);
    Add* test = new Add(value1, value2);
    BinaryIterator *binItr = new BinaryIterator(test);
    binItr -> first();
    EXPECT_EQ(binItr->current()->evaluate(), 8.66 );
    binItr -> next();
    EXPECT_EQ(binItr->current()->evaluate(), 7.62);
}
