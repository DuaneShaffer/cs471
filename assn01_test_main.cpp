// assn01_test_main.cpp
// Duane Shaffer
// 6 September 2018
//
// For CS 471 Fall 2018
// Test program for quicksort algorithm
// Used in Assignment 1
// Uses the "Catch" unit-testing framework
// Requires assn01_test_suites.cpp, catch.hpp, assn01.h, assn01.cpp

#define CATCH_CONFIG_FAST_COMPILE
                             // Disable some features for faster compile
#define CATCH_CONFIG_RUNNER  // We write our own main
#include "catch.hpp"         // For the "Catch" unit-testing framework
#include <iostream>          // For std::cout, endl, cin


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc, char *argv[])
{
    Catch::Session session;  // Primary Catch object
    int catchresult;         // Catch return code; for return by main

    // Handle command line
    catchresult = session.applyCommandLine(argc, argv);

    if (!catchresult)  // Continue only if no command-line error
    {
        // Run test suites
        std::cout << "BEGIN tests for quicksort algorithm"
                  << " - CS 471 Assn 1"
                  << std::endl
                  << std::endl;
        catchresult = session.run();
        std::cout << "END tests for quicksort algorithm"
                  << " - CS 471 Assn 1"
                  << std::endl
                  << std::endl;
    }

    // Wait for user
    std::cout << "Press ENTER to quit ";
    while (std::cin.get() != '\n') ;

    // Program return value is return code from Catch
    return catchresult;
}