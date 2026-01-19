/* CORE ENGINE - FLAPPY BIRD
   File này quản lý logic: Trọng lực, Va chạm, Tính điểm.
*/

#include <iostream>

class FlappyEngine {
public:
    // Các thông số vật lý (Đơn vị: Pixel)
    float birdY = 256.0f;
    float velocity = 0.0f;
    const float GRAVITY = 0.25f;
    const float JUMP_FORCE = -5.0f;
    
    int score = 0;
    bool isAlive = true;

    // Bộ xử lý nhảy (Flap)
    void onInput() {
        if (!isAlive) return;
        velocity = JUMP_FORCE;
    }

    // Bộ xử lý logic mỗi khung hình (Update)
    void step() {
        if (!isAlive) return;

        velocity += GRAVITY;
        birdY += velocity;

        // Kiểm tra va chạm mặt đất (Base ở tọa độ 400)
        if (birdY > 400) {
            birdY = 400;
            isAlive = false;
        }

        // Kiểm tra điều kiện thắng
        if (score >= 100) {
            std::cout << "WINNER! 100 POINTS REACHED." << std::endl;
        }
    }
};
