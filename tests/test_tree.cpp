// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_tree/TREE.h"


TEST(test_tree, insert) {
	Tree tr1 = Tree();
    tr1.insert(10);
    tr1.insert(12);
    tr1.insert(9);
    tr1.insert(9);
    tr1.insert(8);
    tr1.insert(11);
    tr1.insert(7);

    int *data = tr1.get_left();

	ASSERT_EQ(data[0], 10);
	ASSERT_EQ(data[1], 9);
    ASSERT_EQ(data[2], 8);
    ASSERT_EQ(data[3], 7);

}
TEST(test_tree, size) {
    Tree tr1 = Tree();
    ASSERT_EQ(tr1.get_size(), 0);

    tr1.insert(1);
    tr1.insert(2);
    tr1.insert(3);
    tr1.insert(4);
    tr1.insert(5);
    tr1.insert(6);
    tr1.insert(0);

    ASSERT_EQ(tr1.get_size(), 7);

}