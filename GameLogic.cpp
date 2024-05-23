#include "GameLogic.h"

GameLogic::GameLogic(QObject *parent) : QObject(parent), currentPlayer(1), winCondition(3)
{
    board.resize(3, std::vector<int>(3, 0));
}

bool GameLogic::makeMove(int row, int column)
{
    if(board[row][column] == 0) {
        board[row][column] = currentPlayer;
        return true;
    }
    return false;
}

void GameLogic::reset()
{
    for(auto &row : board) {
        std::fill(row.begin(), row.end(), 0);
    }
    currentPlayer = 1;
}

bool GameLogic::checkWin(int row, int column)
{
    static const std::vector<std::pair<int, int>> directions = {
        {1, 0}, {0, 1}, {1, 1}, {1, -1}
    };
    for(const auto &dir : directions) {
        if(checkWinCondition(row, column, dir.first, dir.second)) {
            return true;
        }
    }
    return false;
}

void GameLogic::nextPlayer()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

QString GameLogic::currentPlayerSymbol() const
{
    return (currentPlayer == 1) ? "X" : "O";
}

bool GameLogic::checkWinCondition(int row, int column, int dx, int dy)
{
    int count = 0;
    for(int i = -winCondition + 1; i < winCondition; ++i) {
        int r = row + i * dx;
        int c = column + i * dy;
        if(r >= 0 && r < board.size() && c >= 0 && c < board[r].size() && board[r][c] == currentPlayer) {
            if(++count == winCondition) {
                return true;
            }
        } else {
            count = 0;
        }
    }
    return false;
}