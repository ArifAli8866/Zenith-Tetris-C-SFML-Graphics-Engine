#include <SFML/Graphics.hpp>
#include <time.h>
#include <sstream>

using namespace sf;

const int M = 20;
const int N = 10;
int field[M][N] = {0};

struct Point { int x, y; } a[4], b[4];

int figures[7][4] = {
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

enum State { MENU, GAME, ABOUT };

bool check() {
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;
    return 1;
};

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), "Tetris by Arif Ali");
    window.setFramerateLimit(60);

    Texture t1, t2, t3, tMenu, tAbout;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");
    tMenu.loadFromFile("images/menu.png");
    tAbout.loadFromFile("images/about.png");

    Sprite s(t1), background(t2), frame(t3), sMenu(tMenu), sAbout(tAbout);

    // Font for Score
    Font font;
    font.loadFromFile("fonts/arial.ttf"); 
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(200, 100);

    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;
    int score = 0;
    State currentState = MENU;
    Clock clock;

    // Initial piece spawn
    int n = rand() % 7;
    for (int i = 0; i < 4; i++) {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
    }

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) window.close();

            if (e.type == Event::KeyPressed) {
                if (currentState == MENU) {
                    if (e.key.code == Keyboard::P) currentState = GAME;
                    if (e.key.code == Keyboard::A) currentState = ABOUT;
                    if (e.key.code == Keyboard::E) window.close();
                } 
                else if (currentState == ABOUT || currentState == GAME) {
                    if (e.key.code == Keyboard::M || e.key.code == Keyboard::Escape) currentState = MENU;
                }

                if (currentState == GAME) {
                    if (e.key.code == Keyboard::Up) rotate = true;
                    else if (e.key.code == Keyboard::Left) dx = -1;
                    else if (e.key.code == Keyboard::Right) dx = 1;
                }
            }
        }

        if (currentState == GAME) {
            if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

            // Move
            for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
            if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

            // Rotate
            if (rotate) {
                Point p = a[1];
                for (int i = 0; i < 4; i++) {
                    int x = a[i].y - p.y;
                    int y = a[i].x - p.x;
                    a[i].x = p.x - x;
                    a[i].y = p.y + y;
                }
                if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
            }

            // Tick
            if (timer > delay) {
                for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

                if (!check()) {
                    for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;
                    colorNum = 1 + rand() % 7;
                    int n = rand() % 7;
                    for (int i = 0; i < 4; i++) {
                        a[i].x = figures[n][i] % 2;
                        a[i].y = figures[n][i] / 2;
                    }
                }
                timer = 0;
            }

            // Check lines and update Score
            int k = M - 1;
            for (int i = M - 1; i > 0; i--) {
                int count = 0;
                for (int j = 0; j < N; j++) {
                    if (field[i][j]) count++;
                    field[k][j] = field[i][j];
                }
                if (count < N) k--;
                else score += 100; // Increase score per line
            }

            dx = 0; rotate = 0; delay = 0.3;

            std::stringstream ss;
            ss << "Score:\n" << score;
            scoreText.setString(ss.str());
        }

        // Draw
        window.clear(Color::White);
        if (currentState == MENU) {
            window.draw(sMenu);
        } else if (currentState == ABOUT) {
            window.draw(sAbout);
        } else if (currentState == GAME) {
            window.draw(background);
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    if (field[i][j] == 0) continue;
                    s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
                    s.setPosition(j * 18, i * 18);
                    s.move(28, 31);
                    window.draw(s);
                }
            for (int i = 0; i < 4; i++) {
                s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
                s.setPosition(a[i].x * 18, a[i].y * 18);
                s.move(28, 31);
                window.draw(s);
            }
            window.draw(frame);
            window.draw(scoreText);
        }
        window.display();
    }
    return 0;
}
