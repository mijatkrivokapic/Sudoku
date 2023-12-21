#ifndef BOARD
#define BOARD

#include <string>
#include <fstream>
#include <sstream>
#include <time.h>


class Board {
private:
	int data[9][9];
	bool isValid(int row, int col, int num);
	bool isInRow(int row, int num);
	bool isInCol(int col, int num);
	bool isInSquare(int row, int col, int num);
	bool findEmpty(int& row, int& col);
public:
	Board();
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	friend class Sudoku9;
	friend class FileManager;
};

#endif