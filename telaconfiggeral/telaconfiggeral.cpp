#include "telaconfiggeral.h"
#include "configbancogeral.h"
#include "control.h"

TelaConfigGeral::TelaConfigGeral( QObject* parent ) :
    QObject( parent ) {}

void TelaConfigGeral::insertNomeTurma( const QString& nomeTurma ) {
    ConfigBancoGeral::dataBaseOpenConexion();
//    Control *control = new Control();
//    control->chamarSignal();
    ConfigBancoGeral::insertNomeTurma( nomeTurma );
}

void TelaConfigGeral::salvarNomeEscola( QString nomeEscola , QString maximoCaraLinha ) {
    ConfigBancoGeral *conexaoBanco =  new ConfigBancoGeral();
    ConfigBancoGeral::dataBaseOpenConexion();
    conexaoBanco->insertOrUpdateConfigGeral( nomeEscola , maximoCaraLinha );
    setSelectAnimationFailOrSucess(true);
    emit selectAnimationFailOrSucessChanged();
}

QString TelaConfigGeral::retornoNomeEscola() {
    ConfigBancoGeral::dataBaseOpenConexion();
    return ConfigBancoGeral::selectNomeEscola().isEmpty() ? "Nome Escola" : ConfigBancoGeral::selectNomeEscola();
}

int TelaConfigGeral::retornoMaximoCaracterLinha(){
    ConfigBancoGeral::dataBaseOpenConexion();
    return ConfigBancoGeral::selectMaximoCarcterLinha();
}

void TelaConfigGeral::deletarTurma(const QString &nomeTurma){
    ConfigBancoGeral::dataBaseOpenConexion();
    if( !nomeTurma.isEmpty() ){
    ConfigBancoGeral().deleteTurma( nomeTurma );
    }
}

QStringList TelaConfigGeral::comboBoxPrintar() const {
    ConfigBancoGeral::dataBaseOpenConexion();
    QStringList comboBox;
    comboBox.append( ConfigBancoGeral::selectTurmas() );
    comboBox.prepend( " " );
    return comboBox;
}

bool TelaConfigGeral::selectAnimationFailOrSucess() const {
    return _selectAnimationFailOrSucess;
}

void TelaConfigGeral::setSelectAnimationFailOrSucess( bool selectAnimationFailOrSucess ) {
    _selectAnimationFailOrSucess = selectAnimationFailOrSucess;
}
