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
}

void Player::tick(){
    move();

    if (arena->gameMap[currentRow][currentColumn] == 2){
        arena->gameMap[currentRow][currentColumn] = 0;
    }
}

void Player::setStartCoordinates(int row, int col){
    currentColumn = col;
    currentRow = row;
}

void Player::move(){

    std::cout << "playerDir: " << playerDir << " currentRow: " << currentRow << " currentColumn: " << currentColumn << std::endl;
    
    
    if (playerDir == 4 && currentColumn == 0){
        currentColumn = arena->gameColumns;
    }

    if (playerDir == 2 && currentColumn == arena->gameColumns - 1){
        currentColumn = -1;
    }

    switch(playerDir){
        case 1:
            if(arena->gameMap[currentRow - 1][currentColumn] != 1)
                currentRow -= 1;
            break;
        case 2:
            if(arena->gameMap[currentRow][currentColumn + 1] != 1)
                currentColumn += 1;
            break;
        case 3:
            if(arena->gameMap[currentRow + 1][currentColumn] != 1)
                currentRow += 1;
            break;
        case 4:
            if(arena->gameMap[currentRow][currentColumn - 1] != 1)
                currentColumn -= 1;
            break;
    }
}

void Player::drawPlayer(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(qRgb(234, 222, 51)));
    
    painter.drawEllipse(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0, arena->rect().height() / 31.0);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        playerDir = 1;  //up
    }
    if(event->key() == Qt::Key_Down)
    {
        playerDir = 3; //down
    }
    if(event->key() == Qt::Key_Left)
    {
        playerDir = 4; //left
    }
    if(event->key() == Qt::Key_Right)
    {
        playerDir = 2; //right
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