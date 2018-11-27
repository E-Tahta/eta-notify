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

    property int maxWidth: 300

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
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.WordWrap
            anchors.centerIn: parent
        }
    }

    Component.onCompleted: {
        message.text = bridge.message

        if (bridge.layout == "big") {
            main.width = Screen.width
            main.height = Screen.height
            message.width = main.width -100
            message.font.pointSize = 30
            if (message.paintedWidth < 1700) {
                message.horizontalAlignment = Text.AlignHCenter
            } else {
                message.horizontalAlignment = Text.AlignJustify
            }
        } else if (bridge.layout == "small") {
            message.font.pointSize = 12
            message.horizontalAlignment = Text.AlignHCenter
            message.width =  main.maxWidth - 24
            if (main.maxWidth > message.paintedWidth) {
                main.width = message.paintedWidth + 24
            } else {
                main.width = main.maxWidth;
            }
            main.height = message.paintedHeight + 24
            main.x= 1700 - (main.width / 2)
            main.y=220
        }
        timer.interval = parseInt(bridge.duration) * 1000
        timer.start()
    }
}
