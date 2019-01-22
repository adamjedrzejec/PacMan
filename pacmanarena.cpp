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
    player = new Player(this);
    player ->setStartCoordinates(17, 13);
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    foodSpawned = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(drawScene()));
    timer->start(1000);
}

// void PacmanArena::drawScene(){
//     QPainter painter(this);
//     drawBoard(painter);
//     drawFood(painter);
//     update();
// }


void PacmanArena::paintEvent(QPaintEvent * /* event */)
{
    // if(!foodSpawned)
        // spawnFood();

    // player->setFlag(QGraphicsItem::ItemIsFocusable);
    // player->setFocus();

    QPainter painter(this);

    drawBoard(painter);
    drawFood(painter);
    player->drawPlayer(painter);

    std::cout << "width: " << rect().width() << " height: " << rect().height() << std::endl;
    
    //emit foodEaten();
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

// void PacmanArena::drawPlayer(QPainter &painter){
   
//     painter.setPen(Qt::NoPen);
//     painter.setBrush(Qt::darkYellow);
 
//     painter.drawEllipse(player->xPos, player->yPos, player->radius, player->radius);
// }

// void PacmanArena::spawnFood(){
//     // playerRadius = rect().width() / columns;
//     player = new Player;
//     playerDir = 0;
//     player->xPos = 13.0 * rect().width() / gameColumns;
//     player->yPos = 17.0 * rect().height() / gameRows;
//     player->radius = rect().width() / gameColumns;

//     // player = new QRect(13.0 * rect().width() / columns, 17.0 * rect().height() / rows, playerRadius, playerRadius);

//     for (int i = 0; i < 31; ++i){
//         for (int j = 0; j < 28; ++j){
//             if (gameMap[i][j] == 2){
//                 food.push_back(QRect(j * 1.0 / gameColumns * rect().width() + 1.0 * rect().width() / columns / 3, i * 1.0 / rows * rect().height() + 1.0 * rect().height() / rows / 3, 1.0 * rect().width() / columns / 3, 1.0 * rect().height() / rows / 3));
//                 // (j * 1.0 / columns * rect().width() + 1.0 * rect().width() / columns / 3, i * 1.0 / rows * rect().height() + 1.0 * rect().height() / rows / 3, 1.0 * rect().width() / columns / 3, 1.0 * rect().height() / rows / 3);
//             }
//         }
//     }
//     std::cout << "FOOD SPAWNED" << std::endl;
//     foodSpawned = true;
// }



void PacmanArena::restartGame(){
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

void PacmanArena::tick(){
//     player->tick(playerDir, this);
}