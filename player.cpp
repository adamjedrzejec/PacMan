#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>

#include "player.h"


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