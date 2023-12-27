/**
 * @file FileManager.cpp
 * @brief Implementation of FileManager class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include "FileManager.hpp"

void FileManager::readBoard(Board& board, std::string filename) {
	std::ifstream in(filename);
	if (!in) {
		throw(std::runtime_error("File not found!"));
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			in >> board.data[i][j];
		}
	}
	in.close();
}

void FileManager::writeBoard(const Board& board, std::string filename) {
	std::ofstream out(filename);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			out << board.data[i][j];
			j == 8 ? out << '\n' : out << ' ';
		}
	}
	out.close();
}