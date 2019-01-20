#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QPushButton>
#include <QShortcut>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>

#include "pacmanarena.h"
#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("&Quit"));
    quit->setFont(QFont("Times", 18, QFont::Bold));

    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QFrame *pacmanBox = new QFrame;
    pacmanBox->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);

    pacmanArena = new PacmanArena;

    connect(pacmanArena, SIGNAL(foodEaten()),
            this, SLOT(increasePoints()));

    QPushButton *restart = new QPushButton(tr("&New Game"));

    connect(restart, SIGNAL(clicked()), this, SLOT(newGame()));


    points = new QLCDNumber(3);
    points->setSegmentStyle(QLCDNumber::Filled);

    (void) new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(quit);
    topLayout->addWidget(points);
    topLayout->addWidget(restart);

    QVBoxLayout *cannonLayout = new QVBoxLayout;
    cannonLayout->addWidget(pacmanArena);
    pacmanBox->setLayout(cannonLayout);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addLayout(topLayout, 0, 0);
    gridLayout->addWidget(pacmanBox, 1, 0);
    gridLayout->setRowStretch(1, 0);
    setLayout(gridLayout);


    newGame();
}


void GameBoard::increasePoints()
{
    points->display(points->value() + 1);
}


void GameBoard::newGame()
{
    points->display(0);
    pacmanArena->restartGame();
}

