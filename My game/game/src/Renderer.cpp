
#include "Renderer.h"

void Renderer::draw(const Ball& ball) {
    // Draw the ball using raylib's DrawCircle function
    DrawCircle(ball.getX(), ball.getY(), ball.getRadius(), RAYWHITE);
}
