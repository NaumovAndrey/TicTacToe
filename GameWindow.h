#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include "GameLogic.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void handleCellClicked(int row, int column);
    void resetGame();

private:
    QTableWidget *gameTable;
    QPushButton *resetButton;
    GameLogic *gameLogic;
    void setupUi();
    void connectSignals();
};

#endif // GAMEWINDOW_H