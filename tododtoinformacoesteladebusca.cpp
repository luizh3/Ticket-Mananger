#include "tododtoinformacoesteladebusca.h"

TodoDtoInformacoesTelaDebusca::TodoDtoInformacoesTelaDebusca( QObject* parent ) :
    QObject( parent ) {}

QString TodoDtoInformacoesTelaDebusca::nome() const {
    return _nome;
}

void TodoDtoInformacoesTelaDebusca::setNome( const QString& nome ) {
    _nome = nome;
}

QString TodoDtoInformacoesTelaDebusca::numeroTotalBilhetes() const {
    return _numeroTotalBilhetes;
}

void TodoDtoInformacoesTelaDebusca::setNumeroTotalBilhetes( const QString& numeroTotalBilhetes ) {
    _numeroTotalBilhetes = numeroTotalBilhetes;
}

QString TodoDtoInformacoesTelaDebusca::numeroBilhetesEntrada() const {
    return _numeroBilhetesEntrada;
}

void TodoDtoInformacoesTelaDebusca::setNumeroBilhetesEntrada( const QString& numeroBilhetesEntrada ) {
    _numeroBilhetesEntrada = numeroBilhetesEntrada;
}

QString TodoDtoInformacoesTelaDebusca::numeroBilhetesSaida() const {
    return _numeroBilhetesSaida;
}

void TodoDtoInformacoesTelaDebusca::setNumeroBilhetesSaida( const QString& numeroBilhetesSaida ) {
    _numeroBilhetesSaida = numeroBilhetesSaida;
}

QString TodoDtoInformacoesTelaDebusca::dataUltimoBilhete() const {
    return _dataUltimoBilhete;
}

void TodoDtoInformacoesTelaDebusca::setDataUltimoBilhete( const QString& dataUltimoBilhete ) {
    _dataUltimoBilhete = dataUltimoBilhete;
}

QString TodoDtoInformacoesTelaDebusca::bilhetesSuspenssao() const {
    return _bilhetesSuspenssao;
}

void TodoDtoInformacoesTelaDebusca::setBilhetesSuspenssao( const QString& bilhetesSuspenssao ) {
    _bilhetesSuspenssao = bilhetesSuspenssao;
}

QString TodoDtoInformacoesTelaDebusca::turnoDoAluno() const {
    return _turnoDoAluno;
}

void TodoDtoInformacoesTelaDebusca::setTurnoDoAluno( const QString& turnoDoAluno ) {
    _turnoDoAluno = turnoDoAluno;
}

QString TodoDtoInformacoesTelaDebusca::turmaDoAluno() const {
    return _turmaDoAluno;
}

void TodoDtoInformacoesTelaDebusca::setTurmaDoAluno( const QString& turmaDoAluno ) {
    _turmaDoAluno = turmaDoAluno;
}
