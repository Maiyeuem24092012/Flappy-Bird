/* CORE ENGINE - FLAPPY BIRD (C++ Logic)
   Nhiệm vụ: Tính toán tọa độ chim, tạo ống nước ngẫu nhiên và di chuyển thế giới.
*/

#include <vector>

struct Pipe {
    float x;
    float top;
    float gap = 110.0f;
};

class FlappyEngine {
public:
    float birdY = 250.0f;
    float velocity = 0.0f;
    float gravity = 0.25f;
    float jumpForce = -5.0f;
    
    std::vector<Pipe> pipes;
    float baseX = 0; // Tọa độ mặt đất
    int score = 0;
    bool isAlive = true;

    // Logic này sẽ được JS biên dịch và chạy mỗi khung hình
    void update() {
        if (!isAlive) return;
        
        // 1. Chim rơi
        velocity += gravity;
        birdY += velocity;

        // 2. Thế giới di chuyển (Mặt đất & Ống nước trôi sang trái)
        baseX -= 2.0f; 
        if (baseX <= -288) baseX = 0;
    }
};
