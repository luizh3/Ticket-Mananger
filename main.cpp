#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "bilheteformatar.h"
#include "control.h"
#include "telaconfiggeral/telaconfiggeral.h"
#include "bilheteentradaousaida/bilheteentradaousaida.h"

int main(int argc, char *argv[]){
    QQuickStyle::setStyle("Default");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    qmlRegisterType<Control>("br.com.bilhete.com",1,0,"ControlV9");
    qmlRegisterType<BilheteFormatar>("br.com.bilhete",1,0,"Bilhete");
    qmlRegisterType<TelaConfigGeral>("br.com.telaconfiggeral",1,0,"ConfigGeral");
    qmlRegisterType<BilheteEntradaOuSaida>("br.com.bilheteentradaousaida",1,0,"BilheteEntradaOuSaida");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
//Default Style
//Fusion Style
//Imagine Style
//Material Style
//Universal Style
