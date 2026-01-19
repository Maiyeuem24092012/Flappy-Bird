/**
 * CORE ENGINE - FLAPPY BIRD
 * Logic chính: Trọng lực, Lực nhảy, Tính điểm.
 */

#include <iostream>

class FlappyBirdEngine {
public:
    // Thông số vật lý chuẩn
    float birdY = 256.0f;
    float velocity = 0.0f;
    const float GRAVITY = 0.25f;
    const float JUMP_FORCE = -5.0f;
    
    int score = 0;
    bool isAlive = true;

    // Xử lý nhảy
    void flap() {
        if (isAlive) velocity = JUMP_FORCE;
    }

    // Cập nhật trạng thái (được gọi mỗi khung hình)
    void update() {
        if (!isAlive) return;

        velocity += GRAVITY;
        birdY += velocity;

        // Giới hạn va chạm mặt đất (Base)
        if (birdY > 400) {
            birdY = 400;
            isAlive = false;
        }

        // Logic thắng cuộc
        if (score >= 100) {
            std::cout << "Winner! 100 points reached." << std::endl;
        }
    }
};
