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
#include <cfloat>
#include <random>
#include <iostream>

using std::is_sorted;
using std::vector;

/*******************************
 * Helper functions for test suite
 * *********************************/
template <typename t>
void sort_and_test(t & container){
    my_quicksort(container.begin(), container.end());
    REQUIRE(is_sorted(container.begin(), container.end()));
}

template <typename t>
void if_sorted_change(t & container) {
    if (is_sorted(container.begin(), container.end())){
            std::swap(*container.begin(), *(container.end()-1));
        }
}

template <typename t, typename u>
void create_and_test_array_size(t size, u gen) {
    vector<t> testVec(size);
    generate(begin(testVec), end(testVec), gen);
    if_sorted_change(testVec);
    sort_and_test(testVec);
}

/********************************
 * Test Cases for my_quicksort
 * *****************************/
TEST_CASE("Empty container"){
    vector<int> testVec{};
    sort_and_test(testVec);
}
TEST_CASE("Sorted array remains sorted"){
    SECTION("Positive Values"){
        vector<int> testVec{0,1,2,3,4};
        sort_and_test(testVec);
    }
    SECTION("Negative values"){
        vector<int> testVec{-4,-3,-2,0};
        sort_and_test(testVec);
    }
    SECTION("Single value"){
        vector<int> testVec{0};
        sort_and_test(testVec);
    }
    SECTION("Int min and max"){
        vector<int> testVec{INT_MIN, INT_MAX};
        sort_and_test(testVec);
    }
}

TEST_CASE("Unsorted array is sorted: int"){
    // Random generation from: 
    // https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_int_distribution<int> dist {INT_MIN, INT_MAX};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    SECTION("Array size: 2"){ create_and_test_array_size(2, gen); }
    SECTION("Array size: 10"){ create_and_test_array_size(10, gen); }
    SECTION("Array size: 100"){ create_and_test_array_size(100, gen); }
    SECTION("Array size: 10000"){ create_and_test_array_size(10000, gen); }
}

TEST_CASE("Unsorted array is sorted: double"){
    // Random generation from: 
    // https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_real_distribution<double> dist {DBL_MIN, DBL_MAX};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    SECTION("Array size: 2"){ create_and_test_array_size((double) 2, gen); }
    SECTION("Array size: 10"){ create_and_test_array_size((double)10, gen); }
    SECTION("Array size: 100"){ create_and_test_array_size((double)100, gen); }
    SECTION("Array size: 10000"){ create_and_test_array_size((double)10000, gen); }
}

TEST_CASE("Unsorted array with a lot of repeated data"){
    // Random generation from: 
    // https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    std::uniform_real_distribution<double> dist {DBL_MIN, DBL_MAX};

    auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };

    unsigned int NUMTIMESTOTEST = 5;
    for (auto i = 0; i < NUMTIMESTOTEST; ++i){
        vector<double> testVec(10);
        generate(begin(testVec), end(testVec), gen);

        unsigned int AMOUNT_OF_REPEATED_DATA = 5; // Data repeated 2^(number entered) times
        for (auto j = 0; j < AMOUNT_OF_REPEATED_DATA; ++j)
            testVec.insert(std::end(testVec), std::begin(testVec), std::end(testVec));
        sort_and_test(testVec);
    }
}