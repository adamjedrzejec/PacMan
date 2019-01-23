#ifndef GHOST_H
#define GHOST_H

#include <QWidget>
#include <QPainter>

#include "pacmanarena.h"
#include "player.h"

class Ghost : public QWidget
{
    Q_OBJECT
public:
    Ghost(PacmanArena *a, Player *p, QWidget *parent = 0);
    PacmanArena *arena;
    Player *player;
    void drawGhost(QPainter &painter);
    void setStartCoordinates(int row, int col);
private slots:
    void moveGhost();
signals:
    
protected:
    
private:
    int currentRow, currentColumn;
};


#endif