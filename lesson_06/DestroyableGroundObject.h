#pragma once
#include "GameObject.h"

class DestroyableGroundObject : public GameObject
{
public:
    virtual bool __fastcall is_inside(double x1, double x2) const = 0;
    virtual inline uint16_t get_score() const = 0; 
};