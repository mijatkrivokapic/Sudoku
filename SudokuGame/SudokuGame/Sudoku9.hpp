#include<string>
#include "Board.hpp"

class Sudoku9 {
private:
	std::string puzzleFileName;
	std::string solutionFileName;
	bool solved;
	int correctCount;
	int incorrectCount;
	int gameCount;
	Board puzzle;
	Board solution;
};