#pragma once

#include <iostream>

class Settings {
private:
  std::string boardTexture;
  std::string pieceTexture;

public:
  Settings();

  void PrintSettings();
  void SaveSettings();
  void ResetSettings();

  void SetBoardTexture(const std::string &texture);
  void SetPieceTexture(const std::string &texture);
  void ChangeSettings();

  void DisplaySettingsMenu();
};