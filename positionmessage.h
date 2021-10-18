#ifndef POSITIONMESSAGE_H
#define POSITIONMESSAGE_H

#include <QWidget>

class PositionMessage : public QWidget
{
    Q_OBJECT
public:
    explicit PositionMessage(QWidget *parent = nullptr);
    bool isFilled=false;
    int character{-1};//0:black 1:red
    int piece{0};//1:帅 2:士 3:象 4:马 5:车 6:炮 7:兵
signals:

};

#endif // POSITIONMESSAGE_H
