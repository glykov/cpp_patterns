#include "TeaserMediator.h"

TeaserMediator::~TeaserMediator()
{
    for (auto obj : subscribers) {
        delete obj;
    }
}

void TeaserMediator::add_subscriber(GameObject* obj)
{
    subscribers.push_back(obj);
}

void TeaserMediator::notify(const GameObject* sender, std::string message)
{
    for (auto obj : subscribers) {
        if (obj != sender) {
            obj->be_notified(message);
        }
    }
}