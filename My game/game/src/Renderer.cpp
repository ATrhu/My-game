#include "Renderer.h"

void Renderer::draw(const Ball& ball) {
    DrawCircle(ball.getX(), ball.getY(), ball.getRadius(), RAYWHITE);
}
