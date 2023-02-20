#include <iostream>
#include <vector>
#include "Bomb.h"

int main()
{
    std::vector<Bomb*> bombs;
    bombs.push_back(new Bomb());
    bombs[0]->SetDirection(0.3, 1);
    bombs[0]->SetSpeed(2);
    bombs[0]->SetPos(51, 5);
    bombs.push_back(bombs[0]->Clone());
    bombs[1]->SetPos(52, 5);
    bombs.push_back(bombs[0]->Clone());
    bombs[2]->SetPos(53, 5);

    for (auto bomb : bombs) {
        std::cout << bomb->GetX() << " " << bomb->GetY() << std::endl;
    }

    return 0;
}