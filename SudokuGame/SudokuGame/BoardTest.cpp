/**
 * @file BoardTest.cpp
 * @brief Implementation of BoardTest class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "BoardTest.hpp"

int data[9][9] = { {0,3,0,2,0,0,0,0,7},
		{0,0,6,1,0,0,5,0,0},
		{0,2,5,0,9,7,0,0,0},
		{0,0,1,0,0,0,7,0,0},
		{5,0,0,7,3,0,8,0,0},
		{0,0,7,0,0,0,0,5,0},
		{0,9,3,0,0,0,0,7,5},
		{0,0,0,9,0,0,0,0,0},
		{0,0,0,0,0,0,9,0,0} };

int fullData[9][9] = {
	{1,2,4,5,3,6,8,7,9},
	{8,5,3,4,9,7,2,1,6},
	{6,7,9,1,8,2,4,3,5},
	{2,1,8,3,6,5,7,9,4},
	{3,4,6,9,7,1,5,2,8},
	{7,9,5,8,2,4,3,6,1},
	{5,6,1,2,4,3,9,8,7},
	{4,8,2,7,1,9,6,5,3},
	{9,3,7,6,5,8,1,4,2}
};

BoardTest::BoardTest() :board(data),fullBoard(fullData){}

void BoardTest::isInColTest() {
	std::cout << "\nTestig functioin Board::isInCol" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	//not in col test
	if (!board.isInCol(0, 1, 4)) {
		std::cout << "Not in col test passed" << std::endl;
	}
	else {
		std::cout << "Not in col test failed" << std::endl;
	}

	//in col test
	if (board.isInCol(0, 1, 2)) {
		std::cout << "Is in col test passed" << std::endl;
	}
	else {
		std::cout << "Is in col test failed" << std::endl;
	}

	try {
		//position out of range test
		board.isInCol(-1, 10, 2);
		std::cout << "Position out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Position out of range test passed" << std::endl;
	}

	try {
		//number out of range test
		board.isInCol(1, 3, 10);
		std::cout << "Number out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Number out of range test passed" << std::endl;
	}
}

void BoardTest::isInRowTest() {
	std::cout << "\nTestig functioin Board::isInRow" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	//not in row test
	if (!board.isInRow(2, 1, 1)) {
		std::cout << "Not in row test passed" << std::endl;
	}
	else {
		std::cout << "Not in row test failed" << std::endl;
	}

	//in row test
	if (board.isInRow(2, 1, 9)) {
		std::cout << "Is in row test passed" << std::endl;
	}
	else {
		std::cout << "Is in row test failed" << std::endl;
	}

	try {
		//position out of range test
		board.isInRow(-1, 10, 2);
		std::cout << "Position out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Position out of range test passed" << std::endl;
	}

	try {
		//number out of range test
		board.isInRow(1, 3, 10);
		std::cout << "Number out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Number out of range test passed" << std::endl;
	}
}

void BoardTest::isInSquareTest() {
	std::cout << "\nTestig functioin Board::isInSquare" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	//not in square test
	if (!board.isInSquare(6, 6, 1)) {
		std::cout << "Not in square test passed" << std::endl;
	}
	else {
		std::cout << "Not in square test failed" << std::endl;
	}

	//in square test
	if (board.isInSquare(7, 8, 9)) {
		std::cout << "Is in square test passed" << std::endl;
	}
	else {
		std::cout << "Is in square test failed" << std::endl;
	}

	try {
		//position out of range test
		board.isInSquare(-1, 10, 2);
		std::cout << "Position out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Position out of range test passed" << std::endl;
	}

	try {
		//number out of range test
		board.isInSquare(6, 6, 10);
		std::cout << "Number out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Number out of range test passed" << std::endl;
	}
}

void BoardTest::isValidTest() {
	std::cout << "\nTestig functioin Board::isValid" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;

	//not valid test
	if (!board.isValid(0, 0, 3)) {
		std::cout << "Not valid test passed" << std::endl;
	}
	else {
		std::cout << "Not valid test failed" << std::endl;
	}

	//valid test
	if (board.isValid(0, 0, 1)) {
		std::cout << "Valid test passed" << std::endl;
	}
	else {
		std::cout << "Valid test failed" << std::endl;
	}

	try {
		//position out of range test
		board.isValid(-1, 10, 2);
		std::cout << "Position out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Position out of range test passed" << std::endl;
	}

	try {
		//number out of range test
		board.isValid(1, 3, 10);
		std::cout << "Number out of range test failed" << std::endl;
	}
	catch (std::runtime_error err) {
		std::cout << "Number out of range test passed" << std::endl;
	}
}

void BoardTest::findEmptyTest() {
	std::cout << "\nTestig functioin Board::findEmoty" << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	
	//first empty field test
	int row = -1;
	int col = -1;
	if (board.findEmpty(row, col) && row == 0 && col == 0) {
		std::cout << "First field empty test passed" << std::endl;
	}
	else {
		std::cout << "First field empty failed" << std::endl;
	}

	for (int i = 0; i < 9; i++) {
		board.data[0][i] = i+1;
	}

	//first row full test
	if (board.findEmpty(row, col) && row == 1 && col == 0) {
		std::cout << "First row full test passed" << std::endl;
	}
	else {
		std::cout << "First row full test failed" << std::endl;
	}


	//full board test

	if (!fullBoard.findEmpty(row, col)) {
		std::cout << "Full board test passed" << std::endl;
	}
	else {
		std::cout << "Full board test failed" << std::endl;
	}

	//last position empty test
	fullBoard.data[8][8] = 0;
	if (fullBoard.findEmpty(row, col) && row == 8 && col == 8) {
		std::cout << "Last position empty test passed" << std::endl;
	}
	else {
		std::cout << "Last position empty failed" << std::endl;
	}
}

void BoardTest::runAllTests() {
	std::cout << "\nTestig Board" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	isInColTest();
	isInRowTest();
	isInSquareTest();
	isValidTest();
	findEmptyTest();
}