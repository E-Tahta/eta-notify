#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class ArgumentParser;

class Bridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message)
    Q_PROPERTY(QString duration READ duration)
    Q_PROPERTY(QString layout READ layout)
public:
    explicit Bridge(QObject *parent = 0);

    QString message() const;
    QString duration() const;
    QString layout() const;

private:
    ArgumentParser *ap;

signals:

public slots:
};

#endif // BRIDGE_H
