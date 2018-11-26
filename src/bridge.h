#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class ArgumentParser;

class Bridge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString message READ message NOTIFY messageChanged)
    Q_PROPERTY(QString duration READ duration NOTIFY durationChanged)
    Q_PROPERTY(QString layout READ layout NOTIFY layoutChanged)
public:
    explicit Bridge(QObject *parent = 0);

    QString message() const;
    QString duration() const;
    QString layout() const;

private:
    ArgumentParser *ap;

    QString m_message;
    QString m_duration;
    QString m_layout;

    void fillValues();

signals:
    void messageChanged();
    void durationChanged();
    void layoutChanged();

public slots:
};

#endif // BRIDGE_H
