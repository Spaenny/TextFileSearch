#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    MainWindow window;
    window.show();

    return prog.exec();
}
