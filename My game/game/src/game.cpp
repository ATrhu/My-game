#include "raylib.h"
#include "physics.h"

int main() {
    int screenHeight = 800, screenWidth = 1080;

    InitWindow(screenWidth, screenHeight, "Physics");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
