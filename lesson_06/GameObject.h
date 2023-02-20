#pragma once
#include <cstdint>
#include <string>
#include "Mediator.h"

class GameObject
{
public:
    GameObject() : x(0.0), y(0.0), width(0) {}

    virtual ~GameObject() { }

    virtual void draw() const = 0;

    inline void set_pos(double nx, double ny) { x = nx; y = ny; }

    inline double get_x() const { return x; }
    inline double get_y() const { return y; }

    inline void set_width(uint16_t nwidth) { width = nwidth; }
    inline uint16_t get_width() const { return width; }

    void set_mediator(Mediator* med) { mediator = med; }
    virtual void be_notified(std::string msg) const = 0; 
protected:
    double x;
    double y;
    uint16_t width;
    Mediator* mediator;
};