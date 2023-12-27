/**
 * @file Sudoku9Test.cpp
 * @brief Implementation of Sudoku9Test class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "Sudoku9Test.hpp"

Sudoku9Test::Sudoku9Test() :game(Sudoku9("tempTestPuzzle.txt", "tempTestSolution.txt")) {}

void Sudoku9Test::generateStatsTest() {
	std::cout << "\nTestig functioin Sudoku9::generateStats" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	FileManager::readBoard(game.solution, "testValuesSolution.txt");
	FileManager::readBoard(game.puzzle, "testValuesPuzzle.txt");
	game.generateStats();

	//valid parameters test
	if (game.correctCount == 57 && game.incorrectCount == 0 && game.solved) {
		std::cout << "Valid paramerers test passed" << std::endl;
	}
	else {
		std::cout << "Valid paramerers test failed" << std::endl;
	}
	
	//incorect counter test
	FileManager::readBoard(game.solution, "testValuesPuzzle.txt");
	game.solution.data[0][0] = 4;
	game.solution.data[1][8] = 7;
	game.solution.data[6][2] = 4;
	game.generateStats();
	if (game.correctCount == 0 && game.incorrectCount == 3 && !game.solved) {
		std::cout << "Incorrect counter test passed" << std::endl;
	}
	else {
		std::cout << "Correct counter test failed" << std::endl;
	}

	//corect ccounter test
	game.solution.data[0][0] = 1;
	game.solution.data[1][8] = 6;
	game.solution.data[6][2] = 1;
	game.generateStats();
	
	if (game.correctCount == 3 && game.incorrectCount == 0 && !game.solved) {
		std::cout << "Correct counter test passed" << std::endl;
	}
	else {
		std::cout << "Correct counter test failed" << std::endl;
	}

	//puzzle and solution mismatch test
	game.solution.data[0][7] = 1;
	try {
		game.generateStats();
		std::cout << "Puzzle and solution mismatch test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Puzzle and solution mismatch test passed" << std::endl;
	}
}

void Sudoku9Test::solvePuzzleTest() {
	std::cout << "\nTestig functioin Sudoku9::solvePuzzle" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	FileManager::readBoard(game.puzzle, "testValuesPuzzle.txt");
	
	//valid puzzle test
	bool solved = true;
	game.solvePuzzle();
	for (int i = 0; i < 9; i++) {
		for (int j = 9; j < 9; j++) {
			if (!game.solution.isValid(i, j, game.solution.data[i][j]))
				solved = false;
		}
	}
	if (solved) {
		std::cout << "Valid puzzle test passed" << std::endl;
	}
	else {
		std::cout << "Valid puzzle test failed" << std::endl;
	}

	//unsolvable puzzle test
	game.puzzle.data[0][0] = 4;
	try {
		game.solvePuzzle();
		std::cout << "Unsolvable puzzle test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Unsolvable puzzle test passed" << std::endl;
	}
}

void Sudoku9Test::generatePuzzleTest() {

	//puzzle is valid  test
	game.generatePuzzle();
	bool valid = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (game.puzzle.data[i][j] != 0 && !game.puzzle.isValid(i, j, game.puzzle.data[i][j])) {
				valid = false;
			}
		}
	}
	if (valid) {
		std::cout << "Puzzle is valid test passed" << std::endl;
	}
	else {
		std::cout << "Puzzle is valid test failed" << std::endl;
	}

	//number of missing values test
	int missing = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (game.puzzle.data[i][j] == 0){
				missing++;
			}
		}
	}
	if (missing <= 64 && missing >= 54) {
		std::cout << "Number of missing values test passed" << std::endl;
	}
	else {
		std::cout << "Number of missing values test failed" << std::endl;
	}
}

void Sudoku9Test::runAllTests() {
	std::cout << "\nTestig Sudoku9" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	generateStatsTest();
	solvePuzzleTest();
	generatePuzzleTest();
}