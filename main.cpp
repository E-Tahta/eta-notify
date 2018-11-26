#include "bridge.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QGuiApplication::setApplicationName("eta-notify");
    QGuiApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription("Eta-notify");
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption messageOption(
                QStringList() << "m" << "message",
                QCoreApplication::translate("main", "set message to be displayed"),
                QCoreApplication::translate("main", "display message"));
    parser.addOption(messageOption);

    QCommandLineOption durationOption(
                QStringList() << "d" << "duration",
                QCoreApplication::translate("main", "set duration"),
                QCoreApplication::translate("main", "seconds"));
    parser.addOption(durationOption);

    QCommandLineOption layoutOption(
                QStringList() << "b" << "big",
                QCoreApplication::translate("main", "set message size to big"));
    parser.addOption(layoutOption);

    parser.process(app);

    bool hasMessage = parser.isSet(messageOption);
    bool hasDuration = parser.isSet(durationOption);
    bool isBig = parser.isSet(layoutOption);

    if (hasMessage) {
        Bridge::s_message = parser.value(messageOption);
    }
    if (hasDuration) {
        Bridge::s_duration = parser.value(durationOption);
    }
    if (isBig) {
        Bridge::s_layout = "big";
    }


    qmlRegisterType<Bridge>("eta.bridge",1,0,"Bridge");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
