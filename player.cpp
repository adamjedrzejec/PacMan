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
}

void Player::tick(){
    move();
}

void Player::setStartCoordinates(int row, int col){
    currentColumn = col;
    currentRow = row;
}

void Player::move(){

    std::cout << "movementDone currentRow: " << currentRow << " currentColumn: " << currentColumn << std::endl;

    switch(playerDir){
        case 1:
            currentRow -= 1;
            break;
        case 2:
            currentColumn += 1;
            break;
        case 3:
            currentRow += 1;
            break;
        case 4:
            currentColumn += 1;
            break;
    }
}

void Player::drawPlayer(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);
    
    painter.drawEllipse(currentColumn / 28.0 * arena->rect().width(), currentRow / 31.0 * arena->rect().height(), arena->rect().width() / 28.0, arena->rect().height() / 31.0);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
    {
        playerDir = 2;  //up
    }
    if(event->key() == Qt::Key_Down)
    {
        playerDir = 4; //down
    }
    if(event->key() == Qt::Key_Left)
    {
        playerDir = 3; //left
    }
    if(event->key() == Qt::Key_Right)
    {
        playerDir = 1; //right
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