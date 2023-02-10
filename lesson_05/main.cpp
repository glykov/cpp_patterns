#include <vector>
#include "visitor.h"
#include "Bomb.h"
#include "Plane.h"

int main()
{
    std::vector<DynamicObject*> v;
    
    Plane *p = new Plane;
    p->SetSpeed(1.2);
    p->SetDirection(2.3, 3.4);
    v.push_back(p);

    Bomb *b1 = new Bomb;
    b1->SetSpeed(4.5);
    b1->SetDirection(5.6, 6.7);
    v.push_back(b1);

    Bomb *b2 = new Bomb;
    b2->SetSpeed(7.8);
    b2->SetDirection(8.9, 9.0);
    v.push_back(b2);

    LogVisitor lv;
    
    /*
     * Logging: Plane speed 1.2; direction x: 2.3, direction y: 3.4
     * Logging: Bomb speed 4.5; direction x: 5.6, direction y: 6.7
     * Logging: Bomb speed 7.8; direction x: 8.9, direction y: 9
     */
    for (const auto obj : v) {
        obj->Accept(lv);
    }
    return 0;
}

