
#include "Ball.h"

// Default constructor
Ball::Ball() : position_x(0.0f), position_y(0.0f), velocity_x(5.0f), velocity_y(5.0f), radius(20.0f), mass(1.0f) {}

// Parameterized constructor
Ball::Ball(float x, float y, float vel_x, float vel_y, float r) :
    position_x(x), position_y(y), velocity_x(vel_x), velocity_y(vel_y), radius(r), mass(1.0f) {}

float Ball::getX() const {
    return position_x;
}

float Ball::getY() const {
    return position_y;
}

float Ball::getRadius() const {
    return radius;
}

float Ball::getMass() const {
    return mass;
}

void Ball::update() {
    if (position_x - radius <= 0 || position_x + radius >= 1920) {
        velocity_x = -velocity_x;
    }
    if (position_y - radius <= 0 || position_y + radius >= 1000) {
        velocity_y *= -1;
    }
    position_x += velocity_x;
    position_y += velocity_y;
}

void Ball::applyForce(float force_x, float force_y) {
    velocity_x += force_x / mass;
    velocity_y += force_y / mass;
}
