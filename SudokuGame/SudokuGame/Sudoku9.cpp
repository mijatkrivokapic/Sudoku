#include "Sudoku9.hpp"

Sudoku9::Sudoku9(std::string puzzleFileName, std::string solutionFileName) :puzzle(Board()),solution(Board()), puzzleFileName(puzzleFileName), solutionFileName(solutionFileName), solved(false), correctCount(0), incorrectCount(0), gameCount(0) {
	srand(time(NULL));
}
	
bool Sudoku9::solve(Board& board) {
	int row = 0;
	int col = 0;

	if (!board.findEmpty(row, col)) {
		return true;
	}

	for (int i = 1; i < 10; i++) {
		if (board.isValid(row, col, i)) {
			board.data[row][col] = i;
			if (solve(board)) {
				return true;
			}
			board.data[row][col] = 0;
		}
	}
	return false;
}

void Sudoku9::erasePuzzle() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			puzzle.data[i][j] = 0;
		}
	}
}

void Sudoku9::generatePuzzle() {
	erasePuzzle();
	fillSquare(0, 0);
	fillSquare(3, 3);
	fillSquare(6, 6);
	solve(puzzle);
	//izmedju 54 i 64 (da bi sudoku bio resiv mora da ima 17, a maskimum je prosecno 6 po po malom kvadratu
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
			} while (puzzle.isInSquare(row, col, num));
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
	correctCount = 0;
	incorrectCount = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			solution.isValid(i, j, solution.data[i][j]) ? correctCount++ : incorrectCount++;
		}
	}
	solved = incorrectCount == 0 ? true : false;
	gameCount++;
}

void Sudoku9::loadPuzzle() {
	FileManager::readBoard(puzzle, puzzleFileName);
}

void Sudoku9::loadSolution() {
	FileManager::readBoard(solution, solutionFileName);
	generateStats();
}

void Sudoku9::solvePuzzle() {
	std::copy(&(puzzle.data[0][0]), &(puzzle.data[9][9]), &(solution.data[0][0]));

	if (!solve(solution)) {
		//nije resiv treba neki eror
	}
	generateStats();
	FileManager::writeBoard(solution, solutionFileName);
}

