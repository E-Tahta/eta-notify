#include "argumentparser.h"
#include <QDebug>
#include <QCoreApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>

ArgumentParser::ArgumentParser(QObject *parent) : QObject(parent)
{
    parser = new QCommandLineParser();

    parser->setApplicationDescription("Eta-notify");
    parser->addHelpOption();
    parser->addVersionOption();

    messageOption = new QCommandLineOption(
                QStringList() << "m" << "message",
                QCoreApplication::translate("main", "set message to be displayed"),
                QCoreApplication::translate("main", "display message"));
    parser->addOption(*messageOption);

    durationOption = new QCommandLineOption(
                QStringList() << "d" << "duration",
                QCoreApplication::translate("main", "set duration"),
                QCoreApplication::translate("main", "seconds"));
    parser->addOption(*durationOption);


    layoutOption = new QCommandLineOption(
                QStringList() << "s" << "small",
                QCoreApplication::translate("main", "set message size to small"));
    parser->addOption(*layoutOption);

    parser->process(QCoreApplication::arguments());

}

QString ArgumentParser::message()
{
    bool hasMessage = parser->isSet(*messageOption);
    if (hasMessage) {
        return parser->value(*messageOption);
    } else {
        qDebug() << "message not found";
        exit(1);
    }
    return "Empty Message";
}

QString ArgumentParser::duration()
{
    bool hasDuration = parser->isSet(*durationOption);
    if (hasDuration) {
        return parser->value(*durationOption);
    }
    return "10";
}

QString ArgumentParser::layout()
{
    bool isSmall = parser->isSet(*layoutOption);
    if (isSmall) {
        return "small";
    }
    return "big";
}
