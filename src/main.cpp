#include <QDebug>
#include <QtGui/QApplication>
#include <QStringList>

#include "segway.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString configPath = "./";
    QString startDirPath = "./";
    double pk = 14.2;
    double dk = 17.7;
    double ik = 1.9;
    
    if (app.arguments().contains("-c")) {
      int const index = app.arguments().indexOf("-c");
      if (app.arguments().count() <= index + 1) {
        return 1;
      }

      configPath = app.arguments()[index + 1];
      if (configPath.right(1) != "/") {
        configPath += "/";
      }
    }
    if (app.arguments().contains("-pk")) {
      int const index = app.arguments().indexOf("-pk");
      if (app.arguments().count() <= index + 1) {
        return 1;
      }

      configPath = app.arguments()[index + 1];
      if (configPath.right(1) != "/") {
        configPath += "/";
      }
    }
    
    if (app.arguments().contains("-h") || app.arguments().contains("--help")) {
      qDebug() << "Flags:";
      
      qDebug() << "-c  -  set path to config file";
//      qDebug() << "-d  -  set path to start directory";

      return 0;
    }

    Segway robot(app.thread(), configPath, startDirPath, pk, dk, ik);

    return app.exec();
}
