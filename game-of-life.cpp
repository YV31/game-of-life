/*
 *    #     #                  
 *      #     # #                
 *  # # #   # #                  
 *
 * Conway's Game of Life :
 *
 *  - It's universe is an infinite two-dimensional grid of cells,
 * each of which is in one of two possible states, live or dead.
 * Every cell interacts with its eight neighbors.
 * At each step in time, the following transitions occur:
 *
 *  1. Any live cell with fewer than two live neighbors dies by exposure.
 *  2. Any live cell with more than three live neighbors dies by overcrowding.
 *  3. Any live cell with two or three live neighbors survives.
 *  4. Any dead cell with exactly three live neighbors will come to life.
 * ___________________________________________________________________________ 
 * 
 *  Author: YV31 (https://github.com/YV31)
 *
 *  Made with raylib just for fun ;)
 * 
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <raylib.h>

#define T_WHITE "\x1b[38;5;15m\x1b[1m"
#define T_BLACK "\x1b[38;5;16m\x1b[1m"
#define T_RESET_ "\x1b[0m "

using std::array;


const int cell_size = 4;

const int rows = 150;
const int columns = 150;

const int screen_width = (columns - 1) * cell_size;
const int screen_height = (rows - 1) * cell_size;

array<array<bool, columns>, rows> board;

template <size_t rows, size_t columns>
std::uint8_t GetCellNeighborCount(int x, int y,
                             array<array<bool, columns>, rows> &arr);

void SetRandomCells();

void PrintBoard();

void ClearBoard();

void Update();

void UpdateDraw();

void UpdateInput();

void UpdateBoard();

int main(int args, char **argv) {

  InitWindow(screen_width, screen_height, "Conway's Game Of Life");

  SetTargetFPS(120);

  // Glider:
  //  board[2][1] = 1;
  //  board[3][2] = 1;
  //  board[1][3] = 1;
  //  board[2][3] = 1;
  //  board[3][3] = 1;

  //  PrintBoard();

  SetRandomCells();

  while (!WindowShouldClose()) {
    Update();
  }

  CloseWindow();
}

void Update() {
  UpdateInput();
  UpdateBoard();
  UpdateDraw();
}

void UpdateDraw() {
  BeginDrawing();

  ClearBackground(BLACK);

  for (int y = 1; y < rows - 1; y++) {
    for (int x = 1; x < columns - 1; x++) {
      if (board[x][y] == 1)
        DrawRectangle(x * cell_size, y * cell_size, cell_size, cell_size,
                      WHITE);
    }
  }

  EndDrawing();
}

void UpdateInput() {
  if (IsKeyPressed(KEY_R)) {
    ClearBoard();
    SetRandomCells();
  }

  if (IsKeyPressed(KEY_O)) {
    SetTargetFPS(1);
  }

  if (IsKeyPressed(KEY_L)) {
    SetTargetFPS(120);
  }
}

void UpdateBoard() {
  auto arr_copy = board;

  for (int y = 1; y < rows - 2; y++) {
    for (int x = 1; x < columns - 2; x++) {
      uint8_t neighbor = GetCellNeighborCount(x, y, arr_copy);
      bool &current_cell = board[x][y];

      // Rules:
      if (neighbor < 2 && current_cell == 1) {
        current_cell = 0;
      } else if (neighbor > 3 && current_cell == 1) {
        current_cell = 0;
      } else if (neighbor == 3 && current_cell == 0) {
        current_cell = 1;
      }
    }
  }
}

template <size_t rows, size_t columns>
uint8_t GetCellNeighborCount(int x, int y,
                             array<array<bool, columns>, rows> &arr) {
  return arr[x - 1][y - 1] + arr[x][y - 1] + arr[x + 1][y - 1] + 
         arr[x - 1][y] +                     arr[x + 1][y]     + 
         arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1];
}

void SetRandomCells() {
  for (int y = 1; y < rows - 2; y++) {
    for (int x = 1; x < columns - 2; x++) {
      board[x][y] = rand() % 2;
    }
  }
}

void ClearBoard() {
  std::for_each(board.begin(), board.end(), [](auto v) { v.fill(0); });
}

void PrintBoard() {
  for (int y = 1; y < rows - 1; y++) {
    for (int x = 1; x < columns - 1; x++) {
      if (board[x][y] == 1) {
        std::cout << T_WHITE << GetCellNeighborCount(x, y, board) << T_RESET_;
      } else {
        std::cout << T_BLACK << GetCellNeighborCount(x, y, board) << T_RESET_;
      }
    }
    std::cout << "\n";
  }
}
