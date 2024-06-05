#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

#define BLOCK_SIZE 20.0f

using namespace std;

enum Direction { Up, Down, Left, Right };

class GlobalData{
public:

    sf::Text    scoreText;
    sf::Font    font;
    int         score           = 0;
    string      msg_paint       = "paint";
    string      msg_collision   = "collision";
    string      msg_score       = "score";



    GlobalData() : score(0) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cout<<"no font"<<std::endl;
        }
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, 10);
    }

};


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
    virtual ~Apple();
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

Apple::~Apple() = default;

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


class Observer{
public:
    virtual void Update(string& message) = 0;
};

class ScoreObserver : public Observer{
private:
    int Score;
public:
    void Update(string& message) override{
        if(message=="score"){
            cout<<"Score update"<<endl;
        }
        /*
         * TODO:
         * 如果消息是分数，进行分数的更新
         *
         *
         * */
    }
};

class PaintObserver : public Observer{
private:
    //TODO:这里改成整个场景内的所有物品的指针的vector，也就是vector<shared_ptr<GameObject>>
    shared_ptr<Snake>       snake;
    shared_ptr<Fruit>       goodFruit;
    sf::RenderWindow&       window;
    GlobalData&             globalData;
    //Mine mine;
public:
    PaintObserver(shared_ptr<Snake>& snake,shared_ptr<Fruit>& goodFruit,sf::RenderWindow& window,GlobalData& globalData):
        snake(snake),goodFruit(goodFruit),window(window),globalData(globalData){}
    void Update(string& message) override{
        //cout<<"Paint update"<<endl;
        /*
         * TODO:
         * 如果消息是绘制，进行物品的绘制
         *
         * */
        if(message=="paint"){
            globalData.scoreText.setString("Score: " + std::to_string(globalData.score));
            window.clear();
            snake->Render(window);
            goodFruit->Render(window);
            window.draw(globalData.scoreText);
            window.display();
        }
    }
};

class CollisionObserver : public Observer{
public:
    void Update(string& message) override{
        if(message=="collision"){
            cout<<"Collision check and update"<<endl;
        }

        /*
         * TODO:
         * 如果消息是碰撞死，进行结算死亡
         * 如果碰撞果子，结算分数
         * */
    }
};

class Subject{
private:
    vector<shared_ptr<Observer>>    observers;
    string                          state;
public:
    void Attatch(shared_ptr<Observer> &observer){
        observers.push_back(observer);
    }
    void UpdateState(string& newState){
        this->state = newState;
        Notify(newState);
    }
    void Notify(string& message){
        for(auto observer : observers){
            observer->Update(message);
        }
    }
};




int main() {


    srand(static_cast<unsigned>(time(0)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

    GlobalData globalData;




    shared_ptr<Snake> snake = make_shared<Snake>();
    shared_ptr<Fruit> apple = make_shared<Apple>();

    shared_ptr<Subject>             subject                 =   make_shared<Subject>();

    shared_ptr<Observer>            scoreObserver           =   make_shared<ScoreObserver>();
    shared_ptr<Observer>            collisionObserver       =   make_shared<CollisionObserver>();
    shared_ptr<Observer>            paintObserver           =   make_shared<PaintObserver>(snake,apple,window,globalData);

    subject ->  Attatch(scoreObserver);
    subject ->  Attatch(collisionObserver);
    subject ->  Attatch(paintObserver);

    apple->Respawn();


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
                    snake -> ChangeDirection(Up);
                } else if (event.key.code == sf::Keyboard::S) {
                    snake -> ChangeDirection(Down);
                } else if (event.key.code == sf::Keyboard::A) {
                    snake -> ChangeDirection(Left);
                } else if (event.key.code == sf::Keyboard::D) {
                    snake -> ChangeDirection(Right);
                }
            }
        }

        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (timer > delay) {
            timer = 0;
            snake -> Update();

            if (snake->CheckCollision()) {
                // 处理蛇碰撞
                window.close();
            }

            if (snake -> CheckAppleCollision(dynamic_pointer_cast<Apple>(apple)->getPosition())) {
                snake -> Grow();
                apple -> Respawn();
                globalData.score++;
            }
        }

        subject -> UpdateState(globalData.msg_paint);

        /*globalData.scoreText.setString("Score: " + std::to_string(globalData.score));
        window.clear();
        snake->Render(window);
        apple->Render(window);
        window.draw(globalData.scoreText);
        window.display();*/
    }

    return 0;
}
