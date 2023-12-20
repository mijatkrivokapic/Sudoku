#include <string>
#include <fstream>
#include <sstream>
#include<time.h>

class Board {
private:
	bool isValid(int row, int col, int num);
	bool isInRow(int row, int num);
	bool isInCol(int col, int num);
	bool isInSquare(int row, int col, int num);
	bool findEmpty(int& row, int& col);
public:
	int data[9][9];
	Board();
	void loadFromFile(std::string filename);
	bool solve();
	friend std::ostream& operator<<(std::ostream& os, const Board& b);
	void generateBoard();
	void eraseBoard();
	void fillSquare(int row, int col);
	void removeValues(int count);
};