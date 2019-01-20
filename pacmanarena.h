#ifndef PACMANARENA_H
#define PACMANARENA_H

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsScene>

class Player;

class PacmanArena : public QWidget
{
    Q_OBJECT

public:
    PacmanArena(QWidget *parent = 0);

signals:
    void foodEaten();

protected:
    void paintEvent(QPaintEvent *event);

private:
    void drawBoard(QPainter &painter);
    void drawFood(QPainter &painter);
    Player *player;
    // std::vector<Food> food;
};

#endif
