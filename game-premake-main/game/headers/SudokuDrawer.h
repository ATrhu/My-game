
#ifndef SUDOKUDRAWER_H
#define SUDOKUDRAWER_H

#include "raylib.h"
#include "SudokuSolver.h"

class SudokuDrawer {
public:
    SudokuDrawer(SudokuSolver& solver) : sudoku(solver) {}

    void Draw() const {
        int offsetX = (SCREEN_WIDTH - (CELL_SIZE * BOARD_SIZE)) / 2;
        int offsetY = (SCREEN_HEIGHT - (CELL_SIZE * BOARD_SIZE)) / 2;

        // Draw Sudoku Grid
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int x = offsetX + i * CELL_SIZE;
                int y = offsetY + j * CELL_SIZE;
                int value = sudoku.GetValue(i, j);
                bool isFixed = sudoku.IsFixed(i, j);

                if (isFixed) {
                    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
                } else {
                    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, RAYWHITE);
                }
                
                DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, GRAY);

                if (value != 0) {
                    char number[2];
                    std::sprintf(number, "%d", value);
                    int textWidth = MeasureText(number, 20);
                    int textHeight = 20;
                    DrawText(number, x + (CELL_SIZE - textWidth) / 2, y + (CELL_SIZE - textHeight) / 2, 20, BLACK);
                }
            }
        }

        // Draw Solve and Reset buttons
        DrawRectangle(10, 10, BUTTON_WIDTH, BUTTON_HEIGHT, RAYWHITE);
        DrawText("Solve", 45, 25, 20, BLACK);

        DrawRectangle(10, 70, BUTTON_WIDTH, BUTTON_HEIGHT, RAYWHITE);
        DrawText("Reset", 45, 85, 20, BLACK);
    }

    bool CheckSolveButtonPressed() const {
        return CheckCollisionPointRec(GetMousePosition(), {10.0f, 10.0f, BUTTON_WIDTH, BUTTON_HEIGHT}) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    }

    bool CheckResetButtonPressed() const {
        return CheckCollisionPointRec(GetMousePosition(), {10.0f, 70.0f, BUTTON_WIDTH, BUTTON_HEIGHT}) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
    }

private:
    SudokuSolver& sudoku;
    constexpr static int SCREEN_WIDTH = 800;
    constexpr static int SCREEN_HEIGHT = 600;
    constexpr static int CELL_SIZE = 50;
    constexpr static int BUTTON_WIDTH = 150;
    constexpr static int BUTTON_HEIGHT = 50;
};

#endif // SUDOKUDRAWER_H
