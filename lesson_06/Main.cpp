#include "Tank.h"
#include "LevelGUI.h"
#include "TeaserMediator.h"

int main()
{
    Tank* tank = new Tank;
    LevelGUI* gui = new LevelGUI;
    TeaserMediator* mediator = new TeaserMediator;
    mediator->add_subscriber(tank);
    mediator->add_subscriber(gui);
    gui->set_mediator(mediator);
    tank->set_mediator(mediator);

    for (int i = 0; i < 10; ++i) {
        tank->tease_the_plane();
    }

    delete tank;
    delete gui;
    delete mediator;
    return 0;
}