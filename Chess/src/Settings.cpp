#include "Settings.h"

#include <fstream>
#include <iostream>
#include <string>

std::string boardTextures[] = {"default", "wood", "marble", "stone", "metal"};
std::string pieceTextures[] = {"default", "wood", "marble", "stone", "metal"};

Settings::Settings() {
    std::ifstream settingsFile("settings.txt");
    settingsFile >> boardTexture >> pieceTexture;
    settingsFile.close();
}

void Settings::PrintSettings() {
    std::cout << "Plansza: " << boardTexture << "\n";
    std::cout << "Figury: " << pieceTexture << "\n";
}

void Settings::SaveSettings() {
    std::ofstream settingsFile("settings.txt");
    std::cout << "Zapisywanie ustawien...\n";
    settingsFile << boardTexture << "\n"
                 << pieceTexture << "\n";
    settingsFile.close();
}

void Settings::ResetSettings() {
    boardTexture = "default";
    pieceTexture = "default";

    std::cout << "Ustawienia zresetowane!\n";
    SaveSettings();
}

void Settings::SetBoardTexture(const std::string &texture) {
    boardTexture = texture;
}

void Settings::SetPieceTexture(const std::string &texture) {
    pieceTexture = texture;
}

void Settings::ChangeSettings() {
    std::cout << "Zmien wyglad planszy:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << boardTextures[i] << "\n";
    }

    int boardTextureChoice;
    std::cin >> boardTextureChoice;

    if (boardTextureChoice >= 1 && boardTextureChoice <= 5) {
      boardTexture = boardTextures[boardTextureChoice - 1];
    } else {
      std::cout << "Zly wybor\n";
    }

    std::cout << "Zmien wyglad figur:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << pieceTextures[i] << "\n";
    }

    int pieceTextureChoice;
    std::cin >> pieceTextureChoice;

    if (pieceTextureChoice >= 1 && pieceTextureChoice <= 5) {
      pieceTexture = pieceTextures[pieceTextureChoice - 1];
    } else {
      std::cout << "Zly wybor\n";
    }

    std::cout << "Ustawienia zmienione!\n";
}

void Settings::DisplaySettingsMenu() {
    char choiceChar = ' ';
    do {
        system("cls");

        std::string choice;
        std::cout << "Menu Ustawien\n";
        std::cout << " 1) Pokaz\n";
        std::cout << " 2) Zmien\n";
        std::cout << " 3) Reset\n";
        std::cout << " 4) Zapis\n";
        std::cout << " q) Exit\n";

        std::cout<<"Wybor: ";

        std::getline(std::cin, choice);

        choiceChar = choice[0];

        system("cls");

        switch (choiceChar) {
            case '1':
                PrintSettings();
                system("pause");
                break;
            case '2':
                ChangeSettings();
                system("pause");
                break;
            case '3':
                ResetSettings();
                system("pause");
                break;
            case '4':
                SaveSettings();
                system("pause");
                break;
            case 'q':
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    } while (choiceChar != 'q');
}