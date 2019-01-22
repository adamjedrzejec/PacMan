#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <iostream>

#include "player.h"
#include "pacmanarena.h"

// void Player::drawPlayer(int x, int y, QPainter &painter)
// {
//     painter.setPen(Qt::NoPen);
//     painter.setBrush(Qt::yellow);
    
//     painter.drawEllipse(x, y, 30, 30);
// }

// void Player::keyPressEvent(QKeyEvent *event){
//     // qDebug() << "Player knows you pressed a key!";
//     if (event->key() == Qt::Key_Left){
//         setPos(x()-10,y());
//     }
//     else if (event->key() == Qt::Key_Right){
//         setPos(x()+10, y());
//     }
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

void Player::tick(int &playerDir, PacmanArena *pa){
    move(playerDir, pa);
}

void Player::move(int &playerDir, PacmanArena *pa){

    currentRow = (yPos + 10) / (pa->height() / 31.0);
    currentColumn = (xPos + 10) / (pa->width() / 28.0);

    std::cout << "movementDone currentRow: " << currentRow << " currentColumn: " << currentColumn << std::endl;

    switch(playerDir){
        case 1:
            xPos =  
    }

    pa->update();
}