#ifndef CANNONCHESS_H
#define CANNONCHESS_H

#include "abstractchess.h"

class CannonChess : public AbstractChess
{
public:
    CannonChess(Team team, int x, int y);
    CannonChess();
    void setView() override;
};

#endif // CANNONCHESS_H
