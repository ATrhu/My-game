#include "raylib.h"
#include "physics.h"
#include "Ball.h"

int main() {
    int screenHeight = 800, screenWidth = 1080;

    InitWindow(screenWidth, screenHeight, "Physics");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
