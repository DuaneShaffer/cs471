// assn01_test_suites.cpp
// Duane Shaffer
// 6 September 2018
//
// For CS 471 Fall 2018
// Test program for quicksort algorithm
// Used in Assignment 1
// Uses the "Catch" unit-testing framework
// Requires assn01_test_main.cpp, catch.hpp, assn01.h
// The beginning of this file comes from previous assignments from Dr. Glen G Chappell
#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "headers/catch.hpp"       // For the "Catch" unit-testing framework
#include <vector>
#include <algorithm>
#include "headers/assn01.h"

using std::is_sorted;
using std::vector;

TEST_CASE("Unsorted array remains sorted") {
    vector<int> testVec{0,1,2,3,4};

    my_quicksort(testVec, testVec.begin(), testVec.end());

    REQUIRE(is_sorted(testVec.begin(), testVec.end()));

}