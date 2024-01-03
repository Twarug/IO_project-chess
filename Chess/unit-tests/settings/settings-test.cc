#include "../../src/Settings.h"
#include <gtest/gtest.h>

class SettingsTest : public ::testing::Test {
protected:
  Settings *settings;

  void SetUp() override { settings = new Settings(); }

  void TearDown() override { delete settings; }
};

TEST_F(SettingsTest, DefaultTextures) {
  EXPECT_EQ(settings->BoardTexture, "default");
  EXPECT_EQ(settings->PieceTexture, "default");
}

TEST_F(SettingsTest, SaveAndLoadSettings) {
  settings->BoardTexture = "wood";
  settings->PieceTexture = "metal";
  settings->SaveSettings();

  Settings loadedSettings;
  EXPECT_EQ(loadedSettings.BoardTexture, "wood");
  EXPECT_EQ(loadedSettings.PieceTexture, "metal");
}

TEST_F(SettingsTest, ResetSettings) {
  settings->BoardTexture = "marble";
  settings->PieceTexture = "stone";
  settings->ResetSettings();

  EXPECT_EQ(settings->BoardTexture, "default");
  EXPECT_EQ(settings->PieceTexture, "default");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
