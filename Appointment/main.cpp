#include "appointmentcheck.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow main;
    main.show();
  //  a.exec();
    return a.exec();
}
