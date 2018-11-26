import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import eta.bridge 1.0

ApplicationWindow {
    id: main
    flags: Qt.X11BypassWindowManagerHint
    color: "#383838"
    visible: true
    width: 640
    height: 480

    Bridge {
        id: bridge
    }

    Timer {
        id: timer
        running: false
        repeat: true
        triggeredOnStart: false
        onTriggered: {
            Qt.quit()
        }
    }

    Text {
        id: message
        color: "#FF6C00"
        font.bold: true
        width: main.width - 20
        height: main.height -20
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 12
        anchors.centerIn: parent
    }

    Component.onCompleted: {
        message.text = bridge.message

        if (bridge.layout == "big") {
            main.width = Screen.width
            main.height = Screen.height
            message.font.pointSize = 20
        } else {
            main.x = (Screen.width - main.width) / 2
            main.y = (Screen.height - main.height) / 2
        }

        timer.interval = parseInt(bridge.duration) * 1000
        timer.start()
    }
}
