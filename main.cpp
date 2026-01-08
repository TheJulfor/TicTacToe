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
        std::cout << "3. Правила игры\n";
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
        } else if (input == "3") {
            std::cout << "=== Правила игры ===\n";
            std::cout << "Поле 3х3 клеток. Игроки ходят по очереди, ставя свой символ в любую из свободных клеток поля.\n";
            std::cout << "Игрок побеждает, если собрались три его символа в ряд по вертикали/горизонтали/диагонали\n";
            std::cout << "Игра заканчивается, когда побеждает один из игроков или не остается свободных клеток.\n\n";
            std::cout << "=== Номера клеток ===\n";
            std::cout << " 1 ┃ 2 ┃ 3 \n";
            std::cout << "━━━╋━━━╋━━━\n";
            std::cout << " 4 ┃ 5 ┃ 6 \n";
            std::cout << "━━━╋━━━╋━━━\n";
            std::cout << " 7 ┃ 8 ┃ 9 \n\n";
        } else if (input == "0") {
            std::cout << "Выход...";
        } else {
            std::cout << "Неверный ввод, попробуйте снова..\n\n";
        }
    }
}
