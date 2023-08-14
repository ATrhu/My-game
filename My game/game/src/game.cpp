
#include "raylib.h"
#include "physics.h"
#include "Ball.h"
#include "Renderer.h"
#include <vector>

// Function to check collision between two balls and adjust their velocities
void checkAndResolveCollision(Ball& ball1, Ball& ball2) {
    float distance = sqrt(pow(ball2.getX() - ball1.getX(), 2) + pow(ball2.getY() - ball1.getY(), 2));
    float sumOfRadii = ball1.getRadius() + ball2.getRadius();

    if (distance < sumOfRadii) {
        // Calculate collision response (elastic collision)
        float normalX = (ball2.getX() - ball1.getX()) / distance;
        float normalY = (ball2.getY() - ball1.getY()) / distance;

        float relativeVelocityX = ball1.getX() - ball2.getX();
        float relativeVelocityY = ball1.getY() - ball2.getY();

        float dotProduct = relativeVelocityX * normalX + relativeVelocityY * normalY;

        if (dotProduct > 0) return;  // The balls are moving away from each other

        // Calculate impulse scalar
        float impulse = (-2.0f * dotProduct) / (ball1.getMass() + ball2.getMass());

        // Apply impulse to each ball's velocity
        ball1.applyForce(impulse * normalX, impulse * normalY);
        ball2.applyForce(-impulse * normalX, -impulse * normalY);
    }
}

int main() {
    const int screenHeight = 1000;
    const int screenWidth = 1920;
    Renderer renderer;
    std::vector<Ball> balls;

    InitWindow(screenWidth, screenHeight, "Physics");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Check for mouse click and create a new ball at the clicked position
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            balls.emplace_back(GetMouseX(), GetMouseY());
        }

        // Check for collisions between balls and adjust their velocities
        for (size_t i = 0; i < balls.size(); ++i) {
            for (size_t j = i + 1; j < balls.size(); ++j) {
                checkAndResolveCollision(balls[i], balls[j]);
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        for (Ball& ball : balls) {
            ball.update();
            renderer.draw(ball);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
