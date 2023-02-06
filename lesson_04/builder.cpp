#include <vector>
#include "builder.h"

int main()
{
    WoodenHouseBuilder* whb = new WoodenHouseBuilder;
    BrickHouseBuilder* bhb = new BrickHouseBuilder;
    ConcreteHouseBuilder* chb = new ConcreteHouseBuilder;

    Director director;
    std::vector<House*> city;

    for (int i = 0; i < 10; ++i)
    {
        HouseBuilder* hb;
        if (i % 2 == 0)
            hb = whb;
        else if (i % 3 == 0)
            hb = bhb;
        else
            hb = chb;

        director.set_builder(hb);
        director.build_house();
        city.push_back(hb->get_house());
    }

    for (const auto& h : city)
    {
        std::cout << "score: " << h->GetScore() << ", width: " 
                << h->GetWidth() << ", x: " << h->GetX() 
                << ", y: " << h->GetY() << std::endl;
    }
    return 0;
}