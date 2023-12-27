/**
 * @file BoardTest.hpp
 * @brief Declaration od BoardTest class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#ifndef BOARD_TEST
#define BOARD_TEST

#include "Board.hpp"
#include <iostream>

class BoardTest {
public:
	Board board;
	Board fullBoard;
	BoardTest();
	void runAllTests();

	/**
	 * @brief Tests whether the isInCol function behaves as expected.
	 * Prints test results to the console.
	 * Checks cases:
	 * - When the number is not in the column.
	 * - When the number is in the column.
	 * - When the position being checked is out of range.
	 * - When the number being checked is out of range.
	 */
	void isInColTest();

	/**
	 * @brief Tests whether the isInRow function behaves as expected.
	 * Prints test results to the console.
	 * Checks cases:
	 * - When the number is not in the row.
	 * - When the number is in the row.
	 * - When the position being checked is out of range.
	 * - When the number being checked is out of range.
	 */
	void isInRowTest();

	/**
	 * @brief Tests whether the isInSquare function behaves as expected.
	 * Prints test results to the console.
	 * Checks cases:
	 * - When the number is not in the submatrix.
	 * - When the number is in the submatrix.
	 * - When the position being checked is out of range.
	 * - When the number being checked is out of range.
	 */
	void isInSquareTest();

	/**
	 * @brief Tests whether the isValid function behaves as expected.
	 * Prints test results to the console.
	 * Checks cases:
	 * - When placing a number does not violate the rules of the game.
	 * - When placing a number violates the rules of the game.
	 * - When the position being checked is out of range.
	 * - When the number being checked is out of range.
	 */
	void isValidTest();

	/**
	 * @brief Tests whether the findEmpty function behaves as expected.
	 * Prints test results to the console.
	 * Checks cases:
	 * - When the first position is empty.
	 * - When the first row is full.
	 * - When all positions are full.
	 * - When only the last position is empty.
	 */
	void findEmptyTest();
};

#endif // !BOARD_TEST
