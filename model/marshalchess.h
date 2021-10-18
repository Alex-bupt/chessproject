#ifndef MARSHALCHESS_H
#define MARSHALCHESS_H

#include "abstractchess.h"

class MarshalChess : public AbstractChess
{
public:
    MarshalChess(Team team, int x, int y);
    MarshalChess();
    void setView() override;
};

#endif // MARSHALCHESS_H
