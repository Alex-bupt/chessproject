#include "cannonchess.h"

CannonChess::CannonChess(Team team, int x, int y):AbstractChess(team,x,y){}

CannonChess::CannonChess():CannonChess(UNSET,-1,-1){}

void CannonChess::setView(){
    // todo
    return;
}
