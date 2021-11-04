#include "chessesmanager.h"
#include<iostream>

constexpr int TABLE_LEFT =0;
constexpr int TABLE_BOTTOM=0;
constexpr int PER_CELL=20;


ChessesManager* ChessesManager::pointerToInstance=new ChessesManager();
ChessesManager& ChessesManager::getInstance(){
    return *pointerToInstance;
}


ChessesManager::ChessesManager(){
    for(int i=0;i<5;i++){
        RedSoldier[i]= SoldierChess(RED,2*i,3);
        BlackSoldier[i]=SoldierChess(BLACK,8-2*(4-i),6);

        chesses.push_back(&RedSoldier[i]);
        chesses.push_back(&BlackSoldier[i]);
    }
    for(int i=0;i<2;i++){
        RedCannon[i]=CannonChess(RED,1+6*i,2);
        BlackCannon[i]=CannonChess(BLACK,7-6*i,7);
        RedRook[i]=RookChess(RED,8*i,0);
        BlackRook[i]=RookChess(BLACK,8-8*i,9);
        RedHorse[i]=HorseChess(RED,1+6*i,0);
        BlackHorse[i]=HorseChess(BLACK,7-6*i,9);
        RedElephant[i]=ElephantChess(RED,2+4*i,0);
        BlackElephant[i]=ElephantChess(BLACK,6-4*i,9);
        RedScholar[i]=ScholarChess(RED,3+2*i,0);
        BlackScholar[i]=ScholarChess(BLACK,5-2*i,9);

        chesses.push_back(&RedCannon[i]);
        chesses.push_back(&BlackCannon[i]);
        chesses.push_back(&RedRook[i]);
        chesses.push_back(&BlackRook[i]);
        chesses.push_back(&RedHorse[i]);
        chesses.push_back(&BlackHorse[i]);
        chesses.push_back(&RedElephant[i]);
        chesses.push_back(&BlackElephant[i]);
        chesses.push_back(&RedScholar[i]);
        chesses.push_back(&BlackScholar[i]);
    }
    RedMarshal[0]=MarshalChess(RED,4,0);
    BlackMarshal[0]=MarshalChess(BLACK,4,9);

    chesses.push_back(&RedMarshal[0]);
    chesses.push_back(&BlackMarshal[0]);
}
