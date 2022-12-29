#include "dog.h"
#include <QCoreApplication>
#include <QDebug>
#include <QTest>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dog dog;
    QTest::qExec(&dog);
//    dog.dumpObjectTree();
//    dog.dumpObjectInfo();

    return a.exec();
}
