#pragma once
#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
    bool __fastcall is_inside(double x1, double x2) const override;
    inline uint16_t get_score() const override { return score; }
    void draw() const override;
    void tease_the_plane() const;
    void be_notified(std::string msg) const override;
private:
    const uint16_t score = 30;
};