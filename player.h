#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>

class PacmanArena;

class Player : public QWidget
{
public:
    Player(PacmanArena *a, QWidget *parent = 0);
    // void drawPlayer(int x, int y, QPainter &painter);
    // void keyPressEvent(QKeyEvent * event);
    void tick();
    void drawPlayer(QPainter &painter);
    void setStartCoordinates(int row, int col);
private:
    PacmanArena *arena;
    void move();
    int currentRow, currentColumn;
    int radius;
    int playerDir;
};


#endif