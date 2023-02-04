#pragma once
#include "TankAdaptee.h"
#include "DestroyableGroundObject.h"

class TankAdapter : public DestroyableGroundObject
{
public:
    TankAdapter(const TankAdaptee& t) : tank(t) {}

    void SetPos(double nx, double ny) {  
        tank.SetPos(nx, ny);
    }

    uint16_t GetWidth() const {  
        return tank.GetWidth();  
    }

    void SetWidth(uint16_t width) {
        tank.SetWidth(width);
    } 

    void Draw() const {  
        tank.Paint();  
    }

    bool __fastcall isInside(double x1, double x2) const {
        tank.isInRange(x1, x2);  
    };

    inline double GetY() const { return y; }
    inline double GetX() const { return x; }

    uint16_t GetScore() const {
        tank.GetScore();
    }
private:
    TankAdaptee tank;
};