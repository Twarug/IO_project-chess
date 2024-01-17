#include "Utils.h"

#include <windows.h>

void ResetCuror(Pos pos) {
  HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(output, { (short)pos.x, (short)pos.y });
}