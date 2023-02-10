
#include <iostream>

#include "Bomb.h"
#include "visitor.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(Visitor &v)
{
    v.Visit(this);
}