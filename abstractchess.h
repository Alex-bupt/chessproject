#ifndef ABSTRACTCHESS_H
#define ABSTRACTCHESS_H

enum Team{BLACK=0,RED=1,UNSET=-1};

class AbstractChess
{
public:
    AbstractChess(Team team_, int x_, int y_);
    virtual void setView();
    void setCoordinate(int x_,int y_);
    int x{-1}, y{-1};//the coordinate of the chess, -1 means UNSET
    Team team{RED};//the team: RED or BLACK
    bool isAlive = 1;
private:
};

#endif // ABSTRACTCHESS_H
