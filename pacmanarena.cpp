#include <QPainter>
#include <iostream>
#include <vector>
#include <QGraphicsView>

#include "pacmanarena.h"
#include "levelboard.h"
#include "player.h"

PacmanArena::PacmanArena(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    foodSpawned = false;
}


void PacmanArena::paintEvent(QPaintEvent * /* event */)
{
    if(!foodSpawned)
        spawnFood();

    QPainter painter(this);

    drawBoard(painter);
    drawFood(painter);
    drawPlayer(painter);

    std::cout << "width: " << rect().width() << " height: " << rect().height() << std::endl;
    
    //emit foodEaten();
}

void PacmanArena::drawBoard(QPainter &painter){
  
    painter.setPen(Qt::black);
    painter.setBrush(Qt::darkBlue);

    for (int i = 0; i < 31; ++i){
        for (int j = 0; j < 28; ++j){
            if (levelBoard[i][j] == 1){
                painter.drawRect(j / 28.0 * rect().width(), i / 31.0 * rect().height(), rect().width() / 28.0, rect().height() / 31.0);
            }
        }
    }
}

void PacmanArena::drawFood(QPainter &painter){
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::yellow);


	for(std::vector<QRect>::iterator it = food.begin(); it != food.end(); ++it)
	{
		painter.drawEllipse(*it);
	}

}

void PacmanArena::drawPlayer(QPainter &painter){
   
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::darkYellow);
 
    painter.drawEllipse(*player);
}

void PacmanArena::spawnFood(){
    playerRadius = rect().width() / columns;
    player = new QRect(13.0 * rect().width() / columns, 17.0 * rect().height() / rows, playerRadius, playerRadius);

    for (int i = 0; i < 31; ++i){
        for (int j = 0; j < 28; ++j){
            if (levelBoard[i][j] == 2){
                food.push_back(QRect(j * 1.0 / columns * rect().width() + 1.0 * rect().width() / columns / 3, i * 1.0 / rows * rect().height() + 1.0 * rect().height() / rows / 3, 1.0 * rect().width() / columns / 3, 1.0 * rect().height() / rows / 3));
                // (j * 1.0 / columns * rect().width() + 1.0 * rect().width() / columns / 3, i * 1.0 / rows * rect().height() + 1.0 * rect().height() / rows / 3, 1.0 * rect().width() / columns / 3, 1.0 * rect().height() / rows / 3);
            }
        }
    }
    std::cout << "FOOD SPAWNED" << std::endl;
    foodSpawned = true;
}

// void PacmanArena::keyPressEvent(QKeyEvent *event){

//     std::cout << "Dziala" << std::endl;
//     // qDebug() << "Player knows you pressed a key!";
//     // if (event->key() == Qt::Key_Left){
//     //     setPos(x()-10,y());
//     // }
//     // else if (event->key() == Qt::Key_Right){
//     //     setPos(x()+10, y());
//     // }
// }

void PacmanArena::restartGame(){
    // player->xPos = rect().width();
    // player->yPos = rect().height();
    // player->radius = rect().width() / columns;
}