#include <gtest/gtest.h>
#include <string>
#include "List.hpp"
#include "Bag.hpp"

TEST(ListCopyMove, CopyCtorAndIndependence) {
    List<int> a; a.push_back(1); a.push_back(2); a.push_back(3);
    List<int> b(a); // copy
    EXPECT_EQ(a.size(), 3u);
    EXPECT_EQ(b.size(), 3u);
    b.pop_front();
    EXPECT_EQ(b.front(), 2);
    EXPECT_EQ(a.front(), 1);
}

TEST(ListCopyMove, CopyAssign) {
    List<std::string> a; a.push_back("one"); a.push_back("two");
    List<std::string> b; b.push_back("x");
    b = a; // copy-assign
    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(b.front(), std::string("one"));
}

TEST(ListCopyMove, MoveCtorAndAssign) {
    List<int> a; a.push_back(10); a.push_back(20);
    List<int> b(std::move(a));
    EXPECT_EQ(b.size(), 2u);
    EXPECT_EQ(a.size(), 0u);

    List<int> c; c.push_back(7);
    c = std::move(b);
    EXPECT_EQ(c.size(), 2u);
    EXPECT_EQ(b.size(), 0u);
    EXPECT_EQ(c.front(), 10);
    EXPECT_EQ(c.back(), 20);
}

TEST(ListOps, InsertEraseAfter) {
    List<int> xs; xs.push_back(1); xs.push_back(3);
    auto it = xs.begin(); // at 1
    xs.insert_after(it, 2); // 1,2,3
    EXPECT_EQ(xs.size(), 3u);
    it = xs.begin();
    xs.erase_after(it); // erase 2 -> 1,3
    EXPECT_EQ(xs.size(), 2u);
    EXPECT_EQ(xs.back(), 3);
}

TEST(BagBasics, InsertRemoveContainsCount) {
    Bag<std::string> bag;
    bag.insert("apple");
    bag.insert("banana");
    bag.insert("apple");

    EXPECT_EQ(bag.size(), 3u);
    EXPECT_TRUE(bag.contains("banana"));
    EXPECT_EQ(bag.count("apple"), 2u);

    EXPECT_TRUE(bag.remove("apple"));
    EXPECT_EQ(bag.count("apple"), 1u);
    EXPECT_EQ(bag.size(), 2u);

    EXPECT_FALSE(bag.remove("cherry"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
