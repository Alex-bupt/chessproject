#include "abstractchess.h"
#include <iostream>

AbstractChess::AbstractChess(Team team_, int x_, int y_):x{x_},y{y_},team{team_}{}
void AbstractChess::setCoordinate(int x_,int y_){
    std::cout << "before:" << x << "=====" << y << "\n";
    this->x=x_;
    this->y=y_;
    setView();
    std::cout << "after:" << x << "=====" << y << "\n";
    return;
}

void AbstractChess::setView(){
    if(0==isAlive){
        x=-1;y=-1;
    }
}
