#include "raylib.h"



int main() {


    int screenHeight = 800, screenWidth = 600;

    InitWindow(screenWidth,screenHeight, "Physics");
    SetTargetFPS(60);

    
    while (!WindowShouldClose()) 

    BeginDrawing();
    ClearBackground(RAYWHITE);

    EndDrawing();
    

    CloseWindow();
    return 0;
}
