#include "controlclass.h"
#include <QDebug>

ControlClass::ControlClass(QObject *parent) : QObject(parent)
{

}

// GETTER
int ControlClass::getCounter() const
{
    return m_counter;
}

// SETTER
void ControlClass::setCounter(int value)
{
    if(value != m_counter){
        m_counter = value;
        // jeśli nastapi zmiana w kodzie c++ zrób coś w kodzie QML
        emit counterChanged();
    }
}

// SLOT - wykonanie czegoś w wyniku akcji w QML
void ControlClass::doSomething()
{
    qDebug() << "I can do sth";
}
