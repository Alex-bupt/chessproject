#include "chessboard.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPen>
#include<QBrush>
#include<QDebug>
#include<QRect>
#include<QPushButton>
#include<QLabel>

int ChessBoard::x ;
int ChessBoard::y ;

int ChessBoard::xIndexPossition(int X){
    return X*90+70-35;
}

int ChessBoard::yIndexPossition(int Y){
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


    //绘制棋子
    QPushButton * RedSoldier1 = new QPushButton("兵",this);
    RedSoldier1->setFixedSize(70,70);
    RedSoldier1->move(35,305);
    QPushButton * BlackSoldier1 = new QPushButton("卒",this);
    BlackSoldier1->setFixedSize(70,70);
    BlackSoldier1->move(35,575);
    QPushButton * RedSoldier2 = new QPushButton("兵",this);
    RedSoldier2->setFixedSize(70,70);
    RedSoldier2->move(215,305);
    QPushButton * BlackSoldier2 = new QPushButton("卒",this);
    BlackSoldier2->setFixedSize(70,70);
    BlackSoldier2->move(215,575);
    QPushButton * RedSoldier3 = new QPushButton("兵",this);
    RedSoldier3->setFixedSize(70,70);
    RedSoldier3->move(395,305);
    QPushButton * BlackSoldier3 = new QPushButton("卒",this);
    BlackSoldier3->setFixedSize(70,70);
    BlackSoldier3->move(395,575);
    QPushButton * RedSoldier4 = new QPushButton("兵",this);
    RedSoldier4->setFixedSize(70,70);
    RedSoldier4->move(575,305);
    QPushButton * BlackSoldier4 = new QPushButton("卒",this);
    BlackSoldier4->setFixedSize(70,70);
    BlackSoldier4->move(575,575);
    QPushButton * RedSoldier5 = new QPushButton("兵",this);
    RedSoldier5->setFixedSize(70,70);
    RedSoldier5->move(755,305);
    QPushButton * BlackSoldier5 = new QPushButton("卒",this);
    BlackSoldier5->setFixedSize(70,70);
    BlackSoldier5->move(755,575);
    QPushButton * RedCannon1 = new QPushButton("炮",this);
    RedCannon1->setFixedSize(70,70);
    RedCannon1->move(125,215);
    QPushButton * RedCannon2 = new QPushButton("炮",this);
    RedCannon2->setFixedSize(70,70);
    RedCannon2->move(665,215);
    QPushButton * BlackCannon1 = new QPushButton("炮",this);
    BlackCannon1->setFixedSize(70,70);
    BlackCannon1->move(125,665);
    QPushButton * BlackCannon2 = new QPushButton("炮",this);
    BlackCannon2->setFixedSize(70,70);
    BlackCannon2->move(665,665);
    QPushButton * RedRook1 = new QPushButton("车",this);
    RedRook1->setFixedSize(70,70);
    RedRook1->move(35,35);
    QPushButton * RedRook2 = new QPushButton("车",this);
    RedRook2->setFixedSize(70,70);
    RedRook2->move(755,35);
    QPushButton * BlackRook1 = new QPushButton("車",this);
    BlackRook1->setFixedSize(70,70);
    BlackRook1->move(35,845);
    QPushButton * BlackRook2 = new QPushButton("車",this);
    BlackRook2->setFixedSize(70,70);
    BlackRook2->move(755,845);
    QPushButton * RedHorse1 = new QPushButton("马",this);
    RedHorse1->setFixedSize(70,70);
    RedHorse1->move(125,35);
    QPushButton * RedHorse2 = new QPushButton("马",this);
    RedHorse2->setFixedSize(70,70);
    RedHorse2->move(665,35);
    QPushButton * BlackHorse1 = new QPushButton("马",this);
    BlackHorse1->setFixedSize(70,70);
    BlackHorse1->move(125,845);
    QPushButton * BlackHorse2 = new QPushButton("马",this);
    BlackHorse2->setFixedSize(60,60);
    BlackHorse2->move(665,845);
    QPushButton * RedElephant1 = new QPushButton("象",this);
    RedElephant1->setFixedSize(70,70);
    RedElephant1->move(215,35);
    QPushButton * RedElephant2 = new QPushButton("象",this);
    RedElephant2->setFixedSize(70,70);
    RedElephant2->move(575,35);
    QPushButton * BlackElephant1 = new QPushButton("象",this);
    BlackElephant1->setFixedSize(70,70);
    BlackElephant1->move(215,845);
    QPushButton * BlackElephant2 = new QPushButton("象",this);
    BlackElephant2->setFixedSize(70,70);
    BlackElephant2->move(575,845);
    QPushButton * RedScholar1 = new QPushButton("士",this);
    RedScholar1->setFixedSize(70,70);
    RedScholar1->move(305,35);
    QPushButton * RedScholar2 = new QPushButton("士",this);
    RedScholar2->setFixedSize(70,70);
    RedScholar2->move(485,35);
    QPushButton * BlackScholar1 = new QPushButton("士",this);
    BlackScholar1->setFixedSize(70,70);
    BlackScholar1->move(305,845);
    QPushButton * BlackScholar2 = new QPushButton("士",this);
    BlackScholar2->setFixedSize(70,70);
    BlackScholar2->move(485,845);
    QPushButton * RedMarshal = new QPushButton("帅",this);
    RedMarshal->setFixedSize(70,70);
    RedMarshal->move(395,35);
    QPushButton * BlackMarshal = new QPushButton("将",this);
    BlackMarshal->setFixedSize(70,70);
    BlackMarshal->move(395,845);

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
