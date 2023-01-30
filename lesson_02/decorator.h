#include <iostream>
#include "Bomb.h"

class BombDecorator : public DynamicObject
{
public:
    BombDecorator(Bomb* b) : bomb(b) {}

    void Move(uint16_t time) override {
        bomb->Move(time * 2.0);
    }

    void Draw() const override {
        double x = bomb->GetX();
        double y = bomb->GetY();
        GotoXY(x - 1, y - 1);
        std::cout << "\\|/";
        bomb->Draw();
    }
private:
    Bomb* bomb;
};