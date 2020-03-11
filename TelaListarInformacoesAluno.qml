import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

Rectangle{
    width: parent.width
    height: parent.height

    Column{
    width: parent.width
    height: parent.height
    spacing: 30

    Label {
    id: name
    text:"NOME ALUNO: " + modelData.nome
    font.pointSize: 18
    }

    NotoRowLayout{
    title: "Total De bilhetes:"
    texto: modelData.numeroTotalBilhetes
    }

    NotoRowLayout{
    title: "Bilhetes de entrada:"
    texto: modelData.numeroBilhetesEntrada
    }

    NotoRowLayout{
    title: "Bilhetes de Saida:"
    texto: modelData.numeroBilhetesSaida
    }

    NotoRowLayout{
    title: "Bilhetes de Suspensao:"
    texto: "Sem Implementacao"
    }

    NotoRowLayout{
    title: "Turma Do Aluno:"
    texto: modelData.turmaDoAluno
    }

    NotoRowLayout{
    title: "Turno Do Aluno:"
    texto: modelData.turnoDoAluno
    }

    NotoRowLayout{
    title: "Numero De Bilhetes Emitidos:"
    texto: "Sem Implementacao"
    }

    NotoRowLayout{
    title: "Ultimo Bilhete Emitido em:"
    texto: modelData.dataUltimoBilhete
    }
  }
}
