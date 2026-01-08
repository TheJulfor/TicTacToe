#include <iostream>
#include "gameLogic.h"
#include <locale>

int main() {
    system("chcp 65001 > nul");

    std::string input;
    while (input != "0") {
        std::cout << "==== Крестики-нолики ====\n";
        std::cout << "1. Начать новую игру\n";
        std::cout << "=========================\n";
        std::cout << "0. Выход\n";
        std::cout << "\n";
        std::cout << "Ваш выбор:";

        std::getline(std::cin, input);
        if (input == "1") {
            Game game;
            std::cout << "Начинаем новую игру...\n\n\n";
            initGame(game);
            gameLoop(game);
        } else if (input == "0") {
            std::cout << "Выход...";
        } else {
            std::cout << "Неверный ввод, попробуйте снова..\n\n";
        }
    }
}
