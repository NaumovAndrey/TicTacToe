#include "GameWindow.h"
#include <QPushButton>
#include <QVBoxLayout>

GameWindow::GameWindow(QWidget *parent) : QWidget(parent), gameLogic(new GameLogic(this))
{
    setupUi();
    connectSignals();
}

GameWindow::~GameWindow()
{
    delete gameLogic;
}

void GameWindow::setupUi()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    resetButton = new QPushButton("Reset Game", this);
    gameTable = new QTableWidget(3, 3, this);

    layout->addWidget(resetButton);
    layout->addWidget(gameTable);
    setLayout(layout);
}

void GameWindow::connectSignals()
{
    connect(gameTable, &QTableWidget::cellClicked, this, &GameWindow::handleCellClicked);
    connect(resetButton, &QPushButton::clicked, this, &GameWindow::resetGame);
}

void GameWindow::handleCellClicked(int row, int column)
{
    if(gameLogic->makeMove(row, column)) {
        gameTable->setItem(row, column, new QTableWidgetItem(gameLogic->currentPlayerSymbol()));
        if(gameLogic->checkWin(row, column)) {
            // Show win message
        } else {
            gameLogic->nextPlayer();
        }
    }
}

void GameWindow::resetGame()
{
    gameLogic->reset();
    gameTable->clear();
}