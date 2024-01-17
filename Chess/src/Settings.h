#include <fstream>
#include <iostream>
#include <string>

std::string boardTextures[] = {"default", "wood", "marble", "stone", "metal"};
std::string pieceTextures[] = {"default", "wood", "marble", "stone", "metal"};

class Settings {
public:
  std::string BoardTexture;
  std::string PieceTexture;

  Settings(std::string boardTexture, std::string pieceTexture)
      : BoardTexture(boardTexture), PieceTexture(pieceTexture) {}

  void PrintSettings() const {
    std::cout << "Board Texture: " << BoardTexture << "\n";
    std::cout << "Piece Texture: " << PieceTexture << "\n";
  }
};

class SettingsBuilder {
private:
  std::string boardTexture = "default";
  std::string pieceTexture = "default";

public:
  SettingsBuilder &SetBoardTexture(const std::string &texture) {
    boardTexture = texture;
    return *this;
  }

  SettingsBuilder &SetPieceTexture(const std::string &texture) {
    pieceTexture = texture;
    return *this;
  }

#include <fstream> // Include the necessary header file

  static void SaveSettings(const Settings &settings) {
    std::ofstream settingsFile("settings.txt");
    std::cout << "Saving settings...\n";
    settingsFile << settings.BoardTexture << "\n"
                 << settings.PieceTexture << "\n";
    settingsFile.close();
  }

  SettingsBuilder &ChangeSettings() {
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

    return *this;
  }

  SettingsBuilder &ResetSettings() {
    boardTexture = "default";
    pieceTexture = "default";
    return *this;
  }

  Settings Build() { return Settings(boardTexture, pieceTexture); }
};