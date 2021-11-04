#include "positionmessage.h"
PositionMessage PositionMessage::position[9][10];
PositionMessage::PositionMessage()
{
        for(int i=0;i<9;i++)
            for(int j=0;j<10;j++){
                position[i][j].character=-1;
                position[i][j].isFilled=false;
                position[i][j].piece=0;
}
    //更新坐标信息
        for(int i=0;i<9;i++){
            position[i][0].isFilled=true;
            position[i][0].character=1;
        }
        int j=5;
        for(int i=0;i<5;i++){
            position[i][0].piece=j;
            j--;
        }
        int k=2;
        for(int i=5;i<9;i++){
            position[i][0].piece=k;
            k++;
        }
        for(int i=0;i<9;i++){
            position[i][9].isFilled=true;
            position[i][9].character=0;
        }
        int q=5;
        for(int i=0;i<5;i++){
            position[i][9].piece=q;
            q--;
        }
        int p=2;
        for(int i=5;i<9;i++){
            position[i][9].piece=p;
            p++;
        }
        for(int i=0;i<9;i=i+2){
            position[i][3].isFilled=true;
            position[i][3].piece=7;
            position[i][3].character=1;
        }
        for(int j=0;j<9;j=j+2){
            position[j][6].isFilled=true;
            position[j][6].piece=7;
            position[j][6].character=0;
        }
        position[1][2].isFilled=true;
        position[1][2].piece=6;
        position[1][2].character=1;
        position[7][2].isFilled=true;
        position[7][2].piece=6;
        position[7][2].character=1;
        position[1][7].isFilled=true;
        position[1][7].piece=6;
        position[1][7].character=0;
        position[7][7].isFilled=true;
        position[7][7].piece=6;
        position[7][7].character=0;
}
