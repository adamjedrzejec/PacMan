#include <QApplication>
#include <QTranslator>
#include <QLocale>

#include "gameboard.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameBoard board;
    board.setGeometry(100, 100, 800, 900);
    board.setFixedSize(800, 900);
    board.show();
    return app.exec();
}
