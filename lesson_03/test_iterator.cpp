#include <iostream>
#include "iterator.h"
#include "Plane.h"

std::vector<Bomb*> FindAllBombs(std::vector<DynamicObject*>& vecDynamicObj)
{
    std::vector<Bomb*> vecBombs;
    BombIterator it(vecDynamicObj);

    while (it.hasNext()) {
        Bomb* b = it.next();
        vecBombs.push_back(b);
    }

    return vecBombs;
}

int main()
{
    std::vector<DynamicObject*> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(new Bomb());
    }
    vec.push_back(new Plane());
    vec.push_back(new Bomb());

    std::cout << vec.size() << std::endl;           // 12 объектов

    std::vector<Bomb*> vec2 = FindAllBombs(vec);

    std::cout << vec2.size() << std::endl;          // 11 объектов, исключая самолет

    return 0;
}