#include "ghost.h"
#include "gameboard.h"


Ghost::Ghost(PacmanArena *a, Player *p, QWidget *parent)
    :QWidget(parent)
{
    arena = a;
    player = p;
    canBeEaten = false;
    setStartCoordinates();
    atSpawn = true;
    ghostDir = 0;
}


void Ghost::drawGhost(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    if(canBeEaten)
    {
        painter.setBrush(QColor(qRgb(173, 204, 255)));
    }
    else
    {
        painter.setBrush(QColor(qRgb(252, 76, 12)));
    }


    painter.drawEllipse(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0,  arena->rect().height() / 31.0);
}

void Ghost::setStartCoordinates(){
    currentRow = 14;
    currentColumn = 13;
}

void Ghost::tick()
{
    move();
}

void Ghost::move()
{
    if(atSpawn){
        currentRow -= 1;

        if (currentRow == 11)
            atSpawn = false;
    }
    else{
        movementMade = false;

        do{
            ghostDir = rand() % 4 + 1;

            switch(ghostDir){
                case UP:
                    if(arena->gameMap[currentRow - 1][currentColumn] != 1){
                        currentRow -= 1;
                        movementMade = true;
                    }
                    break;
                case RIGHT:
                    if(currentColumn == arena->gameColumns - 1)
                        currentColumn = -1;
                    if(arena->gameMap[currentRow][currentColumn + 1] != 1){
                        currentColumn += 1;
                        movementMade = true;
                    }
                    break;
                case DOWN:
                    if((arena->gameMap[currentRow + 1][currentColumn] != 1) && (arena->gameMap[currentRow + 1][currentColumn] != 3)){
                        currentRow += 1;
                        movementMade = true;
                    }
                    break;
                case LEFT:
                    if(currentColumn == 0)
                        currentColumn = arena->gameColumns;
                    if(arena->gameMap[currentRow][currentColumn - 1] != 1){
                        currentColumn -= 1;
                        movementMade = true;
                    }
                    break;
            }
        }while (!movementMade);
    }
}
