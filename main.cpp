#include "widget.h"
#include "chessboard.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChessBoard * board= new ChessBoard;
    board->show();
    return a.exec();
}
