// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_red_black/red_black.h"
#include <random>

TEST(test_RedBlackTree, testSearchBST) {
	RedBlackTree tree1;

	ASSERT_FALSE(tree1.SearchBST(101).first);

	tree1.insert(1);
	tree1.insert(21);
	tree1.insert(-15);

	ASSERT_FALSE(tree1.SearchBST(101).first);
	tree1.insert(101);
	ASSERT_TRUE(tree1.SearchBST(101).first);
}

TEST(test_RedBlackTree, testSearchBST_null) {
	RedBlackTree tree1;

	ASSERT_FALSE(tree1.SearchBST(101).first);
}



