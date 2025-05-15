// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_red_black/red_black.h"
#include <random>
/*
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
	tree1.insert(-17);
	ASSERT_TRUE((tree1.min()->data == -17));

}

TEST(test_RedBlackTree, test_max) {
	RedBlackTree tree1;
	tree1.insert(1);
	tree1.insert(21);
	tree1.insert(5);
	tree1.insert(17);
	tree1.insert(-15);
	ASSERT_TRUE((tree1.max()->data == 21));
	tree1.insert(817);
	ASSERT_TRUE((tree1.max()->data == 817));
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

TEST(test_RedBlackTree, test_lenBlack) {
	RedBlackTree tree1;
	for(int i = 0; i < 100; i++) tree1.insert(i);

	ASSERT_EQ(tree1.lenBlack(), 2);

}
TEST(test_RedBlackTree, test_replay) {
	RedBlackTree tree1;
	tree1.insert(1);
	tree1.insert(-15);
	tree1.insert(21);
	tree1.insert(21);
	tree1.insert(21);

	ASSERT_TRUE((tree1.max()->parent->data == 1));

}
TEST(test_RedBlackTree, test_1) {
	RedBlackTree tree1;
	tree1.insert(1);
	tree1.insert(10);
	tree1.insert(9);



	tree1.displayTrea();
	ASSERT_TRUE((tree1.max()->data == 1));

}
*/