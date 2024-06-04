#include <SFML/Graphics.hpp>
#include <vector>

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

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    Snake snake(20.0f);

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
        }

        window.clear();
        snake.Render(window);
        window.display();
    }

    return 0;
}
