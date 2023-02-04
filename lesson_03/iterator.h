#pragma once
#include <vector>
#include "Bomb.h"

class IIterator
{
public:
    virtual Bomb* next() = 0;
    virtual bool hasNext() = 0;
};

class BombIterator : public IIterator
{
public:
    BombIterator(std::vector<DynamicObject*>& v) : vec(v), ptr(nullptr), position(0) {}

    bool hasNext() override {
        if (position >= vec.size()) {
            return false;
        } else if ( dynamic_cast<Bomb*>(vec[position]) == nullptr &&  dynamic_cast<Bomb*>(vec[position + 1]) != nullptr) {
            ++position;
        }
        return true;
    } 

    Bomb* next() override {
        ptr = dynamic_cast<Bomb*>(vec[position]);
        ++position;
        return ptr;
    }
private:
    std::vector<DynamicObject*>& vec;
    Bomb* ptr;
    int position;
};