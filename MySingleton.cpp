#include "MySingleton.hpp"
#include <QString>

DECLARE_SINGLETON_INSTANCE(MySingleton) // [[2]]

struct MySingletonPrivate {
    int number;
    QString name;
};

MySingleton::MySingleton() : data(new MySingletonPrivate) {
}

MySingleton::~MySingleton() {
    delete data;
}

void MySingleton::setNumber(int number) {
    data->number = number;
}

int MySingleton::getNumber() const {
    return data->number;
}

void MySingleton::setName(const QString &name) {
    data->name = name;
}

QString MySingleton::getName() const {
    return data->name;
}

void testSingleton() {
    qDebug() << MySingleton::getInstance().getName() << MySingleton::getInstance().getNumber();

    MySingleton::getInstance().setName("WBD");
    MySingleton::getInstance().setNumber(10);
    qDebug() << MySingleton::getInstance().getName() << MySingleton::getInstance().getNumber();
}
