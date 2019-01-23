#include "ghost.h"
#include "gameboard.h"


Ghost::Ghost(PacmanArena *a, Player *p, QWidget *parent)
    :QWidget(parent)
{
    arena = a;
    player = p;
}

void Ghost::drawGhost(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);

    painter.drawEllipse(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0,  arena->rect().height() / 31.0);
}

// void Ghost::paintGhost(int x, int y, QPainter &painter)
// {
//     painter.setPen(Qt::NoPen);
//     if(canBeEaten)
//     {
//         painter.setBrush(Qt::green);
//     }
//     else
//     {
//         painter.setBrush(Qt::red);
//     }
//     painter.drawEllipse(x + (width/4), y, width, height);
// }

void Ghost::setStartCoordinates(int row, int col){
    currentColumn = col;
    currentRow = row;
}


void Ghost::moveGhost()
{
    
}
