/**
 * @file Board.cpp
 * @brief Implementation of Board class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "board.hpp"
#include<iostream>


Board::Board() :data() { }

Board::Board(int initialData[9][9]) :data() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			data[i][j] = initialData[i][j];
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
	checkRange(row, col, num);
	if (isInRow(row, col, num) || isInCol(row, col, num) || isInSquare(row, col, num)) {
		return false;
	}
	return true;
}

bool Board::isInRow(int row,int col, int num){
	checkRange(row, col, num);
	for (int i = 0; i < 9; i++) {
		if (i != col && data[row][i] == num) {
			return true;
		}
	}
	return false;
}

bool Board::isInCol(int row, int col, int num){
	checkRange(row, col, num);
	for (int i = 0; i < 9; i++) {
		if (i != row && data[i][col] == num) {
			return true;
		}
	}
	return false;

}

bool Board::isInSquare(int row, int col, int num){
	checkRange(row, col, num);
	for (int i = row - row % 3; i < row - row % 3 + 3; i++) {
		for (int j = col - col % 3; j < col - col % 3 + 3; j++) {
			if (data[i][j] == num && !(i == row && j == col)) {
				return true;
			}
		}
	}
	return false;
}

void Board::checkRange(int row, int col, int num) {
	if (row < 0 || row>8 || col < 0 || col > 8) {
		throw std::runtime_error("Position out of range!");
	}
	if (num < 1 || num > 9) {
		throw std::runtime_error("Number out of range!");
	}
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