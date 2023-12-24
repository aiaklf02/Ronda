#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QList>
#include <QString>
#include "jeu.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    jeu j;

    engine.rootContext()->setContextProperty("jeu",&j);
    engine.rootContext()->setContextProperty("j1",&(j.getJ1()));
    engine.rootContext()->setContextProperty("j2",&(j.getJ2()));
    engine.rootContext()->setContextProperty("Table",&(j.getTable()));
    engine.rootContext()->setContextProperty("cartesMasquees",&(j.getCarteMasquee()));


    const QUrl url(u"qrc:/game/Main.qml"_qs);

    QObject::connect( &engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
