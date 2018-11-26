#include "bridge.h"

QString Bridge::s_message = "No message";
QString Bridge::s_duration = "3";
QString Bridge::s_layout = "small";

Bridge::Bridge(QObject *parent) : QObject(parent)
{

}

QString Bridge::message() const
{
    return s_message;
}

QString Bridge::duration() const
{
    return s_duration;
}

QString Bridge::layout() const
{
    return s_layout;
}
