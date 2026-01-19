#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

// Liên kết thư viện âm thanh của Windows
#pragma comment(lib, "winmm.lib")

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;
int birdY = 10;
int score = 0;
bool gameOver = false;

struct Pipe {
    int x, gapY;
};

vector<Pipe> pipes;

void Setup() {
    srand(time(NULL));
    pipes.push_back({WIDTH, rand() % (HEIGHT - 6) + 3});
    // Phát nhạc nền từ thư mục assets (Lặp vô tận)
    PlaySound(TEXT("assets/music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void Draw() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

    for (int i = 0; i < WIDTH + 2; i++) cout << "#"; cout << endl;

    for (int y = 0; y < HEIGHT; y++) {
        cout << "#";
        for (int x = 0; x < WIDTH; x++) {
            bool isPipe = false;
            for (auto& p : pipes) {
                if (x == p.x && (y < p.gapY || y > p.gapY + 4)) {
                    cout << "H"; 
                    isPipe = true;
                }
            }
            if (!isPipe) {
                if (x == 5 && y == birdY) cout << "O"; // Con chim
                else cout << " ";
            }
        }
        cout << "#" << endl;
    }

    for (int i = 0; i < WIDTH + 2; i++) cout << "#"; cout << endl;
    cout << "Score: " << score << " / 100 | Bam [SPACE] de nhay!" << endl;

    if (score >= 100) {
        system("cls");
        cout << "============================" << endl;
        cout << "   BAN DA THANG (WINNER)!   " << endl;
        cout << "============================" << endl;
        gameOver = true;
    }
}

void Input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ') birdY -= 3;
    }
}

void Logic() {
    birdY++; 
    if (birdY < 0 || birdY >= HEIGHT) gameOver = true;

    for (int i = 0; i < pipes.size(); i++) {
        pipes[i].x--;
        if (pipes[i].x == 5 && (birdY < pipes[i].gapY || birdY > pipes[i].gapY + 4))
            gameOver = true;
        if (pipes[i].x == 4) score++;
    }

    if (pipes[0].x < 0) {
        pipes.erase(pipes.begin());
        pipes.push_back({WIDTH, rand() % (HEIGHT - 6) + 3});
    }
}

int main() {
    // Ẩn con trỏ chuột trong console để tránh nhấp nháy
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(80); 
    }

    if (score < 100) {
        cout << "GAME OVER! Diem cua ban: " << score << endl;
    }
    
    // Tắt nhạc khi kết thúc
    PlaySound(NULL, 0, 0);
    system("pause");
    return 0;
}
