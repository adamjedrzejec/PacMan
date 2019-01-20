#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>

class Player : public QGraphicsEllipseItem
{
public:
    Player() : xPos(0), yPos(0) {};
    // void drawPlayer(int x, int y, QPainter &painter);
    // void keyPressEvent(QKeyEvent * event);

    int xPos, yPos;
    private:
};


#endif