#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#define BLOCK_SIZE 20.0f

using namespace std;

enum Direction { Up, Down, Left, Right };

class GameObject{
public:
    GameObject();
    virtual ~GameObject();
    virtual void Render(sf::RenderWindow& window) = 0;
};

GameObject::GameObject() = default;
GameObject::~GameObject() = default;


class Fruit : public GameObject{
public:
    Fruit();
    virtual ~Fruit();
    virtual void Respawn()=0;
    virtual void Eaten()=0;
};

Fruit::Fruit()  = default;
Fruit::~Fruit() = default;

class Snake : public GameObject{
public:
    Snake();
    void Update();
    void Render(sf::RenderWindow& window) override;
    void ChangeDirection(Direction newDirection);
    void Grow();
    bool CheckCollision();
    bool CheckAppleCollision(sf::Vector2f applePosition);

private:
    int lifeCount;
    vector<sf::RectangleShape> body;
    Direction direction;
    bool grow;
};

void Snake::Render(sf::RenderWindow& window){
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


class Apple : public Fruit{
public:
    Apple();
    void Respawn() override;
    void Render(sf::RenderWindow& window) override;
    void Eaten() override;

    sf::Vector2f getPosition();

private:
    sf::CircleShape appleShape;
};

Apple::Apple(){
    appleShape.setRadius(BLOCK_SIZE / 2);
    appleShape.setFillColor(sf::Color::Red);
}

void Apple::Respawn() {
    int maxX = 800 / static_cast<int>(BLOCK_SIZE);
    int maxY = 600 / static_cast<int>(BLOCK_SIZE);
    int x = std::rand() % maxX * static_cast<int>(BLOCK_SIZE);
    int y = std::rand() % maxY * static_cast<int>(BLOCK_SIZE);
    appleShape.setPosition(x, y);
}

void Apple::Render(sf::RenderWindow& window){
    window.draw(appleShape);
}

sf::Vector2f Apple::getPosition() {
    return appleShape.getPosition();
}

void Apple::Eaten() {
    cout<<"eaten"<<endl;
}

class GameObjectFactory{
public:
    virtual GameObject* Manufacture() = 0;
};

class AppleFactory : GameObjectFactory{
    Apple* Manufacture() override{
        auto* apple = new Apple();
        return apple;
    }
};

class SnakeFactory : GameObjectFactory{
    Snake* Manufacture() override{
        auto* snake = new Snake();
        return snake;
    }
};

class Observer{
public:
    virtual void Update();
};

class ScoreObserver : Observer{
private:
    int Score;
public:
    void Update(){

    }
};

class PaintObserver : Observer{
private:
    Snake* snake;
    Fruit* goodFruit;
    //Mine mine;
public:
    PaintObserver(Snake *snake,Fruit *goodFruit):
        snake(snake),goodFruit(goodFruit){}
    void Update(){

    }
};

class CollisionObserver:Observer{
public:
    void Update(){

    }
};

class Subject{
private:
    vector<Observer> observers;
public:
    void Attatch(Observer observer){
        observers.push_back(observer);
    }
};


Snake::Snake() : direction(Right), grow(false),lifeCount(1){
    body.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE)));
    body.back().setFillColor(sf::Color::Green);
    body.back().setPosition(BLOCK_SIZE * 5, BLOCK_SIZE * 5);
}

void Snake::Update(){
    if (grow) {
        body.push_back(sf::RectangleShape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE)));
        body.back().setFillColor(sf::Color::Green);
        grow = false;
    } else {
        for (size_t i = body.size() - 1; i > 0; --i) {
            body[i].setPosition(body[i - 1].getPosition());
        }
    }

    switch (direction) {
        case Up:
            body[0].move(0, -BLOCK_SIZE);
            break;
        case Down:
            body[0].move(0, BLOCK_SIZE);
            break;
        case Left:
            body[0].move(-BLOCK_SIZE, 0);
            break;
        case Right:
            body[0].move(BLOCK_SIZE, 0);
            break;
    }
}







int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");
    Snake snake;
    Apple apple;
    apple.Respawn();

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
