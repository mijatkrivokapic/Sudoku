/**
 * @file Board.hpp
 * @brief Declaration od Board class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#ifndef BOARD
#define BOARD

#include <string>
#include <fstream>
#include <sstream>

class Board {
private:
    int data[9][9];
    /**
     * @brief Checks if placing a number in the specified position violates Sudoku rules.
     * @param row - Index of the row where the check is performed.
     * @param col - Index of the column where the check is performed.
     * @param num - Number being checked.
     * @return true if placing the number does not violate the rules, false otherwise.
     */
    bool isValid(int row, int col, int num);

    /**
     * @brief Checks if the number is present in the corresponding row, excluding the specified column position.
     * @param row - Index of the row to be checked.
     * @param col - Index of the column to be excluded from the check.
     * @param num - Number whose existence is checked.
     * @return true if the number is in the corresponding row, false otherwise.
     */
    bool isInRow(int row, int col, int num);

    /**
     * @brief Checks if the number is present in the corresponding column, excluding the specified row position.
     * @param row - Index of the row to be excluded from the check.
     * @param col - Index of the column to be checked.
     * @param num - Number whose existence is checked.
     * @return true if the number is in the corresponding column, false otherwise.
     */
    bool isInCol(int row, int col, int num);

    /**
     * @brief Checks if the number is present in the corresponding 3x3 submatrix of the board,
     * excluding the specified row and column.
     * @param row - Index of the row where the submatrix is located.
     * @param col - Index of the column where the submatrix is located.
     * @param num - Number whose existence is checked.
     * @return true if the number is in the corresponding submatrix, false otherwise.
     */
    bool isInSquare(int row, int col, int num);

    /**
     * @brief Finds the first empty position in the board.
     * Sets the values of the 'row' and 'col' parameters to the coordinates of the found position.
     * @param row - Reference to the variable representing the row index.
     * @param col - Reference to the variable representing the column index.
     * @return true if there is an empty position on the board, false otherwise.
     */
    bool findEmpty(int& row, int& col);

    /**
     * @brief Helper function that checks if the position is out of the board's range
     * and if the number has a valid value for a Sudoku board.
     * Throws a runtime_error if values are out of range.
     * @param row - Index of the row to be checked.
     * @param col - Index of the column to be checked.
     * @param num - Number to be checked.
     */
    void checkRange(int row, int col, int num);

public:
    /**
     * @brief Default constructor.
     * Initializes an object of the Board class, sets all values in data to 0.
     */
    Board();

    /**
     * @brief Parameterized constructor.
     * Initializes an object of the Board class, sets all values in data to those from the provided parameter.
     * @param initialData - Initial values for the data attribute.
     */
    Board(int initialData[9][9]);

    friend std::ostream& operator<<(std::ostream& os, const Board& b);
    friend class Sudoku9;
    friend class FileManager;
    friend class BoardTest;
    friend class Sudoku9Test;
    friend class FileManagerTest;
};

#endif


