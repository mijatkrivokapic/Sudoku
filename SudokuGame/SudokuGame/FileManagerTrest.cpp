/**
 * @file FileManagerTest.cpp
 * @brief Implementation of FileManagerTest class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "FileManagerTest.hpp"

int testData[9][9] = {
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

FileManagerTest::FileManagerTest():fullBoard(Board(testData)),emptyBoard(Board()) {}

void FileManagerTest::invalidFileNameTest() {
	try {
		FileManager::readBoard(emptyBoard, "invalidFileName");
		std::cout << "Invalid filename test failed" << std::endl;
	}
	catch(std::runtime_error err) {
		std::cout << "Invalid filename test passed" << std::endl;
	}
}

void FileManagerTest::readWriteTest() {
	FileManager::writeBoard(fullBoard, "tempTestSolution.txt");
	FileManager::readBoard(emptyBoard, "tempTestSolution.txt");
	bool passed = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (fullBoard.data[i][j] != emptyBoard.data[i][j]) {
				passed = false;
			}
		}
	}
	if (passed) {
		std::cout << "Read write test passed" << std::endl;
	}
	else {
		std::cout << "Read write test failed" << std::endl;
	}
}

void FileManagerTest::runAllTests() {
	std::cout << "\nTestig FIleManager" << std::endl;
	std::cout << "-------------------------------------------------------------------" << std::endl;
	invalidFileNameTest();
	readWriteTest();
}