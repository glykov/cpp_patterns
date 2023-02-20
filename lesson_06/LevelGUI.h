#pragma once
#include <chrono>
#include "GameObject.h"

class LevelGUI : public GameObject {
public:

    LevelGUI() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0) { }

    void __fastcall set_param(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall set_height(uint16_t heightN) { height = heightN; };
    
    inline uint16_t get_finish_x() const { return finishX; }
    inline void set_finish_x(uint16_t finishXN) { finishX = finishXN; }

    void draw() const override;
    void draw_message(std::string messge) const;

    void be_notified(std::string msg) const override;
private:

    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;
};