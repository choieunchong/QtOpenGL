#ifndef DOG_H
#define DOG_H

#include <QDebug>
#include <QObject>

class dog : public QObject
{
    Q_OBJECT
public:
    explicit dog(QObject* parent = nullptr);

private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    void bark();
    void rollover();
    void simple();
};

#endif // DOG_H
