/* ADVANCED CORE ENGINE - FLAPPY BIRD */
#include <vector>

enum GameState { START, PLAYING, GAMEOVER };

class FlappyBrain {
public:
    GameState state = START;
    float birdY = 256.0f;
    float velocity = 0.0f;
    int score = 0;
    int highScore = 0;

    // Logic xử lý khi người chơi tác động (Phím cách hoặc Chuột)
    void handleInput() {
        if (state == START) {
            state = PLAYING;
            velocity = -4.5f;
        } else if (state == PLAYING) {
            velocity = -4.5f;
        } else if (state == GAMEOVER) {
            reset();
        }
    }

    void reset() {
        state = START;
        birdY = 256.0f;
        velocity = 0.0f;
        score = 0;
    }
};
