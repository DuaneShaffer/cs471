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
#include <climits>
#include <random>

using std::is_sorted;
using std::vector;

template <typename t>
void call_and_require(t & container){
    my_quicksort(container, container.begin(), container.end());
    REQUIRE(is_sorted(container.begin(), container.end()));
}

TEST_CASE("Empty container"){
    vector<int> testVec{};
    call_and_require(testVec);
}
TEST_CASE("Sorted array remains sorted"){
    SECTION("Positive Values"){
        vector<int> testVec{0,1,2,3,4};
        call_and_require(testVec);
    }
    SECTION("Negative values"){
        vector<int> testVec{-4,-3,-2,0};
        call_and_require(testVec);
    }
    SECTION("Single value"){
        vector<int> testVec{0};
        call_and_require(testVec);
    }
    SECTION("Int min and max"){
        vector<int> testVec{INT_MIN, INT_MAX};
        call_and_require(testVec);
    }
}

TEST_CASE("Unsorted array is sorted"){
    // Random generation from: https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {1, 52};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    SECTION("Array size: 2"){
        vector<int> testVec(2);
        generate(begin(testVec), end(testVec), gen);
        REQUIRE_FALSE(is_sorted(testVec.begin(), testVec.end()));
        call_and_require(testVec);
    }
    SECTION("Array size: 100"){
        vector<int> testVec(100);
        generate(begin(testVec), end(testVec), gen);
        REQUIRE_FALSE(is_sorted(testVec.begin(), testVec.end()));
        call_and_require(testVec);
    }
    SECTION("Array size: 10000"){
        vector<int> testVec(10000);
        generate(begin(testVec), end(testVec), gen);
        REQUIRE_FALSE(is_sorted(testVec.begin(), testVec.end()));
        call_and_require(testVec);
    }
}