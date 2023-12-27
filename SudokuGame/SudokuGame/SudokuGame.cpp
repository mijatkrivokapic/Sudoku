/**
 * @file SudokuGame.cpp
 * @brief Implementation of main function
 * @author Mijat Krivokapic
 * @date 27.12.2023.
 */

#include <iostream>
#include<conio.h>
#include "Sudoku9.hpp"
#include "BoardTest.hpp"
#include"Sudoku9Test.hpp"
#include "FileManagerTest.hpp"

void runAllTests();

int main(int argc, char* argv[])
{
    Sudoku9 game(argv[1], argv[2]);
    char continueGame;
    char option;
    do {
        try {
            std::cout << "Unesite redni broj ispred opcije koju zelite:" << std::endl;
            std::cout << "\t1) Ucitavanje postavke zagonetke iz fajla " << game.puzzleFileName << std::endl;
            std::cout << "\t2) Generisanje nove postavke zagonetke" << std::endl;
            std::cout << "\t3) Testiranje" << std::endl;
            bool succes = false;
            while (!succes) {
                std::cin >> option;
                succes = true;
                switch (option)
                {
                case'1':
                    game.loadPuzzle();
                    break;
                case'2':
                    game.generatePuzzle();
                    break;
                case '3':
                    runAllTests();
                    std::cin >> continueGame;
                    system("cls");
                    continue;
                    break;
                default:
                    std::cout << "Pogresan unos, pokusajte ponovo:" << std::endl;
                    succes = false;
                }
            }

            if (option == '3') {
                continue;
            }

            std::cout << game.puzzle << std::endl;

            std::cout << "Unesite redni broj ispred opcije koju zelite:" << std::endl;
            std::cout << "\t1) Ucitavanje resenja iz fajla " << game.solutionFileName << std::endl;
            std::cout << "\t2) Prikazivanje programski generisanog resenja" << std::endl;
            succes = false;
            while (!succes) {
                std::cin >> option;
                succes = true;
                switch (option)
                {
                case'1':
                    game.loadSolution();
                    break;
                case'2':
                    game.solvePuzzle();
                    break;
                default:
                    std::cout << "Pogresan unos, pokusajte ponovo:" << std::endl;
                    succes = false;
                }
            }
            std::cout << game.solution << std::endl;
            std::cout << "Statistika igre:" << std::endl;
            std::cout << "\tBroj pogresno postavljenih brojeva: " << game.incorrectCount << std::endl;
            std::cout << "\tBroj pravilno postavljenih brojeva: " << game.correctCount << std::endl;
            std::cout << "\tRedni broj igre:" << game.gameCount << std::endl;
            game.solved ? std::cout << "\tZagonetka je resena" << std::endl : std::cout << "\tZagonetka nije resena" << std::endl;
        }
        catch (std::runtime_error err) {
            std::cout << err.what() << std::endl;
        }
        
        std::cout << "Da li zelite da nastavite igru? (d/n)" << std::endl;
        std::cin >> continueGame;
        system("cls");
    } while (continueGame != 'n' && continueGame != 'N');
}

void runAllTests() {
    BoardTest boardTest = BoardTest();
    Sudoku9Test sudoku9Test = Sudoku9Test();
    FileManagerTest fileManagerTest = FileManagerTest();
    boardTest.runAllTests();
    sudoku9Test.runAllTests();
    fileManagerTest.runAllTests();
}
    