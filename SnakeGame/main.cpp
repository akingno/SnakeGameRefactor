#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

// 定义方向
enum Direction { Up, Down, Left, Right };

// 蛇类
class Snake {
public:
    Snake(float blockSize);
    ~Snake();

    void Update();
    void Render(sf::RenderWindow& window);
    void ChangeDirection(Direction newDirection);
    void Grow();
    bool CheckCollision();
    bool CheckAppleCollision(sf::Vector2f applePosition);

private:
    float blockSize;
    std::vector<sf::RectangleShape> body;
    Direction direction;
    bool grow;
};

Snake::Snake(float blockSize) : blockSize(blockSize), direction(Right), grow(false) {
    body.push_back(sf::RectangleShape(sf::Vector2f(blockSize, blockSize)));
    body.back().setFillColor(sf::Color::Green);
    body.back().setPosition(blockSize * 5, blockSize * 5);
}

Snake::~Snake() {}

void Snake::Update() {
    if (grow) {
        body.push_back(sf::RectangleShape(sf::Vector2f(blockSize, blockSize)));
        body.back().setFillColor(sf::Color::Green);
        grow = false;
    } else {
        for (size_t i = body.size() - 1; i > 0; --i) {
            body[i].setPosition(body[i - 1].getPosition());
        }
    }

    switch (direction) {
        case Up:
            body[0].move(0, -blockSize);
            break;
        case Down:
            body[0].move(0, blockSize);
            break;
        case Left:
            body[0].move(-blockSize, 0);
            break;
        case Right:
            body[0].move(blockSize, 0);
            break;
    }
}

void Snake::Render(sf::RenderWindow& window) {
    for (auto& segment : body) {
        window.draw(segment);
    }
}

void Snake::ChangeDirection(Direction newDirection) {
    direction = newDirection;
}

void Snake::Grow() {
    grow = true;
}

bool Snake::CheckCollision() {
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[0].getPosition() == body[i].getPosition()) {
            return true;
        }
    }
    return false;
}

bool Snake::CheckAppleCollision(sf::Vector2f applePosition) {
    if (body[0].getPosition() == applePosition) {
        return true;
    }
    return false;
}

// 苹果类
class Apple {
public:
    Apple(float blockSize);
    void Respawn();
    void Render(sf::RenderWindow& window);

    sf::Vector2f getPosition();

private:
    float blockSize;
    sf::CircleShape appleShape;
};

Apple::Apple(float blockSize) : blockSize(blockSize) {
    appleShape.setRadius(blockSize / 2);
    appleShape.setFillColor(sf::Color::Red);
    Respawn();
}

void Apple::Respawn() {
    int maxX = 800 / static_cast<int>(blockSize);
    int maxY = 600 / static_cast<int>(blockSize);
    int x = std::rand() % maxX * static_cast<int>(blockSize);
    int y = std::rand() % maxY * static_cast<int>(blockSize);
    appleShape.setPosition(x, y);
}

void Apple::Render(sf::RenderWindow& window) {
    window.draw(appleShape);
}

sf::Vector2f Apple::getPosition() {
    return appleShape.getPosition();
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    Snake snake(20.0f);
    Apple apple(20.0f);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout<<"no font"<<std::endl;
        return -1; // 确保字体文件存在
    }

    int score = 0;
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    sf::Clock clock;
    float timer = 0.0f, delay = 0.1f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::W) {
                    snake.ChangeDirection(Up);
                } else if (event.key.code == sf::Keyboard::S) {
                    snake.ChangeDirection(Down);
                } else if (event.key.code == sf::Keyboard::A) {
                    snake.ChangeDirection(Left);
                } else if (event.key.code == sf::Keyboard::D) {
                    snake.ChangeDirection(Right);
                }
            }
        }

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (timer > delay) {
            timer = 0;
            snake.Update();

            if (snake.CheckCollision()) {
                // 处理蛇碰撞
                window.close();
            }

            if (snake.CheckAppleCollision(apple.getPosition())) {
                snake.Grow();
                apple.Respawn();
                score++;
            }
        }

        scoreText.setString("Score: " + std::to_string(score));

        window.clear();
        snake.Render(window);
        apple.Render(window);
        window.draw(scoreText);
        window.display();
    }

    return 0;
}
