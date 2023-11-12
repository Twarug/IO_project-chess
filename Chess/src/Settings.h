#pragma once
#include <fstream>
#include <iostream>
#include <string>

std::string boardTextures[] = {"default", "wood", "marble", "stone", "metal"};
std::string pieceTextures[] = {"default", "wood", "marble", "stone", "metal"};

struct Settings {
  std::string BoardTexture = "default";
  std::string PieceTexture = "default";

  Settings() {
    std::ifstream settingsFile("settings.txt");
    if (settingsFile.is_open()) {
      std::string line;
      int lineNum = 0;

      while (getline(settingsFile, line)) {
        switch (lineNum) {
        case 0:
          BoardTexture = line;
          break;
        case 1:
          PieceTexture = line;
          break;
        default:
          std::cout << "Invalid line in settings file\n";
          break;
        }
        lineNum++;
      }
    }
    settingsFile.close();
  }

  void PrintSettings() {
    std::cout << "Board Texture: " << BoardTexture << "\n";
    std::cout << "Piece Texture: " << PieceTexture << "\n";
  }

  void SaveSettings() {
    std::ofstream settingsFile("settings.txt");
    std::cout << "Saving settings...\n";
    settingsFile << BoardTexture << "\n" << PieceTexture << "\n";
    settingsFile.close();
  }

  void ChangeSettings() {

    std::cout << "Change board texture:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << boardTextures[i] << "\n";
    }

    int boardTextureChoice;
    std::cin >> boardTextureChoice;

    switch (boardTextureChoice) {
    case 1:
      BoardTexture = boardTextures[0];
      break;
    case 2:
      BoardTexture = boardTextures[1];
      break;
    case 3:
      BoardTexture = boardTextures[2];
      break;
    case 4:
      BoardTexture = boardTextures[3];
      break;
    case 5:
      BoardTexture = boardTextures[4];
      break;
    default:
      std::cout << "Invalid choice\n";
      break;
    }

    std::cout << "Change piece texture:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << pieceTextures[i] << "\n";
    }

    int pieceTextureChoice;
    std::cin >> pieceTextureChoice;

    switch (pieceTextureChoice) {
    case 1:
      PieceTexture = pieceTextures[0];
      break;
    case 2:
      PieceTexture = pieceTextures[1];
      break;
    case 3:
      PieceTexture = pieceTextures[2];
      break;
    case 4:
      PieceTexture = pieceTextures[3];
      break;
    case 5:
      PieceTexture = pieceTextures[4];
      break;
    default:
      std::cout << "Invalid choice\n";
      break;
    }

    SaveSettings();

    std::cout << "Settings changed successfully\n";
  }

  void ResetSettings() {
    BoardTexture = "default";
    PieceTexture = "default";
  }
};