import QtQuick 2.3
import QtQuick.Controls 1.2
import eta.bridge 1.0

ApplicationWindow {
    id: main
    flags: Qt.FramelessWindowHint
    visible: true
    width: 640
    height: 480

    Bridge {
        id: bridge
    }

    Text {
        anchors.centerIn: parent
        text: bridge.message;
    }
}
