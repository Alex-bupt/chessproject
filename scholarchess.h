#ifndef SCHOLARCHESS_H
#define SCHOLARCHESS_H

#include "abstractchess.h"

class ScholarChess : public AbstractChess
{
public:
    ScholarChess(Team team, int x, int y);
    ScholarChess();
    void setView() override;
};

#endif // SCHOLARCHESS_H
