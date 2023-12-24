#ifndef SUDOKU9
#define SUDOKU9

#include<string>
#include<time.h>
#include "Board.hpp"
#include "FileManager.hpp"

class Sudoku9 {
private:
	/**Sets all values in board.data to 0.
	*/
	void erasePuzzle();
	/**Fills 3x3 square within board.data with pseudo-random numbers which do not break Sudoku rules.
	*	@param row - index of first row in a square to be filled
	*	@param col - index of first column in a square to be filler
	*/
	void fillSquare(int row, int col);
	/**Sets values from pseudo-random locations to 0
	* @param count - number of values to be set to 0
	*/
	void removeValues(int count);
	/**Checks if Sudoku is solved anf generates game stats
	*/
	void generateStats();
	bool solve(Board& board);
public:
	Board puzzle;
	Board solution;
	std::string puzzleFileName;
	std::string solutionFileName;
	bool solved;
	bool correctSolution;
	int correctCount;
	int incorrectCount;
	int gameCount;
	Sudoku9(std::string puzzleFileName, std::string solutionFileName);
	void solvePuzzle();
	/**	Generates pseudo-random Sudoku board.
	*	Values in board.data are replaced with generated table.
	*/
	void generatePuzzle();
	void loadPuzzle();
	void loadSolution();
};

#endif