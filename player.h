#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QKeyEvent>

class PacmanArena;

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(PacmanArena *a, QWidget *parent = 0);
    void tick();
    void drawPlayer(QPainter &painter);
    void setStartCoordinates(int row, int col);
signals:
    void foodEaten();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    PacmanArena *arena;
    int animationTimer;
    void move();
    int currentRow, currentColumn;
    int playerDir;
    int rotation;
};


#endif