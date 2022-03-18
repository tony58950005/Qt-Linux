#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QProcess>
#include <QQuickWindow>
#include <QtQml>
#include <QQuickView>
#include "openotherapp.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<OpenOtherApp>("com.company.openotherapp",1,0,"Openotherapp");
    QQuickView viewer;
    viewer.rootContext()->setContextProperty("openOtherApp",new OpenOtherApp);
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);
    viewer.setSource(QUrl("qrc://main.qml"));
    viewer.show();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
