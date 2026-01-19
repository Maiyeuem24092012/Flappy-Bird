/* CORE LOGIC ENGINE - FLAPPY BIRD */
#include <iostream>

class BirdEngine {
public:
    float y = 250.0f;
    float velocity = 0.0f;
    const float GRAVITY = 0.25f;
    const float JUMP = -4.5f;

    void update() {
        velocity += GRAVITY;
        y += velocity;
        if (y > 400) y = 400; // Giới hạn chạm đất
    }
};
