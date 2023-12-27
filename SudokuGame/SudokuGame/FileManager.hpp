/**
 * @file FileManager.hpp
 * @brief Declaration od FileManager class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#ifndef FILE_MANAGER
#define FILE_MANAGER

#include "Board.hpp"

class FileManager {
public:
    /**
     * @brief Reads a Sudoku board from the file specified by the given filename.
     * Writes the values into the board whose reference is passed. Throws a runtime_error if the file does not exist.
     * @param board - Reference to the board where values are loaded.
     * @param filename - File name where the board is stored.
     */
	static void readBoard(Board& board, std::string filename);

    /**
     * @brief Writes the values of the given Sudoku board into the file specified by the given filename.
     * @param board - Reference to the board whose values are written.
     * @param filename - File name where the board is going to be written.
     */
	static void writeBoard(const Board& board, std::string filename);
};

#endif