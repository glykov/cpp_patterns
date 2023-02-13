#pragma once
#include <vector>
#include <string>

class GameObject;

class Mediator
{
public:
    virtual ~Mediator() {}
    virtual void notify(GameObject* sender, std::string message) = 0;
};




