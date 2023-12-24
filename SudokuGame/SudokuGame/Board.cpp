#include "board.hpp"
#include<iostream>


Board::Board() :data() { }

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
	if (isInRow(row, col, num) || isInCol(row, col, num) || isInSquare(row, col, num)) {
		return false;
	}
	return true;
}
bool Board::isInRow(int row,int col, int num){
//eror ako je vece od 9
	for (int i = 0; i < 9; i++) {
		if (i != col && data[row][i] == num) {
			return true;
		}
	}
	return false;
}
bool Board::isInCol(int row, int col, int num){
	for (int i = 0; i < 9; i++) {
		if (i != row && data[i][col] == num) {
			return true;
		}
	}
	return false;

}
bool Board::isInSquare(int row, int col, int num){
	for (int i = row - row % 3; i < row - row % 3 + 3; i++) {
		for (int j = col - col % 3; j < col - col % 3 + 3; j++) {
			if (data[i][j] == num && !(i == row && j == col)) {
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