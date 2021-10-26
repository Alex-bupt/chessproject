#ifndef ELEPHANTCHESS_H
#define ELEPHANTCHESS_H

#include "abstractchess.h"

class ElephantChess : public AbstractChess
{
public:
    ElephantChess(Team team, int x, int y);
    ElephantChess();
    void setView() override;
};

#endif // ELEPHANTCHESS_H
