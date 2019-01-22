#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>

class PacmanArena;

class Player : public QGraphicsEllipseItem
{
public:
    Player() : xPos(0), yPos(0), radius(10) {};
    // void drawPlayer(int x, int y, QPainter &painter);
    // void keyPressEvent(QKeyEvent * event);

    int xPos, yPos;
    int radius;
    void tick(int &, PacmanArena *);
private:
    void move(int &, PacmanArena *);
    int currentRow, currentColumn;
};


#endif