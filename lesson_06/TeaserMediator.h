#pragma once
#include "Mediator.h"
#include "GameObject.h"

class TeaserMediator : public Mediator
{
public:
    ~TeaserMediator();
    void add_subscriber(GameObject* obj);
    void notify(const GameObject* sender, std::string message) override;
private:
    std::vector<GameObject*> subscribers;
};