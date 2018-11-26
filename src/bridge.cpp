#include "bridge.h"
#include "argumentparser.h"

Bridge::Bridge(QObject *parent) : QObject(parent),
    m_message("Empty Message"),
    m_duration("5"),
    m_layout("big")
{
    ap = new ArgumentParser(this);
    fillValues();
}

QString Bridge::message() const
{
    return m_message;
}

QString Bridge::duration() const
{
    return m_duration;
}

QString Bridge::layout() const
{
    return m_layout;
}

void Bridge::fillValues()
{
    if (m_message != ap->message()) {
        m_message = ap->message();
        emit messageChanged();
    }
    if (m_duration != ap->duration()) {
        m_duration = ap->duration();
        emit durationChanged();
    }
    if (m_layout != ap->layout()) {
        m_layout = ap->layout();
        emit layoutChanged();
    }
}
