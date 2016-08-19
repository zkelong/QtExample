import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import "./QChart"
import QtQuick 2.0
import QtMultimedia 5.0

ApplicationWindow {
    title: qsTr("Hello World")
//    width: 800
//    height: 600
    visible: true

    TestQChart {
        id: chart
    }
}
