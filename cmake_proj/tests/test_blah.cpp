#include <gtest/gtest.h>

#include "blah.h"

TEST(TestBlah, OutputTest) {
    EXPECT_EQ(2,Sum(1,1));
}
