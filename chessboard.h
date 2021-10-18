#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include<QPaintEvent>
#include<QWidget>
#include<QMouseEvent>
#include<QPainter>
#include"positionmessage.h"
#include<QVector>

/****************
 * author:杨臻烨 *
 ****************/
class ChessBoard : public QWidget {
public:
    int moveX = 0, moveY = 0;//左下角原点
    int moveX1 = 0, moveY1 = 0;//左上角原点
    explicit ChessBoard(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);//override绘图函数
    void mouseMoveEvent(QMouseEvent *ev);

    void paintLine(QPainter *p, int _x, int _y);//绘制折线
    void mousePressEvent(QMouseEvent *eve);

    static QVector <PositionMessage> position[90][90];
    static int mouse_click_pos_x;
    static int mouse_click_pos_y;

    static int xIndex2Position(int x);

    static int yIndex2Position(int y);
};

#endif // CHESSBOARD_H
