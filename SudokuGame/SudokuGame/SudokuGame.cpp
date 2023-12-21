// SudokuGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Sudoku9.hpp"

int main(int argc, char* argv[])
{
    //proveri da li ima 2 argumenta
    Sudoku9 game(argv[1], argv[2]);
    char continueGame;
    char option;
    do {
        std::cout << "Unesite redni broj ispred opcije koju zelite:" << std::endl;
        std::cout << "\t1)Ucitavanje postavke zagonetke iz fajla " << game.puzzleFileName << std::endl;
        std::cout << "\t2) Generisanje nove postavke zagonetke" << std::endl;
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
                std::cout << "option";
                game.generatePuzzle();
                break;
            default:
                std::cout << "Pogresan unos, pokusajte ponovo:" << std::endl;
                succes = false;
            }
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
                std::cout << "option";
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
        std::cout << "\tBroj ravilno postavljenih brojeva: " << game.correctCount << std::endl;
        game.solved ? std::cout << "\tZagonetka je resena" << std::endl : std::cout << "\tZagonetka nije resena" << std::endl;
        std::cout << game.puzzle;
        std::cout << game.solution;
        std::cin >> continueGame;
    } while (continueGame != 'n' || continueGame != 'N');
}

    