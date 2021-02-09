#include <gtest/gtest.h>

TEST(dummy2, oneEqualsOne)
{
    ASSERT_EQ(1, 1);
}

TEST(dummy2, oneNotEqualsTwo)
{
    int two = 1;

    ASSERT_NE(1, two);
}