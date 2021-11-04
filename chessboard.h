
#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include<QPaintEvent>
#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include"positionmessage.h"
#include<QVector>
#include<QPushButton>
#include "Controller.h"
/****************
 * author:杨臻烨 *
 ****************/
class ChessBoard : public QWidget
{
public:
    static int x;
    static int y;
    int moveX=0,moveY=0;//左下角原点
    int moveX1=0,moveY1=0;//左上角原点
    static int xIndexPosition(int x);
    static int yIndexPosition(int y);
    explicit ChessBoard(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);//override绘图函数
    void mouseMoveEvent(QMouseEvent* ev);
    void mousePressEvent(QMouseEvent* eve);
    void paintLine(QPainter* p,int _x,int _y);//绘制折线

    //wcx
    void refreshView( );

    bool isChessWaitingForMove = false;

    AbstractChess* selectedModel=nullptr;
    QPushButton * selectedChess =nullptr;
    ChessType selectedType =Soldier;

    //yzy
    QPushButton * RedSoldier1 = new QPushButton("兵",this);
    QPushButton * BlackSoldier1 = new QPushButton("卒",this);
    QPushButton * RedSoldier2 = new QPushButton("兵",this);
    QPushButton * BlackSoldier2 = new QPushButton("卒",this);
    QPushButton * RedSoldier3 = new QPushButton("兵",this);
    QPushButton * BlackSoldier3 = new QPushButton("卒",this);
    QPushButton * RedSoldier4 = new QPushButton("兵",this);
    QPushButton * BlackSoldier4 = new QPushButton("卒",this);
    QPushButton * RedSoldier5 = new QPushButton("兵",this);
    QPushButton * BlackSoldier5 = new QPushButton("卒",this);
    QPushButton * RedCannon1 = new QPushButton("炮",this);
    QPushButton * RedCannon2 = new QPushButton("炮",this);
    QPushButton * BlackCannon1 = new QPushButton("炮",this);
    QPushButton * BlackCannon2 = new QPushButton("炮",this);
    QPushButton * RedRook1 = new QPushButton("车",this);
    QPushButton * RedRook2 = new QPushButton("车",this);
    QPushButton * BlackRook1 = new QPushButton("車",this);
    QPushButton * BlackRook2 = new QPushButton("車",this);
    QPushButton * RedHorse1 = new QPushButton("马",this);
    QPushButton * RedHorse2 = new QPushButton("马",this);
    QPushButton * BlackHorse1 = new QPushButton("马",this);
    QPushButton * BlackHorse2 = new QPushButton("马",this);
    QPushButton * RedElephant1 = new QPushButton("象",this);
    QPushButton * RedElephant2 = new QPushButton("象",this);
    QPushButton * BlackElephant1 = new QPushButton("象",this);
    QPushButton * BlackElephant2 = new QPushButton("象",this);
    QPushButton * RedScholar1 = new QPushButton("士",this);
    QPushButton * RedScholar2 = new QPushButton("士",this);
    QPushButton * BlackScholar1 = new QPushButton("士",this);
    QPushButton * BlackScholar2 = new QPushButton("士",this);
    QPushButton * RedMarshal = new QPushButton("帅",this);
    QPushButton * BlackMarshal = new QPushButton("将",this);

    QPushButton* iQPB[32]={RedSoldier1,BlackSoldier1 ,RedSoldier2 ,BlackSoldier2 ,RedSoldier3 ,BlackSoldier3 ,RedSoldier4 ,BlackSoldier4,RedSoldier5 ,BlackSoldier5,RedCannon1 ,RedCannon2,BlackCannon1 , BlackCannon2,RedRook1,RedRook2 ,BlackRook1 , BlackRook2,RedHorse1 ,RedHorse2 ,BlackHorse1, BlackHorse2 ,RedElephant1,RedElephant2 ,BlackElephant1 ,BlackElephant2 ,RedScholar1,RedScholar2,BlackScholar1,BlackScholar2,RedMarshal, BlackMarshal};
    ChessType iType[32]={Soldier,Soldier ,Soldier,Soldier,Soldier,Soldier,Soldier,Soldier,Soldier,Soldier,Cannon,Cannon,Cannon,Cannon,Rook,Rook,Rook,Rook,Horse,Horse,Horse,Horse,Elephant,Elephant,Elephant,Elephant,Scholar,Scholar,Scholar,Scholar,Marshal,Marshal};
    AbstractChess* iModel(int i);
};

#endif // CHESSBOARD_H
