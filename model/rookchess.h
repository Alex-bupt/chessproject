#ifndef ROOKCHESS_H
#define ROOKCHESS_H

#include "abstractchess.h"

class RookChess : public AbstractChess
{
public:
    RookChess(Team team, int x, int y);
    RookChess();
    void setView() override;
};

#endif // ROOKCHESS_H
