#include "Board.hpp"

class FileManager {
public:
	static void readBoard(Board& board, std::string filename);
	static void writeBoard(const Board& board, std::string filename);
};