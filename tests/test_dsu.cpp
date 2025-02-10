// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_dsu/DSU.h"


#define EPSILON 0.000001



TEST(test_dsu, find_test) {
	DSU d = DSU(10);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 9);

}
TEST(test_dsu, test_union_sets) {
	DSU d = DSU(10);
	d.union_sets(1, 10);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 0);
}

TEST(test_dsu, test_clear) {
	DSU d = DSU(10);
	d.clear();

	ASSERT_TRUE(d.get_size() == 0);
}
TEST(test_dsu, test_union_sets_2) {
	DSU d = DSU(10);
	d.union_sets(1, 2);
	d.union_sets(1, 3);
	d.union_sets(1, 4);
	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(2) == 0);
	ASSERT_TRUE(d.find(3) == 0);
	ASSERT_TRUE(d.find(4) == 0);

}
TEST(test_dsu, test_union_sets_3) {
	DSU d = DSU(10);
	d.union_sets(1, 2);
	d.union_sets(1, 3);
	d.union_sets(1, 4);
	d.union_sets(4, 5);
	d.union_sets(5, 6);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(2) == 0);
	ASSERT_TRUE(d.find(3) == 0);
	ASSERT_TRUE(d.find(4) == 0);
	ASSERT_TRUE(d.find(5) == 0);


}
TEST(test_dsu, test_rank) {
	DSU d = DSU(10);

	ASSERT_TRUE(d.get_rank(1) == 0);
	ASSERT_TRUE(d.get_rank(2) == 0);
	d.union_sets(1, 2);
	d.union_sets(1, 3);

	ASSERT_TRUE(d.get_rank(1) == 1);
	ASSERT_TRUE(d.get_rank(3) == 1);
}