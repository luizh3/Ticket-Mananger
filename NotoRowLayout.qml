import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

RowLayout{
Layout.fillWidth: true

property string title
property string texto

Label {
id: name1
text:title
font.pointSize: 16
font.italic: true
}

Label {
id: name2
text:texto
font.pointSize: 16
font.italic: true
color: "#87cefa"
}

}
