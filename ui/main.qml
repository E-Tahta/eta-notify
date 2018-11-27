import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.0
import eta.bridge 1.0

ApplicationWindow {
    id: main
    flags: Qt.X11BypassWindowManagerHint
    color: "transparent"
    visible: true
    width: 500
    height: 300

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

    Rectangle {
        id: container
        anchors.fill: parent
        color: "#383838"
        radius: bridge.layout == "small" ? 5 : 0
        Text {
            id: message
            color: "#eeeeee"
            font.bold: true
            width: main.width - 20
            height: main.height -20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 18
            wrapMode: Text.WordWrap
            anchors.centerIn: parent
        }
    }

    Component.onCompleted: {
        message.text = bridge.message

        if (bridge.layout == "big") {
            main.width = Screen.width
            main.height = Screen.height
            message.font.pointSize = 30
        } else if (bridge.layout == "small") {
            main.width = 300
            main.height = 180
            main.x= 1560
            main.y=220
            message.font.pointSize = 12
        }

        timer.interval = parseInt(bridge.duration) * 1000
        timer.start()
    }
}
