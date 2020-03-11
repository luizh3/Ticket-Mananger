import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle {
    id: root
    visible: true
    width: parent.width
    height: (text.height + ( container.anchors.margins * 3 ) )
    border.color: "#d3d3d3"
    radius: 10

    property string nome: ''
    property string assinaturaPedagogo: ''
    property string tipoBilhete: ''
    property string turma: ''
    property string turno: ''
    property string motivoEmissao: ''
    property string descricaoBilhete: ''
    property string horaEmissao: ''
    property string dataEmissao: ''

    Rectangle {
        id: container
        anchors.fill: parent
        anchors.margins: 12

        Text {
            id: text
            anchors.top: parent.top
            anchors.left: parent.left
            font.pointSize: 12
        }

            RowLayout{
            id:text1
            Layout.fillWidth: true
            anchors.top: text.bottom

            Label {
            text:"Tipo do Bilhete:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.tipoBilhete
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
            }
          }

            RowLayout{
            id:text2
            Layout.fillWidth: true
            anchors.top: text1.bottom

            Label {
            text:"Turma do Aluno:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.turma
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
            }
          }

            RowLayout{
            id:text3
            Layout.fillWidth: true
            anchors.top: text2.bottom

            Label {
            text:"Nome do Aluno:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.nome
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }

            RowLayout{
            id:text4
            Layout.fillWidth: true
            anchors.top: text3.bottom

            Label {
            text:"Turno Frequentado:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.turno
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }

            RowLayout{
            id:text5
            Layout.fillWidth: true
            anchors.top: text4.bottom

            Label {
            text:"Motivo Emissao:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.motivoEmissao
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }
            RowLayout{
            id:text6
            Layout.fillWidth: true
            anchors.top: text5.bottom

            Label {
            text:"Descricao:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.descricaoBilhete
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }
            RowLayout{
            id:text7
            Layout.fillWidth: true
            anchors.top: text6.bottom

            Label {
            text:"Assinatura Pedagogo:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.assinaturaPedagogo
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }
            RowLayout{
            id:text8
            Layout.fillWidth: true
            anchors.top: text7.bottom

            Label {
            text:"Hora Emissao:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.horaEmissao
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }
            RowLayout{
            id:text9
            Layout.fillWidth: true
            anchors.top: text8.bottom

            Label {
            text:"Data Emissao:"
            font.pointSize: 14
            font.italic: true
            }

            Label {
            text:root.dataEmissao
            font.pointSize: 14
            font.italic: true
            color: "#87cefa"
           }
       }
   }
}
