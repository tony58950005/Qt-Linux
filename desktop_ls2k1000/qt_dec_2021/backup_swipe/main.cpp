#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlEngine>
#include <QProcess>
#include <QQuickWindow>
#include <QtQml>
#include <QQuickView>
#include <QObject>
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
    //viewer.show();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/Page1Form.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/Page2Form.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));
    if (engine.rootObjects().isEmpty())
        return -1;

    //viewer.show();
    return app.exec();
}
