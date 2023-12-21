#ifndef SUDOKU9
#define SUDOKU9

#include<string>
#include "Board.hpp"
#include "FileManager.hpp"

class Sudoku9 {
private:
	std::string puzzleFileName;
	std::string solutionFileName;
	Board board;
	void generateBoard();
	void eraseBoard();
	void fillSquare(int row, int col);
	void removeValues(int count);
	void generateStats();
public:
	bool solved;
	int correctCount;
	int incorrectCount;
	int gameCount;
	Sudoku9(std::string puzzleFileName, std::string solutionFileName);
	bool solve();
};

#endif