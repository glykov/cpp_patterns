#pragma once
#include "Plane.h"
#include "Bomb.h"
#include "MyTools.h"

namespace mt = MyTools;

class Visitor
{
public:
    virtual void Visit(Plane* p) = 0;
    virtual void Visit(Bomb* b) = 0;
};

class LogVisitor : public Visitor
{
public:
    void Visit(Plane *p) override;
    void Visit(Bomb *b) override;
};
