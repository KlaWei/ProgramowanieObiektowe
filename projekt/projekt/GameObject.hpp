
#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class GameObject {
public:
    float get_velocity() { return velocity; }
    void accelerate() { velocity = velocity + acceleration; }
    void set_velocity(float v) { velocity = v; }
    void set_acceleration(float a) { acceleration = a; }
protected:
    float velocity;
    float acceleration;
};

#endif
