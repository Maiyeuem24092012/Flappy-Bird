/* CORE ENGINE - FLAPPY BIRD 
   Logic xử lý: Trọng lực, Lực nhảy, Va chạm mặt đất.
*/

class GameCore {
public:
    float birdY = 256.0f;     // Vị trí chim
    float velocity = 0.0f;   // Vận tốc rơi
    const float GRAVITY = 0.25f;  // Trọng lực
    const float JUMP_FORCE = -4.5f; // Lực nhảy

    void update() {
        velocity += GRAVITY;
        birdY += velocity;
        
        // Logic: Nếu chạm đất (tọa độ 400) thì chết
        if (birdY > 400) birdY = 400;
    }

    void flap() {
        velocity = JUMP_FORCE;
    }
};
