#include "chessboard.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPen>
#include<QBrush>
#include<QDebug>
#include<QRect>
#include<QPushButton>
#include<QLabel>

//wcx
#include <windows.h>
#include<iostream>

int transPosFromVirtualToReal(int val){
    return val*90+35;
}


AbstractChess* ChessBoard::iModel(int i){
    AbstractChess* selectedModel;
    if(i<10){
        if(i%2==0){
            selectedModel=&ChessesManager::getInstance().RedSoldier[i/2];
        }
        else{
            selectedModel=&ChessesManager::getInstance().BlackSoldier[i/2];
        }
    }
    else if(i<12){
        selectedModel=&ChessesManager::getInstance().RedCannon[i-10];
    }
    else if(i<14){
        selectedModel=&ChessesManager::getInstance().BlackCannon[13-i];
    }
    else if(i<16){
        selectedModel=&ChessesManager::getInstance().RedRook[i-14];
    }
    else if(i<18){
        selectedModel=&ChessesManager::getInstance().BlackRook[17-i];
    }
    else if(i<20){
        selectedModel=&ChessesManager::getInstance().RedHorse[i-18];
    }
    else if(i<22){
        selectedModel=&ChessesManager::getInstance().BlackHorse[21-i];
    }
    else if(i<24){
        selectedModel=&ChessesManager::getInstance().RedElephant[i-22];
    }
    else if(i<26){
        selectedModel=&ChessesManager::getInstance().BlackElephant[25-i];
    }
    else if(i<28){
        selectedModel=&ChessesManager::getInstance().RedScholar[i-26];
    }
    else if(i<30){
        selectedModel=&ChessesManager::getInstance().BlackScholar[29-i];
    }
    else if(30==i){
        selectedModel=&ChessesManager::getInstance().RedMarshal[0];
    }
    else{
        selectedModel=&ChessesManager::getInstance().BlackMarshal[0];
    }
    return selectedModel;
}

//yzy
int ChessBoard::x ;
int ChessBoard::y ;
int ChessBoard::xIndexPosition(int X){
    return X*90+70-35;
}

int ChessBoard::yIndexPosition(int Y){
    return 940-(Y*90+70)-35;
}

ChessBoard::ChessBoard(QWidget *parent): QWidget(parent)
{
    QPushButton * bt1 = new QPushButton(this);
    QPushButton * bt2 = new QPushButton(this);
    QPushButton * bt3 = new QPushButton(this);
    QPushButton * bt4 = new QPushButton(this);//四个按钮

    bt1->setText("再来一局");
    bt2->setText("认输");
    bt3->setText("和棋");
    bt4->setText("悔棋");

    QFont font = bt1->font();//设置字体格式
    font.setPointSize(11);
    font.setFamily("HeiTi");

    bt1->setFont(font);
    bt2->setFont(font);
    bt3->setFont(font);
    bt4->setFont(font);

    bt1->move(110,0);
    bt2->move(290,0);
    bt3->move(470,0);
    bt4->move(650,0);


    //绘制棋子(dhn+yzy)
    QIcon button_RedSoldier1(":/new/icon/DELICATE/RP.GIF");//兵
    QIcon button_RedSoldier2(":/new/icon/DELICATE/RP.GIF");
    QIcon button_RedSoldier3(":/new/icon/DELICATE/RP.GIF");
    QIcon button_RedSoldier4(":/new/icon/DELICATE/RP.GIF");
    QIcon button_RedSoldier5(":/new/icon/DELICATE/RP.GIF");
    QIcon button_BlackSoldier1(":/new/icon/DELICATE/BP.GIF");//卒
    QIcon button_BlackSoldier2(":/new/icon/DELICATE/BP.GIF");
    QIcon button_BlackSoldier3(":/new/icon/DELICATE/BP.GIF");
    QIcon button_BlackSoldier4(":/new/icon/DELICATE/BP.GIF");
    QIcon button_BlackSoldier5(":/new/icon/DELICATE/BP.GIF");
    QIcon button_RedCannon1(":/new/icon/DELICATE/RC.GIF");//红炮
    QIcon button_RedCannon2(":/new/icon/DELICATE/RC.GIF");
    QIcon button_BlackCannon1(":/new/icon/DELICATE/BC.GIF");//黑炮
    QIcon button_BlackCannon2(":/new/icon/DELICATE/BC.GIF");
    QIcon button_RedHorse1(":/new/icon/DELICATE/RN.GIF");//马
    QIcon button_RedHorse2(":/new/icon/DELICATE/RN.GIF");
    QIcon button_BlackHorse1(":/new/icon/DELICATE/BN.GIF");//馬
    QIcon button_BlackHorse2(":/new/icon/DELICATE/BN.GIF");
    QIcon button_RedRook1(":/new/icon/DELICATE/RR.GIF");//车
    QIcon button_RedRook2(":/new/icon/DELICATE/RR.GIF");
    QIcon button_BlackRook1(":/new/icon/DELICATE/BR.GIF");//車
    QIcon button_BlackRook2(":/new/icon/DELICATE/BR.GIF");
    QIcon button_RedElephant1(":/new/icon/DELICATE/RB.GIF");//相
    QIcon button_RedElephant2(":/new/icon/DELICATE/RB.GIF");
    QIcon button_BlackElephant1(":/new/icon/DELICATE/BB.GIF");//象
    QIcon button_BlackElephant2(":/new/icon/DELICATE/BB.GIF");
    QIcon button_RedScholar1(":/new/icon/DELICATE/RA.GIF");//仕
    QIcon button_RedScholar2(":/new/icon/DELICATE/RA.GIF");
    QIcon button_BlackScholar1(":/new/icon/DELICATE/BA.GIF");//士
    QIcon button_BlackScholar2(":/new/icon/DELICATE/BA.GIF");
    QIcon button_RedMarshal(":/new/icon/DELICATE/RK.GIF");//帅
    QIcon button_BlackMarshal(":/new/icon/DELICATE/BK.GIF");//将

    RedSoldier1->setFixedSize(70,70);
    RedSoldier1->move(35,305);
    RedSoldier1 ->setIcon(button_RedSoldier1);
    BlackSoldier1->setFixedSize(70,70);
    BlackSoldier1->move(35,575);
    BlackSoldier1 ->setIcon(button_BlackSoldier1);
    RedSoldier2->setFixedSize(70,70);
    RedSoldier2->move(215,305);
    RedSoldier2 ->setIcon(button_RedSoldier2);
    BlackSoldier2->setFixedSize(70,70);
    BlackSoldier2->move(215,575);
    BlackSoldier2 ->setIcon(button_BlackSoldier2);
    RedSoldier3->setFixedSize(70,70);
    RedSoldier3->move(395,305);
    RedSoldier3 ->setIcon(button_RedSoldier3);
    BlackSoldier3->setFixedSize(70,70);
    BlackSoldier3->move(395,575);
    BlackSoldier3 ->setIcon(button_BlackSoldier3);
    RedSoldier4->setFixedSize(70,70);
    RedSoldier4->move(575,305);
    RedSoldier4 ->setIcon(button_RedSoldier4);
    BlackSoldier4->setFixedSize(70,70);
    BlackSoldier4->move(575,575);
    BlackSoldier4 ->setIcon(button_BlackSoldier4);
    RedSoldier5->setFixedSize(70,70);
    RedSoldier5->move(755,305);
    RedSoldier5 ->setIcon(button_RedSoldier5);
    BlackSoldier5->setFixedSize(70,70);
    BlackSoldier5->move(755,575);
    BlackSoldier5 ->setIcon(button_BlackSoldier5);
    RedCannon1->setFixedSize(70,70);
    RedCannon1->move(125,215);
    RedCannon1 ->setIcon(button_RedCannon1);
    RedCannon2->setFixedSize(70,70);
    RedCannon2->move(665,215);
    RedCannon2 ->setIcon(button_RedCannon2);
    BlackCannon1->setFixedSize(70,70);
    BlackCannon1->move(125,665);
    BlackCannon1 ->setIcon(button_BlackCannon1);
    BlackCannon2->setFixedSize(70,70);
    BlackCannon2->move(665,665);
    BlackCannon2 ->setIcon(button_BlackCannon2);
    RedRook1->setFixedSize(70,70);
    RedRook1->move(35,35);
    RedRook1 ->setIcon(button_RedRook1);
    RedRook2->setFixedSize(70,70);
    RedRook2->move(755,35);
    RedRook2 ->setIcon(button_RedRook2);
    BlackRook1->setFixedSize(70,70);
    BlackRook1->move(35,845);
    BlackRook1 ->setIcon(button_BlackRook1);
    BlackRook2->setFixedSize(70,70);
    BlackRook2->move(755,845);
    BlackRook2 ->setIcon(button_BlackRook2);
    RedHorse1->setFixedSize(70,70);
    RedHorse1->move(125,35);
    RedHorse1 ->setIcon(button_RedHorse1);
    RedHorse2->setFixedSize(70,70);
    RedHorse2->move(665,35);
    RedHorse2 ->setIcon(button_RedHorse2);
    BlackHorse1->setFixedSize(70,70);
    BlackHorse1->move(125,845);
    BlackHorse1 ->setIcon(button_BlackHorse1);
    BlackHorse2->setFixedSize(60,60);
    BlackHorse2->move(665,845);
    BlackHorse2 ->setIcon(button_BlackHorse2);
    RedElephant1->setFixedSize(70,70);
    RedElephant1->move(215,35);
    RedElephant1 ->setIcon(button_RedElephant1);
    RedElephant2->setFixedSize(70,70);
    RedElephant2->move(575,35);
    RedElephant2 ->setIcon(button_RedElephant2);
    BlackElephant1->setFixedSize(70,70);
    BlackElephant1->move(215,845);
    BlackElephant1 ->setIcon(button_BlackElephant1);
    BlackElephant2->setFixedSize(70,70);
    BlackElephant2->move(575,845);
    BlackElephant2 ->setIcon(button_BlackElephant2);
    RedScholar1->setFixedSize(70,70);
    RedScholar1->move(305,35);
    RedScholar1 ->setIcon(button_RedScholar1);
    RedScholar2->setFixedSize(70,70);
    RedScholar2->move(485,35);
    RedScholar2 ->setIcon(button_RedScholar2);
    BlackScholar1->setFixedSize(70,70);
    BlackScholar1->move(305,845);
    BlackScholar1 ->setIcon(button_BlackScholar1);
    BlackScholar2->setFixedSize(70,70);
    BlackScholar2->move(485,845);
    BlackScholar2 ->setIcon(button_BlackScholar2);
    RedMarshal->setFixedSize(70,70);
    RedMarshal->move(395,35);
    RedMarshal ->setIcon(button_RedMarshal);
    BlackMarshal->setFixedSize(70,70);
    BlackMarshal->move(395,845);
    BlackMarshal ->setIcon(button_BlackMarshal);


    for(int i=0;i<32;i++){
        iQPB[i]->move(iQPB[i]->x(),880-iQPB[i]->y());
        connect(iQPB[i],&QPushButton::clicked,[=](){
            if(isChessWaitingForMove){
                auto eatenChess=iQPB[i];
                //auto eatenType=iType[i];
                AbstractChess* eatenModel=iModel(i);
                Controller::getController().moveChess(selectedType,selectedModel,eatenModel->x,eatenModel->y);
                selectedChess->move(transPosFromVirtualToReal(selectedModel->x),880-transPosFromVirtualToReal(selectedModel->y));
                eatenChess->move(transPosFromVirtualToReal(eatenModel->x),880-transPosFromVirtualToReal(eatenModel->y));
                isChessWaitingForMove=false;
                std::cout<<"xxxxxxxxxxxxx"<<eatenModel->x<<"yyyyyyyy"<<eatenModel->y<<"aaaaaaa"<<eatenModel->isAlive<<"\n";
            }
            else{
                isChessWaitingForMove=true;
                selectedChess =iQPB[i];
                selectedType =iType[i];
                selectedModel=iModel(i);
            }
        });
    }
}

void ChessBoard::mouseMoveEvent(QMouseEvent *ev){
    moveX=(ev->x()-25)/90;
    moveY=(940-ev->y()-25)/90;
    moveX1=(ev->x()-25)/90;
    moveY1=(ev->y()-25)/90;
    // qDebug() << ev->x() <<ev->y();
    qDebug() << moveX1 <<" " <<moveY1;
}

void ChessBoard::mousePressEvent(QMouseEvent *eve){
    ChessBoard::x = moveX;
    ChessBoard::y = moveY;

    //wcx
    //std::cout<<"iiiddd"<<typeid(*selectedModel).name()<<std::endl;
    if(isChessWaitingForMove){
        Controller::getController().moveChess(selectedType,selectedModel,ChessBoard::x,ChessBoard::y);
        selectedChess->move(transPosFromVirtualToReal(selectedModel->x),880-transPosFromVirtualToReal(selectedModel->y));
        isChessWaitingForMove=false;
    }
}

void ChessBoard::paintLine(QPainter *painter, int x, int y){
    QPen pen = painter->pen();//绘制四个折线
    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);

    painter->drawLine(QPoint(x+10,y-30),QPoint(x+10,y-10));
    painter->drawLine(QPoint(x+10,y-10),QPoint(x+30,y-10));
    painter->drawLine(QPoint(x+10,y+10),QPoint(x+10,y+30));
    painter->drawLine(QPoint(x+10,y+10),QPoint(x+30,y+10));
    painter->drawLine(QPoint(x-10,y-10),QPoint(x-10,y-30));
    painter->drawLine(QPoint(x-10,y-10),QPoint(x-30,y-10));
    painter->drawLine(QPoint(x-10,y+10),QPoint(x-10,y+30));
    painter->drawLine(QPoint(x-10,y+10),QPoint(x-30,y+10));

}

void ChessBoard::paintEvent(QPaintEvent *event){
    this->setFixedSize(850,940);
    this->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background,QColor("#B1723C"));
    this->setPalette(palette);//环境背景色
    setMouseTracking(true);

    QPainter * painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing,true);//锯齿化关闭
    int offSet = 70;
    int d = 90;
    QPen pen = painter->pen();//绘制场地

    pen.setColor(QColor("#8D5822"));
    pen.setWidth(7);
    painter->setPen(pen);

    QBrush brush;
    brush.setColor(QColor("#EEC085"));
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRect(60,60,740,830);//场地背景色


    pen.setColor(Qt::black);
    pen.setWidth(1);
    painter->setPen(pen);
    for (int i=0 ; i<10 ;i++) {
        painter->drawLine(QPoint(offSet,offSet+i*d),QPoint(offSet+8*d,offSet+i*d));
    }
    for (int i=0 ; i<=8 ;i++) {
        if(i==0||i==8){
            painter->drawLine(QPoint(offSet+i*d,offSet),QPoint(offSet+i*d,offSet+9*d));
        }
        else {
            painter->drawLine(QPoint(offSet+i*d,offSet),QPoint(offSet+i*d,offSet+4*d));
            painter->drawLine(QPoint(offSet+i*d,offSet+5*d),QPoint(offSet+i*d,offSet+9*d));
        }
    }

    painter->drawLine(QPoint(340,70),QPoint(520,250));//绘制四条斜线
    painter->drawLine(QPoint(340,250),QPoint(520,70));
    painter->drawLine(QPoint(340,700),QPoint(520,880));
    painter->drawLine(QPoint(520,700),QPoint(340,880));

    this->paintLine(painter,250,340);//基准线
    this->paintLine(painter,430,340);
    this->paintLine(painter,610,340);
    this->paintLine(painter,160,250);
    this->paintLine(painter,700,250);
    this->paintLine(painter,250,610);
    this->paintLine(painter,430,610);
    this->paintLine(painter,610,610);
    this->paintLine(painter,160,700);
    this->paintLine(painter,700,700);
    painter->drawLine(QPoint(80,330),QPoint(80,310));//绘制边框基准线
    painter->drawLine(QPoint(80,330),QPoint(100,330));
    painter->drawLine(QPoint(80,350),QPoint(100,350));
    painter->drawLine(QPoint(80,350),QPoint(80,370));
    painter->drawLine(QPoint(780,330),QPoint(780,310));
    painter->drawLine(QPoint(780,330),QPoint(760,330));
    painter->drawLine(QPoint(780,350),QPoint(780,370));
    painter->drawLine(QPoint(780,350),QPoint(760,350));
    painter->drawLine(QPoint(80,600),QPoint(80,580));
    painter->drawLine(QPoint(80,600),QPoint(100,600));
    painter->drawLine(QPoint(80,620),QPoint(80,640));
    painter->drawLine(QPoint(80,620),QPoint(100,620));
    painter->drawLine(QPoint(780,600),QPoint(780,580));
    painter->drawLine(QPoint(780,600),QPoint(760,600));
    painter->drawLine(QPoint(780,620),QPoint(780,640));
    painter->drawLine(QPoint(780,620),QPoint(760,620));


    QRect rect1(offSet+d,offSet+4*d,d,d);//书写楚河汉界
    QRect rect2(offSet+2*d,offSet+4*d,d,d);
    QRect rect3(offSet+5*d,offSet+4*d,d,d);
    QRect rect4(offSet+6*d,offSet+4*d,d,d);
    painter->setFont(QFont("隶书",45,800));
    painter->drawText(rect1,"楚",QTextOption(Qt::AlignCenter));
    painter->drawText(rect2,"河",QTextOption(Qt::AlignCenter));
    painter->drawText(rect3,"汉",QTextOption(Qt::AlignCenter));
    painter->drawText(rect4,"界",QTextOption(Qt::AlignCenter));

    pen.setColor(Qt::red);//绘制定位边框
    painter->setPen(pen);
    pen.setWidth(1);
    if((moveX1*90+70>=25)&&(moveX1*90+70)<=825&&(moveY1*90+70>=25)&&(moveY1*90+70)<=915){
        painter->drawLine(moveX1*90+70-20,moveY1*90+70-45,moveX1*90+70-45,moveY1*90+70-45);
        painter->drawLine(moveX1*90+70-45,moveY1*90+70-45,moveX1*90+70-45,moveY1*90+70-20);
        painter->drawLine(moveX1*90+70+20,moveY1*90+70+45,moveX1*90+70+45,moveY1*90+70+45);
        painter->drawLine(moveX1*90+70+45,moveY1*90+70+45,moveX1*90+70+45,moveY1*90+70+20);
        painter->drawLine(moveX1*90+70-20,moveY1*90+70+45,moveX1*90+70-45,moveY1*90+70+45);
        painter->drawLine(moveX1*90+70-45,moveY1*90+70+45,moveX1*90+70-45,moveY1*90+70+20);
        painter->drawLine(moveX1*90+70+20,moveY1*90+70-45,moveX1*90+70+45,moveY1*90+70-45);
        painter->drawLine(moveX1*90+70+45,moveY1*90+70-45,moveX1*90+70+45,moveY1*90+70-20);

    }
    update();
}
