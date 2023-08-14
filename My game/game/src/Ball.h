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
    // Constructors
    Ball();
    Ball(float x, float y, float r);

    // Getter methods
    float getX() const;
    float getY() const;
    float getRadius() const;
    float getMass() const;

    // Setter methods
    void setX(float x);
    void setY(float y);
    void setRadius(float r);
    void setMass(float m);
    void setVelX(float v);
    void setVelY(float v);


    // Movement methods
    void update();
    void applyForce(float force_x, float force_y);
};
