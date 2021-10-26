#include "horsechess.h"

HorseChess::HorseChess(Team team, int x, int y):AbstractChess(team,x,y){}

HorseChess::HorseChess():HorseChess(UNSET,-1,-1){}

void HorseChess::setView(){
    // todo
    return;
}
