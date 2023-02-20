#include <iostream>
#include "LevelGUI.h"

void LevelGUI::draw() const
{
    std::cout << "drawing level GUI\n";
}

void LevelGUI::draw_message(std::string msg) const
{
    std::cout << "message: " << msg << std::endl;
}

void __fastcall LevelGUI::set_param(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew)
{
    passedTime = passedTimeNew;
    fps = fpsNew;
    bombsNumber = bombsNumberNew;
    score = scoreNew;
}

void LevelGUI::be_notified(std::string message) const
{
    draw_message(message);
}
