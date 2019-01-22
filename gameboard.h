#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>

class QLCDNumber;
class PacmanArena;

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = 0);
signals:
    // void sendKey(int);
protected slots:
    void increasePoints();
    void newGame();

private:
    QLCDNumber *points;
    PacmanArena *pacmanArena;
};

#endif
