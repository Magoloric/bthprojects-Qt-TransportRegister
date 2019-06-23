#include "transportregisterwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //Main was modified to make login and logout functions work correctly
    int currentExitCode = 0;

    do {
        QApplication a(argc, argv);
        TransportRegisterWindow w;
        Login l(&w);
        l.show();
        currentExitCode = a.exec();
    } while( currentExitCode == TransportRegisterWindow::EXIT_CODE_REBOOT );

    return currentExitCode;
}
