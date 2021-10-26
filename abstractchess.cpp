#include "abstractchess.h"
AbstractChess::AbstractChess(Team team_, int x_, int y_):x{x_},y{y_},team{team_}{}
void AbstractChess::setCoordinate(int x_,int y_){
    x=x_;
    y=y_;
    setView();
    return;
}

void AbstractChess::setView(){}
