/**
 * @file Sudoku9.hpp
 * @brief Declaration od Sudoku9 class
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */


#ifndef SUDOKU9
#define SUDOKU9

#include<string>
#include<time.h>
#include "Board.hpp"
#include "FileManager.hpp"

class Sudoku9 {
public:
    Board puzzle;
    Board solution;
    std::string puzzleFileName;
    std::string solutionFileName;
    bool solved;
    int correctCount;
    int incorrectCount;
    int gameCount;

    /**
     * @brief Initializes an object of the Sudoku9 class.
     * Sets the file names for the puzzle and solution. Sets all values in puzzle and solution boards to 0.
     * @param puzzleFileName - File name where the puzzle is stored.
     * @param solutionFileName - File name where the solution is stored.
     */
    Sudoku9(std::string puzzleFileName, std::string solutionFileName);

    /**
     * @brief Solves the Sudoku puzzle located in the puzzle attribute.
     * Stores the solution in the solution attribute. Throws a runtime_error if the puzzle is unsolvable.
     * Generates game statistics.
     */
    void solvePuzzle();

    /**
     * @brief Generates a Sudoku puzzle with pseudorandom numbers at pseudorandom positions satisfying Sudoku rules.
     * The number of set numbers is between 17 and 27. Stores the generated puzzle in the puzzle attribute.
     */
    void generatePuzzle();

    /**
     * @brief Loads the puzzle from the file specified in the puzzleFileName attribute.
     * Stores it in the puzzle attribute. Throws a runtime_error if the file does not exist.
     */
    void loadPuzzle();

    /**
     * @brief Loads the solution from the file specified in the solutionFileName attribute.
     * Stores it in the solution attribute. Throws a runtime_error if the file does not exist or if the solution does not match the puzzle.
     * Generates game statistics.
     */
    void loadSolution();

    friend class Sudoku9Test;

private:
    /**
    * @brief Helper function that sets all data fields of the puzzle attribute to 0.
    */
	void erasePuzzle();

    /**
     * @brief Helper function that fills the given 3x3 submatrix of the puzzle attribute with pseudorandom values
     * according to Sudoku rules.
     * @param row - Index of the first row of the submatrix.
     * @param col - Index of the first column of the submatrix.
     */
	void fillSquare(int row, int col);

    /**
     * @brief Helper function that removes a specified number of values from the puzzle attribute.
     * The positions from which values are removed are pseudorandom.
     * @param count - Number of values to be removed.
     */
	void removeValues(int count);

    /**
     * @brief Generates game statistics based on the puzzle and solution attributes.
     * Stores the statistics in the corresponding class attributes.
     * Throws a runtime_error if the solution does not match the puzzle setup.
     */
    void generateStats();

    /**
     * @brief Helper recursive function that solves given board.
     * @param board - Reference to the board being solved.
     * @return true if the board is successfully solved, false otherwise.
     */
	bool solve(Board& board);
};

#endif
