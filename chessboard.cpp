#include "chessboard.h"
#include<QPainter>
#include<QMouseEvent>
#include<QPen>
#include<QBrush>
#include<QDebug>
#include<QRect>
#include<QPushButton>

QVector<PositionMessage> ChessBoard::position[90][90];

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
}

void ChessBoard::mouseMoveEvent(QMouseEvent *ev){
    moveX=(ev->x()-25)/90;
    moveY=(940-ev->y()-25)/90;
    moveX1=(ev->x()-25)/90;
    moveY1=(ev->y()-25)/90;
   // qDebug() << ev->x() <<ev->y();
    qDebug() << moveX1 <<" " <<moveY1;
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
