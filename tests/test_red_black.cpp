// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_red_black/red_black.h"
#include <random>

TEST(test_RedBlackTree, testSearchBST) {
	RedBlackTree tree1;
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

TEST(test_RedBlackTree, test_min) {
	RedBlackTree tree1;
	tree1.insert(-15);
	tree1.insert(1);
	tree1.insert(21);
	tree1.insert(5);
	tree1.insert(17);
	ASSERT_TRUE((tree1.min()->data == -15));
}

TEST(test_RedBlackTree, test_max) {
	RedBlackTree tree1;
	tree1.insert(1);
	tree1.insert(21);
	tree1.insert(5);
	tree1.insert(17);
	tree1.insert(-15);
	ASSERT_TRUE((tree1.max()->data == 21));
}

TEST(test_RedBlackTree, test_parent) {
	RedBlackTree tree1;
	tree1.insert(1);  
	tree1.insert(-15);
	tree1.insert(21); 
	ASSERT_TRUE((tree1.max()->parent->data == 1));
	tree1.insert(90); 
	ASSERT_TRUE((tree1.max()->parent->data == 21));

}