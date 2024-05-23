#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QObject>
#include <vector>

class GameLogic : public QObject
{
    Q_OBJECT

public:
    explicit GameLogic(QObject *parent = nullptr);
    bool makeMove(int row, int column);
    void reset();
    bool checkWin(int row, int column);
    void nextPlayer();
    QString currentPlayerSymbol() const;

private:
    std::vector<std::vector<int>> board;
    int currentPlayer;
    int winCondition;
    bool checkWinCondition(int row, int column, int dx, int dy);

};

#endif // GAMELOGIC_H