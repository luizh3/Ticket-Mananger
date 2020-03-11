import br.com.bilhete.com 1.0
import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.12


ApplicationWindow{
    id:mainWindow
    width: 1600
    height: 900
    visible: true
    visibility: mainWindow.validarFullScreen();
    title: "Bilhete"

    property bool validarFullScreenWindow

    function validarFullScreen(){
        if( !validarFullScreenWindow ){
        return "Windowed"
        }else{
        return "FullScreen"
      }
    }

    function abrirTelaAtalhoCadastro(){
        retanguloPrincipal.visible = false
        toolBar.visible = false
        menuInicial.visible = false
        stack.push(primeiroELemento)
    }

    function abrirTelaConfig(){
        retanguloPrincipal.visible = false
        telaConfigGeral.visible = true
    }

    header: ToolBar{
        id:toolBar
        visible: false
        background: Rectangle{
        border.color: "#d3d3d3"
        }

        RowLayout{
         anchors.fill: parent
         ToolButton{
            text: "Tipo Bilhete"
            onClicked: {
                menu.open();
            }
         }
         Label{
            id:titulo
            elide: Label.ElideRight
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter
            Layout.fillWidth:true
         }

         ToolButton{
         text: ">"

         onClicked: {
         stack.pop()
         }
        }
      }
    }

    StackView{
    id:stack
    anchors.fill: parent
    }

    Menu{
    id:menu

    MenuItem{
        text: "Bilhete de entrada e saida"
        onClicked: {
            titulo.text = "BILHETE DE ENTRADA E SAIDA"
            stack.push(primeiroELemento)
        }
    }

    MenuItem{
        text: "Bilhete de expulsao"
        onClicked: {
            stack.push(segundoElemento)
            titulo.text = "BILHETE DE EXPULSAO"
        }
    }
    MenuItem{
        text: "Bilhete de reuniao"
        onClicked: {
            stack.push(terceroElemento)
            titulo.text = "BILHETE DE REUNIAO"
       }
    }
 }

    Component{
        id:primeiroELemento

        Rectangle{
        id:retangulo
        anchors.fill: parent

        Cadastro{
          id:cadastro
          width: parent.width
          height: parent.height

          onVoltarTela : function(){
              toolBar.visible = false
              retanguloPrincipal.visible = true
              cadastro.visible = false;
              menuInicial.visible = true;
          }
        }
      }
    }

    Component{
        id:segundoElemento
        Rectangle{
        anchors.fill: parent
        BilheteDeReuniao{
        }

        }

    }

    Component{
        id:terceroElemento
        Rectangle{
        anchors.fill: parent
        color: "orange"
        }
    }


    TelaConfigGeral{
    id:telaConfigGeral
    visible: false
    width: parent.width
    height: parent.height


    Shortcut {
        sequence: "Ctrl+E"
        context: Qt.ApplicationShortcut
        onActivated: mainWindow.abrirTelaAtalhoCadastro()
    }

    Shortcut {
        sequence: "Ctrl+Q"
        context: Qt.ApplicationShortcut
        onActivated: mainWindow.abrirTelaConfig()
    }


    onMudarResulucaoTela:function( bool ){
    validarFullScreenWindow = bool
    mainWindow.visibility = mainWindow.validarFullScreen()
    }

    onVoltarPagina:function(){
      retanguloPrincipal.visible = true
      telaConfigGeral.visible = false
    }
  }

    TelaDeBusca{
    id:telaDebusca
    visible: false
    anchors.fill: parent
    width: parent.width

    onVoltarPagina:function(){
       retanguloPrincipal.visible = true
       telaDebusca.visible = false
       cadastro.visible = false
    }
  }

    ControlV9{
    id:control
  }


    Rectangle{
    id:retanguloPrincipal
    anchors.fill: parent
//  width: parent.width
//  height: parent.height
    anchors.margins: 15
    visible: true
    color: "#fff"
    // color: "#f7f7f7"

    Button{
        id:buttonConfig
        width:45
        height: 45
        background: Rectangle{
        border.color: buttonConfigMouse.pressed ? "#87cefa" : "#d3d3d3"
        radius: 5
        visible: true
    }

        Image {
            id:img
            anchors.centerIn: parent
            width: 30
            height: 30
            source: "img/img.png"

            RotationAnimator on rotation {
                running: buttonConfigMouse.containsMouse && !buttonConfigMouse.pressed
                from: 0;
                to: 360;
                loops: Animation.Infinite
                duration: 2000
            }

            MouseArea{
            id:mouseAreaImage
            hoverEnabled: true
            anchors.fill: parent
            }
        }

    MouseArea{
        id:buttonConfigMouse
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
        retanguloPrincipal.visible = false
        telaConfigGeral.visible = true
        }
     }
  }

    RectangularGlow {
        id: effect
        anchors.fill: menuInicial
        glowRadius: 10
        cornerRadius: 10
        spread: 0.1
        color: "#d3d3d3"
    }

        MenuInicial{
        width: parent.width / 3
        height: parent.height / 2
        visible: true
        id:menuInicial

        onEmitSignalFundo: function(){
            retanguloPrincipal.visible = false
            toolBar.visible = true
            menuInicial.visible = false
            stack.push(primeiroELemento)
        }

        onBuscarPorNome:function(){
            retanguloPrincipal.visible = false
            telaDebusca.visible = true

        }
      }

    }
 }
