#ifndef CONTROLCLASS_H
#define CONTROLCLASS_H

#include <QObject>

class ControlClass : public QObject
{
    Q_OBJECT
    /*
     * Q_PROPERTY - zrobi z counter właściwość dostępną w QML
     *
     */
    Q_PROPERTY(int counter READ getCounter WRITE setCounter NOTIFY counterChanged)
public:
    explicit ControlClass(QObject *parent = nullptr);

    int getCounter() const;                     // getter
    void setCounter(int value);                 // setter

/*
 * SIGNAL - służy do wysyłania informacji z kody C++ do kodu QML
 *
 */
signals:
    void counterChanged();

/*
 * SLOT - służy do wysyłania informacji z kodu QML do C++
 *
 * Żeby funkcja była widoczna w pliku QML musi byc PUBLIC SLOT
 */
public slots:
    void doSomething(); // metoda wywoływana z pliku QML (działa z Conext)


private:
    int m_counter = 0;

};

#endif // CONTROLCLASS_H
