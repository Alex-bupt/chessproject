#ifndef SOLDIERCHESS_H
#define SOLDIERCHESS_H

#include "abstractchess.h"

class SoldierChess : public AbstractChess
{
public:
    SoldierChess(Team team, int x, int y);
    SoldierChess();
    void setView() override;
    bool isDefense();
};

#endif // SOLDIERCHESS_H
