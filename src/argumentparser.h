#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

#include <QObject>
class QCommandLineParser;
class QCommandLineOption;

class ArgumentParser : public QObject
{
    Q_OBJECT
public:
    explicit ArgumentParser(QObject *parent = 0);

    QString message();
    QString duration();
    QString layout();
private:
    QCommandLineParser *parser;
    QCommandLineOption *messageOption;
    QCommandLineOption *durationOption;
    QCommandLineOption *layoutOption;
signals:

public slots:
};

#endif // ARGUMENTPARSER_H
