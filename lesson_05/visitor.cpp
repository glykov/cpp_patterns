#include <iostream>
#include <sstream>
#include "visitor.h"

void LogVisitor::Visit(Plane *p)
{
    std::stringstream ss;
    ss << "Plane speed " << p->GetSpeed() << "; direction x: " 
        << p->GetXDirection() << ", direction y: " << p->GetYDirection();
    
    std::cout << "Logging: " << ss.str() << std::endl;
    mt::WriteToLog(ss.str());
}

void LogVisitor::Visit(Bomb *b)
{
    std::stringstream ss;
    ss << "Bomb speed " << b->GetSpeed() << "; direction x: " 
        << b->GetXDirection() << ", direction y: " << b->GetYDirection();
    
    std::cout << "Logging: " << ss.str() << std::endl;
    mt::WriteToLog(ss.str());
}