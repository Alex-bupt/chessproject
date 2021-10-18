#include "soldierchess.h"

SoldierChess::SoldierChess(Team team, int x, int y):AbstractChess(team,x,y){}

SoldierChess::SoldierChess():SoldierChess(UNSET,-1,-1){}

void SoldierChess::setView(){
    // todo
    return;
}

bool SoldierChess::isDefense(){
    return (RED==team)^(y>=5);
}
