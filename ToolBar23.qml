import QtQuick 2.6
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    footer: TabBar{
    id:tabBar

    TabButton{
        text: "Primeira"
    }
    TabButton{
        text: "Segunda"
    }
    TabButton{
        text: "Terceira"
    }

    }
    StackLayout{

    anchors.fill: parent
    currentIndex: tabBar.currentIndex
    Item {
        id: peimeiraTab
        Rectangle{

        color: "red"
        anchors.fill: parent
        }
    }

    Item {
        id: segundaTab
        Rectangle{
        color: "orange"
        anchors.fill: parent
        }
    }

    Item {
        id: terceiraTab
        Rectangle{
        color: "blue"
        anchors.fill: parent
        }
    }
    }
}
