#include "Ball.h"
#include "physics.h"  // To access the acceleration due to gravity

Ball::Ball() : position_x(0.0f), position_y(0.0f), velocity_x(0.0f), velocity_y(0.0f), radius(1.0f), mass(1.0f) {}

Ball::Ball(float x, float y, float r) : position_x(x), position_y(y), velocity_x(0.0f), velocity_y(0.0f), radius(r), mass(1.0f) {}

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

void Ball::setX(float x) {
    position_x = x;
}

void Ball::setY(float y) {
    position_y = y;
}

void Ball::setRadius(float r) {
    radius = r;
}

void Ball::setMass(float m) {
    mass = m;
}

void Ball::setVelX(float v) {
    velocity_x = v;
}

void Ball::setVelY(float v) {
    velocity_y = v;
}

void Ball::update() {
    if (position_x - radius <= 0 || position_x + radius >= 1920) {
        velocity_x = -velocity_x;
    }
    if (position_y - radius <= 0 || position_y + radius >= 1000) {
        velocity_y *= -1;
    }
    //velocity_y += gravityY;  // Apply gravitational acceleration
    position_x += velocity_x;
    position_y += velocity_y;

}

void Ball::applyForce(float force_x, float force_y) {
    velocity_x += force_x / mass;
    velocity_y += force_y / mass;
}
