/**
 * @file Sudoku9Test.hpp
 * @brief Declaration od Sudoku9Test class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#ifndef SUDOKU9_TEST
#define SUDOKU9_TEST

#include "Sudoku9.hpp"
#include<iostream>

class Sudoku9Test {
public:

	Sudoku9Test();
	Sudoku9 game;

    /**
     * @brief Tests whether the generateStats function behaves as expected.
     * Prints test results to the console.
     * Checks cases:
     * - When the puzzle is valid, the solution is complete, and it matches the puzzle.
     * - When the solution is not complete and contains only correctly placed numbers.
     * - When the solution is not complete and contains only incorrectly placed numbers.
     * - When the solution does not match the puzzle.
     */
	void generateStatsTest();

    /**
     * @brief Tests whether the solvePuzzle function behaves as expected.
     * Prints test results to the console.
     * Checks cases:
     * - Solving valid puzzle.
     * - Solving unsolvable puzzle.
     */
	void solvePuzzleTest();

     /**
      * @brief Tests whether the generatePuzzle function behaves as expected.
      * Prints test results to the console.
      * Checks if the generated puzzle violates Sudoku rules and has the correct number of missing values.
      */
	void generatePuzzleTest();

    /**
     * @brief Runs all tests from the class.
     */
	void runAllTests();
};

#endif // !SUDOKU9_TEST
