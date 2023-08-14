#include "raylib.h"
#include "physics.h"
#include "Ball.h"
#include "Renderer.h"

int main() {
    int screenHeight = 1000, screenWidth = 1920;
    Renderer renderer;
    Ball ball;
    ball.setX(100);
    ball.setY(100);
    ball.setRadius(40);
    ball.setVelX(5);
    ball.setVelY(5);

    InitWindow(screenWidth, screenHeight, "Physics");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        ball.update();
        renderer.draw(ball);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}
