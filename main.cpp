#include "mainwindow.h"
#include <iostream>
#include "JpegParser.hpp"
#include "Mapper.hpp"
#include "ScopedPaHandler.hpp"
#include "Sine.cpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
