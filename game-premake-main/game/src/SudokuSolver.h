
#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <vector>
#include <cstdlib>
#include <ctime>

constexpr int BOARD_SIZE = 9;

class SudokuSolver {
public:
    SudokuSolver() : backtracks(0) {
        Reset();
    }

    void Reset() {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                grid[i][j] = 0;
                fixed[i][j] = false;
            }
        }
    }

    void Generate(int numbers) {
        std::srand(std::time(nullptr));
        Reset();
        
        for (int n = 0; n < numbers; ) {
            int x = std::rand() % BOARD_SIZE;
            int y = std::rand() % BOARD_SIZE;
            int value = (std::rand() % BOARD_SIZE) + 1;

            if (grid[x][y] == 0 && IsValidMove(x, y, value)) {
                grid[x][y] = value;
                fixed[x][y] = true;
                n++;
            }
        }
    }

    bool IsValidMove(int x, int y, int value) const {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (grid[i][y] == value || grid[x][i] == value) return false;
        }
        return true;
    }

    bool Solve() {
        backtracks = 0;
        return SolveCell(0, 0);
    }

    int GetValue(int x, int y) const {
        return grid[x][y];
    }

    bool IsFixed(int x, int y) const {
        return fixed[x][y];
    }

    void SetValue(int x, int y, int value) {
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && !fixed[x][y]) {
            grid[x][y] = value;
        }
    }

    int GetBacktracks() const {
        return backtracks;
    }

private:
    bool SolveCell(int x, int y) {
        if (x == BOARD_SIZE) {
            x = 0;
            if (++y == BOARD_SIZE) {
                return true;
            }
        }
        
        if (grid[x][y] != 0) {
            return SolveCell(x + 1, y);
        }
        
        for (int value = 1; value <= BOARD_SIZE; value++) {
            if (IsValidMove(x, y, value)) {
                grid[x][y] = value;
                if (SolveCell(x + 1, y)) {
                    return true;
                }
            }
        }

        backtracks++;
        grid[x][y] = 0;
        return false;
    }

    int grid[BOARD_SIZE][BOARD_SIZE];
    bool fixed[BOARD_SIZE][BOARD_SIZE];
    int backtracks;
};

#endif // SUDOKUSOLVER_H
