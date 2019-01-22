#include <QPainter>
#include <iostream>
#include <vector>
#include <QGraphicsView>
#include <QtCore>

#include "pacmanarena.h"
#include "player.h"

PacmanArena::PacmanArena(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    player = new Player(this);
    player->setStartCoordinates(17, 13);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(this->tick()));
    timer->start(1000);
}

void PacmanArena::paintEvent(QPaintEvent * /* event */)
{
    // player->setFlag(QGraphicsItem::ItemIsFocusable);
    // player->setFocus();

    QPainter painter(this);

    drawBoard(painter);
    drawFood(painter);
    player->drawPlayer(painter);

    std::cout << "width: " << rect().width() << " height: " << rect().height() << std::endl;
}

void PacmanArena::drawBoard(QPainter &painter){
  
    painter.setPen(Qt::black);
    painter.setBrush(Qt::darkBlue);

    for (int i = 0; i < 31; ++i){
        for (int j = 0; j < 28; ++j){
            if (gameMap[i][j] == 1){
                painter.drawRect(j / 28.0 * rect().width(), i / 31.0 * rect().height(), rect().width() / 28.0, rect().height() / 31.0);
            }
        }
    }
}

void PacmanArena::drawFood(QPainter &painter){
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);

    for (int i = 0; i < 31; ++i){
        for (int j = 0; j < 28; ++j){
            if (gameMap[i][j] == 2){
                painter.drawEllipse(j * 1.0 / gameColumns * rect().width() + 1.0 * rect().width() / gameColumns / 3, i * 1.0 / gameRows * rect().height() + 1.0 * rect().height() / gameRows / 3, 1.0 * rect().width() / gameColumns / 3, 1.0 * rect().height() / gameRows / 3);
            }
        }
    }
}

void PacmanArena::tick(){
    player->tick();
}

void PacmanArena::restartGame(){
    std::copy(&gameStartMap[0][0], &gameStartMap[0][0]+gameRows*gameColumns,&gameMap[0][0]);
    // player->xPos = rect().width();
    // player->yPos = rect().height();
    // player->radius = rect().width() / columns;
}

// void PacmanArena::keyDetected(int i){
//     switch (i){
//         case 1:
//             std::cout << "ArrowUp detected" << std::endl;
//             break;
//         case 2:
//             std::cout << "ArrowRight detected" << std::endl;
//             break;
//         case 3:
//             std::cout << "ArrowDown detected" << std::endl;
//             break;
//         case 4:
//             std::cout << "ArrowLeft detected" << std::endl;
//             break;
//     }
// }