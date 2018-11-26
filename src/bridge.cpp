#include "bridge.h"
#include "argumentparser.h"

Bridge::Bridge(QObject *parent) : QObject(parent)
{
    ap = new ArgumentParser(this);
}

QString Bridge::message() const
{
    return ap->message();
}

QString Bridge::duration() const
{
    return ap->duration();
}

QString Bridge::layout() const
{
    return ap->layout();
}
