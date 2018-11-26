#include "bridge.h"
#include "singleinstance.h"

#include <signal.h>
#include <unistd.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDir>
#include <QCursor>
#include <QDebug>


#define SINGLE_INSTANCE ".eta-notify"
static int setup_unix_signal_handlers();

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOverrideCursor(QCursor(Qt::BlankCursor));
    QGuiApplication::setApplicationName("eta-notify");
    QGuiApplication::setApplicationVersion("1.0");

    QString pidName = SINGLE_INSTANCE;
    QString username = qgetenv("USER");
    if (username.isEmpty())
        username = qgetenv("USERNAME");
    QString tmpPath= "/tmp/";
    QString pidPath = tmpPath.append(username);

    QDir dir(pidPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString name = pidPath.append("/").append(pidName);

    SingleInstance cInstance;

    if(cInstance.hasPrevious(name, QCoreApplication::arguments()))
    {
        return 0;
        qDebug("eta-notify is allready running");
    }

    if (cInstance.listen(name)) {
        qDebug() << "Creating single instance";
        setup_unix_signal_handlers();
    } else {
        qFatal("Couldn't create single instance aborting");
    }

    qmlRegisterType<Bridge>("eta.bridge",1,0,"Bridge");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));

    return app.exec();
}

static void handle_signal(int sig)
{
    QString pidName = SINGLE_INSTANCE;
    QString username = qgetenv("USER");
    if (username.isEmpty())
        username = qgetenv("USERNAME");
    QString tmpPath= "/tmp/";
    QString pidPath = tmpPath.append(username);
    QString name = pidPath.append("/").append(pidName);
    QByteArray ba = name.toLatin1();
    Q_UNUSED(sig);
    unlink(ba.data());
    exit(0);
}

static int setup_unix_signal_handlers()
{
    struct sigaction sig;
    sig.sa_handler = handle_signal;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sig.sa_flags |= SA_RESTART;
    if (sigaction(SIGINT, &sig, 0)) {
        return 1;
    }
    if (sigaction(SIGTERM, &sig, 0)) {
        return 2;
    }
    return 0;
}
