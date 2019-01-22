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
    // void keyPressEvent(QKeyEvent * event);
    void restartGame();
    int playerDir;
signals:
    void foodEaten();

protected:
    void paintEvent(QPaintEvent *event);

protected slots:
    // void keyDetected(int);
    void tick();

private:
    void drawBoard(QPainter &painter);
    void drawFood(QPainter &painter);
    void drawPlayer(QPainter &painter);
    // void drawPlayer(QPainter &painter, Player &player);
    bool foodSpawned;
    void spawnFood();
    Player *player;
    QTimer *timer;
    std::vector<QRect> food;
};

#endif
