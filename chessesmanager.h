#ifndef CHESSES_MANAGER_H
#define CHESSES_MANAGER_H

#include<array>
#include<vector>
#include"soldierchess.h"
#include"cannonchess.h"
#include"rookchess.h"
#include"horsechess.h"
#include"elephantchess.h"
#include"scholarchess.h"
#include"marshalchess.h"

class ChessesManager
{
public:
    static ChessesManager& getInstance();

    SoldierChess test;
    std::array<SoldierChess,5> RedSoldier;
    std::array<SoldierChess,5> BlackSoldier;
    std::array<CannonChess,2> RedCannon;
    std::array<CannonChess,2> BlackCannon;
    std::array<RookChess,2> RedRook;
    std::array<RookChess,2> BlackRook;
    std::array<HorseChess,2> RedHorse;
    std::array<HorseChess,2> BlackHorse;
    std::array<ElephantChess,2> RedElephant;
    std::array<ElephantChess,2> BlackElephant;
    std::array<ScholarChess,2> RedScholar;
    std::array<ScholarChess,2> BlackScholar;
    std::array<MarshalChess,1> RedMarshal;
    std::array<MarshalChess,1> BlackMarshal;
    void removeChess();
    std::vector<AbstractChess*> chesses;

private:
    ChessesManager();
    ~ChessesManager();
    static ChessesManager* pointerToInstance;
};

#endif // CHESSES_MANAGER_H
