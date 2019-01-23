#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <iostream>


#include "player.h"
#include "pacmanarena.h"


Player::Player(PacmanArena *a, QWidget *parent)
    :QWidget(parent)
{
    arena = a;
    setFocusPolicy(Qt::StrongFocus);
    playerDir = 0;
    animationTimer = 0;
}

void Player::tick(){
    move();

    if (arena->gameMap[currentRow][currentColumn] == 2){
        arena->gameMap[currentRow][currentColumn] = 0;
        emit foodEaten();
    }
}

void Player::setStartCoordinates(){
    currentColumn = 13;
    currentRow = 17;
}

void Player::move(){

    std::cout << "playerDir: " << playerDir << " currentRow: " << currentRow << " currentColumn: " << currentColumn << std::endl;
    
    
    if (playerDir == LEFT && currentColumn == 0){
        currentColumn = arena->gameColumns;
    }

    if (playerDir == RIGHT && currentColumn == arena->gameColumns - 1){
        currentColumn = -1;
    }

    switch(playerDir){
        case UP:
            if(arena->gameMap[currentRow - 1][currentColumn] != 1)
                currentRow -= 1;
            break;
        case RIGHT:
            if(arena->gameMap[currentRow][currentColumn + 1] != 1)
                currentColumn += 1;
            break;
        case DOWN:
            if((arena->gameMap[currentRow + 1][currentColumn] != 1) && (arena->gameMap[currentRow + 1][currentColumn] != 3))
                currentRow += 1;
            break;
        case LEFT:
            if(arena->gameMap[currentRow][currentColumn - 1] != 1)
                currentColumn -= 1;
            break;
    }
}

void Player::drawPlayer(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(qRgb(234, 222, 51)));

    rotation = (playerDir - 1) * 90 + 45;

    if (animationTimer == 0)
        painter.drawPie(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0,  arena->rect().height() / 31.0, rotation * 16, 270 * 16);
    else
        painter.drawPie(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0,  arena->rect().height() / 31.0, (rotation - 30) * 16, 330 * 16);

    ++animationTimer;

    animationTimer %= 2;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        playerDir = UP;  //enum 2
    }
    if(event->key() == Qt::Key_Down)
    {
        playerDir = DOWN; //enum 4
    }
    if(event->key() == Qt::Key_Left)
    {
        playerDir = LEFT; //enum 3
    }
    if(event->key() == Qt::Key_Right)
    {
        playerDir = RIGHT; //enum 1
    }
}

// void Player::drawPlayer(int x, int y, QPainter &painter)
// {
//     painter.setPen(Qt::NoPen);
//     painter.setBrush(Qt::yellow);
    
//     painter.drawEllipse(x, y, 30, 30);
// }

// void Player::keyPressEvent(QKeyEvent *event){
//     //qDebug() << "Player knows you pressed a key!";
//     if (event->key() == Qt::Key_Left){
//         setPos(x()-10,y());
//     }
//     else if (event->key() == Qt::Key_Right){
//         // setPos(x()+10, y());
//         std::cout << "KDETCTD" << std::endl;
//         xPos += 20;
//     }
//     else if (event->key() == Qt::Key_Up){
//         setPos(x(), y()-10);
//     }
//     else if (event->key() == Qt::Key_Down){
//         setPos(x(), y()+10);
//     }
// }