#include "board.hpp"
#include<iostream>


Board::Board(std::string filename) {
	std::ifstream in(filename);
	int num = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			in >> data[i][j];
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Board& b) {
	for (int i = 0; i < 9; i++) {
		if (i == 0 || i == 3 || i == 6) {
			os << "=========|=========|=========" << std::endl;
		}
		else {
			os << "---------|---------|---------" << std::endl;
		}
		for (int j = 0; j < 9; j++) {
			b.data[i][j] == 0 ? os << "   " : os << ' ' << b.data[i][j] << ' ';
			if (j == 2 || j == 5) {
				os << '|';
			}
		}
		os << std::endl;
	}
	os << "=========|=========|=========" << std::endl;
	return os;
}

bool Board::isValid(int row, int col, int num) {
	if (isInRow(row, num) || isInCol(col, num) || isInSquare(row, col, num)) {
		return false;
	}
	return true;
}
bool Board::isInRow(int row, int num){
//eror ako je vece od 9
	for (int i = 0; i < 9; i++) {
		if (data[row][i] == num) {
			return true;
		}
	}
	return false;
}
bool Board::isInCol(int col, int num){
	for (int i = 0; i < 9; i++) {
		if (data[i][col] == num) {
			return true;
		}
	}
	return false;

}
bool Board::isInSquare(int row, int col, int num){
	for (int i = row - row % 3; i < row - row % 3 + 3; i++) {
		for (int j = col - col % 3; j < col - col % 3 + 3; j++) {
			if (data[i][j] == num) {
				return true;
			}
		}
	}
	return false;
}

bool Board::findEmpty(int& row, int& col) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (data[i][j] == 0) {
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool Board::solve() {
	int row = 0;
	int col = 0;

	if (!findEmpty(row, col)) {
		return true;
	}

	for (int i = 1; i < 10; i++) {
		if (isValid(row, col, i)) {
			data[row][col] = i;
			if (solve()) {
				return true;
			}
			data[row][col] = 0;
		}
	}
	return false;
}