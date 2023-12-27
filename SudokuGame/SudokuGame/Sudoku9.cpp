/**
 * @file Sudoku9.cpp
 * @brief Implementation of Sudoku9 class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "Sudoku9.hpp"

Sudoku9::Sudoku9(std::string puzzleFN, std::string solutionFN) :puzzle(Board()),solution(Board()), puzzleFileName(puzzleFN), solutionFileName(solutionFN), solved(false), correctCount(0), incorrectCount(0), gameCount(0) {
	srand(time(NULL));
}
	

void Sudoku9::solvePuzzle() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			solution.data[i][j] = puzzle.data[i][j];
		}
	}
	if (!solve(solution)) {

		throw std::runtime_error("Puzzle is unsolvable!");
	}
	generateStats();
	FileManager::writeBoard(solution, solutionFileName);
}

//recursive function that uses backtracking
bool Sudoku9::solve(Board& board) {
	int row = 0;
	int col = 0;

	//if there are no empty spaces, board is solved
	if (!board.findEmpty(row, col)) {
		return true;
	}

	//checking possible numbers in current position
	for (int i = 1; i < 10; i++) {
		if (board.isValid(row, col, i)) {
			board.data[row][col] = i;
			if (solve(board)) { //move on to next position
				return true;	
			}
			board.data[row][col] = 0; //couldn't solve board with i in that position
		}
	}
	return false; //every number in this position breaks the rules - trigger backtracking
}

void Sudoku9::erasePuzzle() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			puzzle.data[i][j] = 0;
		}
	}
}

//Generates puzzle by filling diagonal submatrices first
void Sudoku9::generatePuzzle() {
	erasePuzzle();
	//fill diagonal submatrices
	fillSquare(0, 0);
	fillSquare(3, 3);
	fillSquare(6, 6);
	//fill remaining positions by solving the puzzle
	solve(puzzle);
	int toRemove = rand() % 10 + 54;
	removeValues(toRemove);
	FileManager::writeBoard(puzzle, puzzleFileName);
}

void Sudoku9::fillSquare(int row, int col) {
	for (int i = row; i < row + 3; i++) {
		for (int j = col; j < col + 3; j++) {
			int num;
			do {
				num = rand() % 9 + 1;
			} while (puzzle.isInSquare(i, j, num));
			puzzle.data[i][j] = num;
		}
	}
}

void Sudoku9::removeValues(int count) {
	int row, col;
	for (int i = 0; i < count; i++) {
		do {
			row = rand() % 9;
			col = rand() % 9;
		} while (puzzle.data[row][col] == 0);
		puzzle.data[row][col] = 0;
	}
}


void Sudoku9::generateStats() {
	gameCount++;
	correctCount = 0;
	incorrectCount = 0;
	solved = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (puzzle.data[i][j] == 0) {  //only counting numbers not present in puzzle
				if (solution.data[i][j] == 0) {
					solved = false;  //if there is an empty position in solution, puzzle isn't solved
				}
				else {
					solution.isValid(i, j, solution.data[i][j]) ? correctCount++ : incorrectCount++;
				}
			}
			else {
				if (puzzle.data[i][j] != solution.data[i][j]) {
					throw std::runtime_error("Solution doesn't match the puzzle!");
				}
			}
			
		}
	}
	solved = solved && (incorrectCount == 0);
}

void Sudoku9::loadPuzzle() {
	FileManager::readBoard(puzzle, puzzleFileName);
}

void Sudoku9::loadSolution() {
	FileManager::readBoard(solution, solutionFileName);
	generateStats();
}





