#pragma once
#include <iostream>
#include <cstdlib>
#include "House.h"
#include "MyTools.h"

namespace mt = MyTools;

class WoodenHouse: public House
{
public:
    inline uint16_t GetScore() const override { return score; }
    void SetSocre() { House::score = 40; }
    void SetWidth() { House::SetWidth(6); }
    void SetPos() 
    { 
        uint16_t x = mt::GetMaxX() - 16;
        uint16_t y = mt::GetMaxY() - width - 1;
        double x_pos = rand() % x;
        double y_pos = y;
        House::SetPos(x_pos, y_pos);
    }
    
};

class BrickHouse : public House
{
public:
    inline uint16_t GetScore() const override { return score; }
    void SetSocre() { House::score = 60; }
    void SetWidth() { House::SetWidth(8); }
    void SetPos() 
    { 
        uint16_t x = mt::GetMaxX() - 16;
        uint16_t y = mt::GetMaxY() - width - 1;
        double x_pos = rand() % x;
        double y_pos = y;
        House::SetPos(x_pos, y_pos);
    }
};

// concrete в данном случае - бетон, этот дом самый крепкий
class ConcreteHouse : public House
{
public:
    inline uint16_t GetScore() const override { return score; }
    void SetSocre() { House::score = 80; }
    void SetWidth() { House::SetWidth(10); }
    void SetPos() 
    { 
        uint16_t x = mt::GetMaxX() - 16;
        uint16_t y = mt::GetMaxY() - width - 1;
        double x_pos = rand() % x;
        double y_pos = y;
        House::SetPos(x_pos, y_pos);
    }
};

class HouseBuilder
{
public:
    virtual ~HouseBuilder() {}
    virtual void set_score() const = 0;
    virtual void set_width() const = 0;
    virtual void set_position() const = 0;
    virtual House* get_house() = 0;
};

class WoodenHouseBuilder : public HouseBuilder
{
public:
    WoodenHouseBuilder()
    {
        reset();
    }

    ~WoodenHouseBuilder()
    {
        delete house;
    }

    void reset()
    {
        house = new WoodenHouse;
    }

    void set_score() const override
    {
        house->SetSocre();
    }

    void set_width() const override
    {
        house->SetWidth();
    }

    void set_position() const override
    {
        house->SetPos();
    }

    WoodenHouse* get_house()
    {
        WoodenHouse *result = house;
        reset();
        return result;
    }
private:
    WoodenHouse *house;
};

class BrickHouseBuilder : public HouseBuilder
{
public:
    BrickHouseBuilder()
    {
        reset();
    }

    ~BrickHouseBuilder()
    {
        delete house;
    }

    void reset()
    {
        house = new BrickHouse;
    }

    void set_score() const override
    {
        house->SetSocre();
    }

    void set_width() const override
    {
        house->SetWidth();
    }

    void set_position() const override
    {
        house->SetPos();
    }

    BrickHouse* get_house()
    {
        BrickHouse *result = house;
        reset();
        return result;
    }
private:
    BrickHouse *house;
};

class ConcreteHouseBuilder : public HouseBuilder
{
public:
    ConcreteHouseBuilder()
    {
        reset();
    }

    ~ConcreteHouseBuilder()
    {
        delete house;
    }

    void reset()
    {
        house = new ConcreteHouse;
    }

    void set_score() const override
    {
        house->SetSocre();
    }

    void set_width() const override
    {
        house->SetWidth();
    }

    void set_position() const override
    {
        house->SetPos();
    }

    ConcreteHouse* get_house()
    {
        ConcreteHouse *result = house;
        reset();
        return result;
    }
private:
    ConcreteHouse *house;
};

class Director
{
public:
    void set_builder(HouseBuilder *house_builder)
    {
        builder = house_builder;
    }
    void build_house()
    {
        builder->set_score();
        builder->set_width();
        builder->set_position();
    }
private:
    HouseBuilder *builder;
};
