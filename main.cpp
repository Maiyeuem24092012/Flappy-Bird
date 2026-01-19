/**
 * CORE ENGINE - FLAPPY BIRD
 * Chịu trách nhiệm: Trọng lực, Lực nhảy, Tính toán tọa độ.
 */

class BirdBrain {
public:
    float birdY = 250.0f;
    float velocity = 0.0f;
    const float GRAVITY = 0.25f;  // Trọng lực rơi
    const float JUMP = -5.0f;      // Lực nhảy lên

    // Logic xử lý nhảy
    void processJump() {
        velocity = JUMP;
    }

    // Logic cập nhật vật lý mỗi khung hình
    void updatePhysics() {
        velocity += GRAVITY;
        birdY += velocity;

        // Giới hạn va chạm mặt đất (Base)
        if (birdY > 400) {
            birdY = 400;
        }
    }
};
