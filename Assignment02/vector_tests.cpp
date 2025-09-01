#include <gtest/gtest.h>
#include "MyVector.hpp"

TEST(VectorBase, PushGrowsAndStores) {
    Vector v;
    for (int i = 0; i < 10; ++i) v.push_back(i);
    EXPECT_EQ(v.size(), 10u);
    EXPECT_GE(v.capacity(), 10u); // power-of-two growth
}

TEST(VectorCopyVersion, SameExternalBehavior) {
    VectorCopy v;
    for (int i = 0; i < 100; ++i) v.push_back(i);
    EXPECT_EQ(v.size(), 100u);
    EXPECT_GE(v.capacity(), 100u);
}

TEST(VectorGrow4Version, Starts128ThenQuads) {
    VectorGrow4 v;
    v.push_back(42);
    EXPECT_GE(v.capacity(), 128u);
    for (int i = 0; i < 200; ++i) v.push_back(i);
    EXPECT_GE(v.capacity(), 512u); // 128 * 4
}
