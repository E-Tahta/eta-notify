#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class Bridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message)
    Q_PROPERTY(QString duration READ duration)
    Q_PROPERTY(QString layout READ layout)
public:
    explicit Bridge(QObject *parent = 0);

    static QString s_message;
    static QString s_duration;
    static QString s_layout;

    QString message() const;
    QString duration() const;
    QString layout() const;

signals:

public slots:
};

#endif // BRIDGE_H
