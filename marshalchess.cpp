#include "marshalchess.h"

MarshalChess::MarshalChess(Team team, int x, int y):AbstractChess(team,x,y){}

MarshalChess::MarshalChess():MarshalChess(UNSET,-1,-1){}

void MarshalChess::setView(){
    // todo
    return;
}
