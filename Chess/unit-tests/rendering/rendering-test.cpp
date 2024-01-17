// ReSharper disable CppClangTidyBugproneSuspiciousInclude
#include "../../src/Movement.h"
#include "../../src/Pos.h"
#include "../../src/Board.cpp"
#include "../../src/Piece.cpp"
#include <gtest/gtest.h>


TEST(RendererTests, Pos) {
  Pos pos1 = Pos(1, 4);
  Pos pos2 = Pos(1, 32);
  
  EXPECT_EQ(Pos(0, 0), Pos(0,0));

  EXPECT_NE(pos1, pos2);
  
  EXPECT_EQ(pos1.x, pos2.x);

  EXPECT_EQ(pos1 + pos2, Pos(2, 36));
}

TEST(RendererTests, BOARD)
{
  Board board;

  EXPECT_EQ(board.getPiece({-1, -1}), nullptr);
  EXPECT_EQ(board.getPiece({4, -1}), nullptr);
  EXPECT_EQ(board.getPiece({-3, 2}), nullptr);
  EXPECT_EQ(board.getPiece({43, 2}), nullptr);
  EXPECT_EQ(board.getPiece({3, 324}), nullptr);
  EXPECT_EQ(board.getPiece({465, 324}), nullptr);

  Piece* king = board.getPiece({4, 0});
  EXPECT_NE(king, nullptr);
  EXPECT_EQ(king->GetPos(), Pos(4, 0));
  EXPECT_EQ(king->GetColor(), Color::WHITE);

  std::vector<Movement> movements = king->GetMoves();

  EXPECT_EQ(movements.size(), 5);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}