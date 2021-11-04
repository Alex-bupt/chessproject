#ifndef HORSECHESS_H
#define HORSECHESS_H

#include "abstractchess.h"

class HorseChess : public AbstractChess
{
public:
    HorseChess(Team team, int x, int y);
    HorseChess();
    void setView() override;
};

#endif // HORSECHESS_H
