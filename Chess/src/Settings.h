#include <fstream>
#include <iostream>
#include <string>

std::string boardTextures[] = {"default", "wood", "marble", "stone", "metal"};
std::string pieceTextures[] = {"default", "wood", "marble", "stone", "metal"};

class Settings {
private:
  std::string boardTexture;
  std::string pieceTexture;

public:
  Settings() {
    std::ifstream settingsFile("../settings.txt");
    settingsFile >> boardTexture >> pieceTexture;
    settingsFile.close();
  }

  void PrintSettings() {
    std::cout << "Board Texture: " << boardTexture << "\n";
    std::cout << "Piece Texture: " << pieceTexture << "\n";
  }

  void SaveSettings() {
    std::ofstream settingsFile("../settings.txt");
    std::cout << "Saving settings...\n";
    settingsFile << boardTexture << "\n"
                 << pieceTexture << "\n";
    settingsFile.close();
  }
  
  void ResetSettings() {
    boardTexture = "default";
    pieceTexture = "default";

    SaveSettings();
  }

  void SetBoardTexture(const std::string &texture) {
    boardTexture = texture;
  }

  void SetPieceTexture(const std::string &texture) {
    pieceTexture = texture;
  }

  void ChangeSettings() {
    std::cout << "Change board texture:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << boardTextures[i] << "\n";
    }

    int boardTextureChoice;
    std::cin >> boardTextureChoice;

    if (boardTextureChoice >= 1 && boardTextureChoice <= 5) {
      boardTexture = boardTextures[boardTextureChoice - 1];
    } else {
      std::cout << "Invalid choice\n";
    }

    std::cout << "Change piece texture:\n";

    for (int i = 0; i < 5; i++) {
      std::cout << " " << i + 1 << ". " << pieceTextures[i] << "\n";
    }

    int pieceTextureChoice;
    std::cin >> pieceTextureChoice;

    if (pieceTextureChoice >= 1 && pieceTextureChoice <= 5) {
      pieceTexture = pieceTextures[pieceTextureChoice - 1];
    } else {
      std::cout << "Invalid choice\n";
    }

    std::cout << "Settings changed successfully\n";
  }
};