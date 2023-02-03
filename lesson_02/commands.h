#include <vector>
#include "GameObject.h"
#include "Plane.h"
#include "Bomb.h"

class Command
{
public:
    virtual void execute() = 0;
};

/*
* По заданию нужно было создать две команды на удаление статического и динамического объектов,
* но можно же это реализовать одной командой, передавая вектор указателей и указатель на объект
* родительского класса, логика-то удаления одна и та же - бежим по вектору, находим объект, удаляем
* В самом классе SBomber осуществядется вызов либо
* DeleteObjectCommand command(pBomb, vecDynamicObj);
* либо, установкой через setParams(pObj, vecStaticObj);
* и можно, создав одну команду использовать ее для удаления разных типов объектов
* или я что-то не правильно понимаю?
*/
class DeleteObjectCommand : public Command
{
private:
    std::vector<GameObject*> objects;
    GameObject* gameObject;

public:
    DeleteObjectCommand() : gameObject(nullptr) {}

    DeleteObjectCommand(GameObject* obj, std::vector<GameObject*>& from)
    : gameObject(obj), objects(from)
    {}

    virtual ~DeleteObjectCommand() {
        delete gameObject;
    }

    void setParams(GameObject* obj, std::vector<GameObject*>& from) {
        gameObject = obj;
        objects = from;
    }

    void execute() override {
        auto it = objects.begin();
        for (; it != objects.end(); ++it) {
            if (*it == gameObject) {
                objects.erase(it);
                break;
            }
        }
    }
};

class BombingCommand : public Command
{
public:
    BombingCommand(const Plane* p, std::vector<DynamicObject*>& v, int& bn)
    : plane(p), objects(v), bombsNumber(bn) {}

    virtual ~BombingCommand() {}

    void setParams(const Plane* p, std::vector<DynamicObject*>& v, int& bn){
        plane = p;
        objects = v;
        bombsNumber = bn; 
    }

    void execute() override {
        if (bombsNumber > 0) {
            double x = plane->GetX() + 4;
            double y = plane->GetY() + 2;

            Bomb* pBomb = new Bomb;
            pBomb->SetDirection(0.3, 1);
            pBomb->SetSpeed(2);
            pBomb->SetPos(x, y);
            pBomb->SetWidth(SMALL_CRATER_SIZE);

            vecDynamicObj.push_back(pBomb);
            bombsNumber--;
        }
    }
private:
    const Plane* plane;
    std::vector<DynamicObject*>& objects;
    int& bombsNumber;
};