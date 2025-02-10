// Copyright 2025 <Victor Klimovich>

#include <gtest.h>
#include "../lib_dsu/DSU.h"


#define EPSILON 0.000001


TEST(test_true, can_div) {
	DSU d = DSU(10);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 9);

	d.union_sets(1, 10);

	ASSERT_TRUE(d.find(1) == 0);
	ASSERT_TRUE(d.find(10) == 0);


}