#include <iostream>
#include <locale>
#include "gameLogic.h"
#include "saving.h"

int main() {
    system("chcp 65001 > nul");

    Game game;
    std::string input;
    while (input != "0") {
        std::cout << "====== Крестики-нолики ======\n";
        std::cout << "1. Начать новую игру\n";
        std::cout << "2. Загрузить сохраненную игру\n";
        std::cout << "=============================\n";
        std::cout << "0. Выход\n";
        std::cout << "\n";
        std::cout << "Ваш выбор:";

        std::getline(std::cin, input);
        if (input == "1") {
            std::cout << "Начинаем новую игру...\n\n\n";
            initGame(game);
            gameLoop(game);
        } else if (input == "2") {
            if (loadGame(game)) {
                std::cout << "Загружена сохраненная игра.\n\n\n";
                gameLoop(game);
            } else {
                std::cout << "Ошибка: Нет сохраненной игры или файл поврежден.\n\n";
            }
        } else if (input == "0") {
            std::cout << "Выход...";
        } else {
            std::cout << "Неверный ввод, попробуйте снова..\n\n";
        }
    }
}
