/* CORE ENGINE - FLAPPY BIRD
   Logic: Gravity (0.25), Jump (-5.0), Win (100 points)
*/

class BirdLogic {
public:
    float y = 250.0f;
    float velocity = 0.0f;
    int score = 0;
    bool isAlive = true;

    void applyGravity() {
        if (isAlive) {
            velocity += 0.25f;
            y += velocity;
        }
    }

    void flap() {
        if (isAlive) velocity = -5.0f;
    }
};
