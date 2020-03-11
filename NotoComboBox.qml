import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0

 Rectangle{
    id:mainRetangulo
    visible: true
    width: widthComBox
    height: heigthComBox

    property var modelTxt
    property var widthComBox
    property var heigthComBox
    property var textEditComboBox
    property var tamanhoQuadradoDropBox : 0

    signal emitirText( var text );

    ComboBox
    {
        id: box
        currentIndex: -1
        activeFocusOnPress: true
        style: ComboBoxStyle {
        id: comboBox
        background: Rectangle {
            id: rectCategory
            color: enabled ? "#fff" : "black"
            border.width: box.focus ? 2 : 0.5
            border.color: box.focus ? "#11cdef"  : "#d3d3d3"
            opacity:  enabled ? 1 : 0.2
            radius: 3
        }
        label: Text {
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 18
            font.family: "Courier"
            font.capitalization: Font.SmallCaps
            color: "black"
            opacity: 0.7
            text: textEditComboBox + box.currentText
        }

        // drop-down customization here
        property Component __dropDownStyle: MenuStyle {
            __maxPopupHeight: 600
            __menuItemType: "comboboxitem"

            frame: Rectangle {              // background
                color: "#fff"
                border.width: 1
                border.color: "gray"
                opacity: 0.5
            }
//            padding.top: 12
//            padding.bottom: 12

            itemDelegate.label:             // an item text
                Text
                {
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pointSize: 15
                    font.family: "Courier"
                    font.capitalization: Font.SmallCaps
                    color: styleData.selected ? "#black" : "gray"
                    text: styleData.text
                }

            itemDelegate.background: Rectangle {  // selection of an item
                color: styleData.selected ? "#addff8" : "transparent"
                opacity: 1.5

            }

            __scrollerStyle: ScrollViewStyle {

            }
        }

        property Component __popupStyle: Style {
            property int __maxPopupHeight: 400
            property int submenuOverlap: 100

            property Component menuItemPanel: Text {
                text: "NOT IMPLEMENTED"
                color: "red"
                font {
                    pixelSize: 14
                    bold: true
                }
            }

            property Component __scrollerStyle: null
            }
        }

        model: modelTxt
        width: widthComBox
        height: heigthComBox
        onCurrentIndexChanged: mainRetangulo.emitirText( box.currentText ) 

        Rectangle{
            id:retanguloRetangulo
            height: parent.height - 2
            width: tamanhoQuadradoDropBox == 0 ? 50 : tamanhoQuadradoDropBox
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            anchors.margins: 1
            opacity: 0.5

            Rectangle{
            width: 2
            height: parent.height
            color: box.focus ? "#11cdef" : "#d3d3d3"

            }

        Image {
            id:img
            width: 25
            height: 20
            opacity: box.focus ? 1 : 0.7
            source: "img/img15.svg"
            anchors.centerIn: parent
            anchors.leftMargin: 5
        }
       }
    }
}
