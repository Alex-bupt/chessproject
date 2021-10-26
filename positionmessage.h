#ifndef POSITIONMESSAGE_H
#define POSITIONMESSAGE_H

class PositionMessage
{

public:
    explicit PositionMessage();
    bool isFilled=false;
    int character{-1};//0:balcak,1:red
    int piece{0};//1:帅 2:士 3:象 4:马 5:车 6:炮 7:兵
    static PositionMessage position[9][10];
};

#endif // POSITIONMESSAGE_H
