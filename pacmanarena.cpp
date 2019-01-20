#include <QPainter>
#include <iostream>
#include <vector>
#include <QGraphicsView>

#include "pacmanarena.h"
#include "levelboard.h"


PacmanArena::PacmanArena(QWidget *parent)
    : QWidget(parent)
{
    setPalette(QPalette(QColor(0, 0, 0)));
    setAutoFillBackground(true);
    // std::cout << "width: " << width() << " height: " << height() << std::endl;

    // setPalette(QPalette(QColor(0, 0, 0)));
    // setAutoFillBackground(true);
    
    // for (int i = 0; i < 31; ++i){
    //     for (int j = 0; j < 28; ++j){
    //         if (levelBoard[i][j] == 2){
    //             //food.emplace_back(new Food(j, i));
                
    //         }
    //     }
    // }

    // scene->addItem(player);

    // player->setFlag(QGraphicsItem::ItemIsFocusable);
    // player->setFocus();

    // QGraphicsView * view = new QGraphicsView(scene);
}


void PacmanArena::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    drawBoard(painter);
    drawFood(painter);

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

    for (int i = 0; i < 31; ++i){
        for (int j = 0; j < 28; ++j){
            if (levelBoard[i][j] == 2){
                painter.drawEllipse(j * 1.0 / columns * rect().width() + 1.0 * rect().width() / columns / 3, i * 1.0 / rows * rect().height() + 1.0 * rect().height() / rows / 3, 1.0 * rect().width() / columns / 3, 1.0 * rect().height() / rows / 3);
            }
        }
    }
}