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

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 9);

	d.union_sets(1, 10);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 0);
}

TEST(test_dsu, test_clear) {
	DSU d = DSU(10);
	d.clear();

	ASSERT_TRUE(d.get_size() == 0);
}