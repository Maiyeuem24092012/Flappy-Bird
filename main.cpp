/* CORE ENGINE - FULL MOVEMENT LOGIC */
#include <vector>

struct Pipe {
    float x;
    float topHeight;
    float gap = 110.0f;
    bool passed = false;
};

class GameCore {
public:
    float birdY = 250.0f;
    float velocity = 0.0f;
    std::vector<Pipe> pipes;
    float baseX = 0;
    int score = 0;
    bool isAlive = true;

    void update() {
        if (!isAlive) return;

        // Logic vật lý chim
        velocity += 0.25f; 
        birdY += velocity;

        // Logic cuộn mặt đất (tạo cảm giác di chuyển)
        baseX -= 2.0f;
        if (baseX <= -288) baseX = 0;

        // Logic quản lý ống nước sẽ được Renderer (JS) thực thi dựa trên các biến này
    }
};
