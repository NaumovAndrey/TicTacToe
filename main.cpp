// TicTacToe.cpp: определяет точку входа для приложения.
//

#include "GameWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameWindow window;
    window.show();
    return app.exec();
}