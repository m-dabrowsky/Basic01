#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controlclass.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    /*
     *  --- Dla QQmlContext ---
     */

    //ControlClass myClass;


    /*
     *  --- Dla RegisterType ---
     */
    qmlRegisterType<ControlClass>("Mike", 1, 0, "ControlClass");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    /*
     *  --- Dla QQmlContext ---
     */

    //QQmlContext *rootContext = engine.rootContext();
    //rootContext->setContextProperty("myClass", &myClass);

    return app.exec();
}
