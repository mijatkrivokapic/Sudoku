/**
 * @file FileManagerTest.hpp
 * @brief Declaration od FileManagerTest class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#ifndef FILE_MANAGER_TEST
#define FILE_MANAGER_TEST

#include "FileManager.hpp"
#include<iostream>

class FileManagerTest {
public:
	Board fullBoard;
	Board emptyBoard;
	FileManagerTest();

	/**
	 * @brief Tests the behavior of the readBoard function when given the name of a non-existent file.
	 * Prints test results to the console.
	 */
	void invalidFileNameTest();

	/**
	 * @brief Tests the behavior of the writeBoard and readBoard functions.
	 * Writes a board with test values to a file, reads it back from the file, and compares the original and read data.
	 * Prints test results to the console.
	 */
	void readWriteTest();

	/**
	 * @brief Runs all tests from the class.
	 */
	void runAllTests();
};

#endif // !FILE_MANAGER_TEST
