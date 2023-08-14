
#pragma once

class Ball {
private:
    float position_x;
    float position_y;
    float velocity_x;
    float velocity_y;
    float radius;
    float mass;

public:
    // Default constructor
    Ball();

    // Parameterized constructor
    Ball(float x, float y, float vel_x = 5.0f, float vel_y = 5.0f, float r = 20.0f);

    // Getter methods
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getMass() const;

    // Movement methods
    void update();
    void applyForce(float force_x, float force_y);
};
