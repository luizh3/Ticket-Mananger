#include "bilheteentradaousaida.h"
#include "tododto.h"
#include "bilheteformatar.h"
#include "salvartxt.h"
#include "salvartextstring.h"
#include "cabecalhobilhete.h"
#include "centrobilhete.h"
#include "gerararquivopdf.h"
#include "configbancogeral.h"
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonObject>
#include <QJsonDocument>

#define ENDPOINT_POST "http://localhost:3333/devs"

BilheteEntradaOuSaida::BilheteEntradaOuSaida( QObject* parent ) :
    QObject( parent ) {
    mManager = new QNetworkAccessManager( this );
}

void BilheteEntradaOuSaida::centroBilhete( const QString& description, const QString& nome, const QString& assinatura, const QString& data, const QString& turma, const QString& turno ) {

    setNomePdf( nome );
    setTurma( turma );
    setTurno( turno );
    setDescriprion( description );
    setNome( nome );
    setAssinatura( assinatura );
    setData( data );
    setHora( BilheteFormatar::pegarHora() );
    this->_centro = CentroBilhete().centroBilheteFormatar( description, nome, assinatura, data, turma, turno );
}

void BilheteEntradaOuSaida::cabesalhoBilhete( const QString& tipoBilhete, const QString& motivo ) {

    setMotivo( motivo );
    setTipoBilhete( tipoBilhete );
    setMotivo( motivo );

    QString formata = CabecalhoBilhete().cabesalhoBilhete( tipoBilhete, ConfigBancoGeral::selectNomeEscola(), motivo );
    this->_cabesalho = formata;
    footer();
}

void BilheteEntradaOuSaida::insertSalvarBancoDadosAluno() {
    Tododto* dto = new Tododto();
    QString nomeEscola = ConfigBancoGeral::selectNomeEscola();

    dto->setData( getData() );
    dto->setHora( getHora() );
    dto->setNome( getNome() );
    dto->setAssinatura( getAssinatura() );
    dto->setDescription( getDescriprion() );
    dto->setEmitidoPor( nomeEscola );
    dto->setTurma( getTurma() );
    dto->setTurno( getTurno() );
    dto->setMotivo( getMotivo() );
    dto->setTipoBilhete( getTipoBilhete() );

    ConfigBancoGeral::dataBaseOpenConexion();
    ConfigBancoGeral* bancoGeral = new ConfigBancoGeral();
    bancoGeral->insertBilhete( dto );
    QTimer::singleShot( 3000, this, &BilheteEntradaOuSaida::pararAnimation );
    BilheteEntradaOuSaida bilhete;
    QObject::connect( &bilhete, &BilheteEntradaOuSaida::selectAnimationFailOrSucessChanged, this, &BilheteEntradaOuSaida::setSelectAnimationFailOrSucessPrintar );
    bilhete.selectAnimationFailOrSucessChanged( bancoGeral->getFailOrSucess() );
    post( getNome(), getData(), getHora(), getTipoBilhete() , getMotivo() );
}

bool BilheteEntradaOuSaida::hasDtos() {
    if( !_dtos.isEmpty() ) {
        return true;
    }
    return false;
}

void BilheteEntradaOuSaida::pararAnimation() {
    setAnimationRunnigPrintar( false );
    emit animationRunnigChanged();
}

void BilheteEntradaOuSaida::footer() {
    QString formata;
    QStringList formataRetorno;
    formataRetorno.append( "AVISO ESSE BILHETE DEVE SER REGISTRADO" );
    formataRetorno.append( "NAO SEGUIR AVISO RESULTARA EM MULTA" );
    formataRetorno = BilheteFormatar().formatarBilhete( formataRetorno );
    formata = BilheteFormatar().formatarTamnhoBilhete( formataRetorno );
    this->_footer = formata;
}

void BilheteEntradaOuSaida::salvarArquivoFormatado() {
    if( !getNome().isEmpty() && !getMotivo().isEmpty() && !getAssinatura().isEmpty() ) {
        insertSalvarBancoDadosAluno();
        QStringList bilheteCompleto;
        bilheteCompleto.append( _centro );
        bilheteCompleto.prepend( _cabesalho );
        bilheteCompleto.append( _footer );
        bilheteCompleto.append( QString( "Hora Da Emissão : " + BilheteFormatar().pegarHora().leftJustified( 45, ' ' ) ) );
        QString retorno = bilheteCompleto.join( "" );
        setArquivoPrintar( retorno );
        emit arquivoPrintarChanged();
        if( _opcaoGerarPdf == 1 ) {
            GerarArquivoPdf().gerarArquivoPdf( retorno, _nomePdf );
        }
        SalvarTextString().salvarTextoQFile( retorno );
    }
}

QString BilheteEntradaOuSaida::arquivoPrintar() const {
    return _arquivoPrintar;
}

void BilheteEntradaOuSaida::emitMudarTelaFundo() {
    emit mudarDeTela();
}

void BilheteEntradaOuSaida::buscarPorNomeDto( QString nome, QString turma ) {
    _dtos.clear();
    ConfigBancoGeral::dataBaseOpenConexion();
    QStringList retorno;
    qDebug() << ConfigBancoGeral::selectUltimoIdBanco();
    ConfigBancoGeral configBancoGeral;
    QList<Tododto*> list = {};
    list.append( configBancoGeral.selectPeloNomeETurma( nome, turma ) );
    telaDireita( list );

    if( !nome.isEmpty() ) {
        for ( Tododto* dto : list ) {
            listarNovoDto( dto );
        }
    }
}

void BilheteEntradaOuSaida::telaDireita( QList<Tododto*> list ) {

    TodoDtoInformacoesTelaDebusca* todoTelaBusca = new TodoDtoInformacoesTelaDebusca();
    int contEntrada = 0, contSaida = 0, totalBilhetes = 0;
    _dtosTelaBusca.clear();

    for ( Tododto* dto : list ) {
        if( dto->getTipoBilhete() == "ENTRADA" ) {
            contEntrada++;
        }else if ( dto->getTipoBilhete() == "SAIDA" ) {
            contSaida++;
        }
        todoTelaBusca->setNome( dto->getNome() );
        todoTelaBusca->setDataUltimoBilhete( dto->getData() );
        todoTelaBusca->setTurmaDoAluno( dto->getTurma() );
        todoTelaBusca->setTurnoDoAluno( dto->getTurno() );
        // Implementar metodo e atributo  // todoTelaBusca->setBilhetesSuspenssao();
    }

    totalBilhetes = contEntrada + contSaida;
    todoTelaBusca->setNumeroTotalBilhetes( QString::number( totalBilhetes ) );
    todoTelaBusca->setNumeroBilhetesSaida( QString::number( contSaida ) );
    todoTelaBusca->setNumeroBilhetesEntrada( QString::number( contEntrada ) );
    _dtosTelaBusca.append( todoTelaBusca );
    emit dtosTelaBuscaChanged();

}

void BilheteEntradaOuSaida::listarNovoDto( Tododto* dto ) {
    _dtos.append( dto );
    hasDtos();
}

QList<QObject*> BilheteEntradaOuSaida::dtosToObject() const {
    QList<QObject*> dtos = {};

    if( !_dtos.isEmpty() ) {
        for( int i = _dtos.count() - 1; i >=0; i-- ) {
            dtos.append( _dtos.at( i ) );
        }
        return dtos;
    }else {
        for( int i = _dtosTelaBusca.count() - 1; i >=0; i-- ) {
            dtos.append( _dtosTelaBusca.at( i ) );
        }
        return dtos;
    }
}

void BilheteEntradaOuSaida::post( const QString& nome, const QString& data, const QString& hora, const QString& tipoBilhete , const QString& motivo ) {

    QJsonObject response;
    response[NOME] = nome;
    response[DATA] = data;
    response[HORA] = hora;
    response[TIPO_BILHETE] = tipoBilhete;
    response[MOTIVO] = motivo;

    QJsonDocument doc( response );

    QNetworkRequest request = QNetworkRequest( QUrl( ENDPOINT_POST ) );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json" );

    mManager->post( request, doc.toJson() );
}

double BilheteEntradaOuSaida::selectAnimationFailOrSucessPrintar() {
    return _selectAnimationFailOrSucess;
}

void BilheteEntradaOuSaida::setSelectAnimationFailOrSucessPrintar( bool var ) {
    _selectAnimationFailOrSucess = var;
    selectAnimationFailOrSucessChanged( var );
}

double BilheteEntradaOuSaida::animationRunnigPrintar() {
    return _runnigAnimation;
}

void BilheteEntradaOuSaida::setAnimationRunnigPrintar( bool var ) {
    _runnigAnimation = var;
}

QString BilheteEntradaOuSaida::getTipoBilhete() const { return _tipoBilhete; }
void BilheteEntradaOuSaida::setTipoBilhete( const QString& tipoBilhete ) { _tipoBilhete = tipoBilhete; }

int BilheteEntradaOuSaida::getOpcaoGerarPdf() const { return _opcaoGerarPdf; }
void BilheteEntradaOuSaida::setOpcaoGerarPdf( int opcaoGerarPdf ) { _opcaoGerarPdf  = opcaoGerarPdf; }

QString BilheteEntradaOuSaida::getEmitidoPor() const { return _emitidoPor; }
void BilheteEntradaOuSaida::setEmitidoPor( const QString& emitidoPor ) { _emitidoPor = emitidoPor; }

QString BilheteEntradaOuSaida::getHora() const { return _hora; }
void BilheteEntradaOuSaida::setHora( const QString& hora ) { _hora = hora; }

QString BilheteEntradaOuSaida::getData() const { return _data; }
void BilheteEntradaOuSaida::setData( const QString& data ) { _data = data; }

QString BilheteEntradaOuSaida:: getNome() const { return _nome; }
void BilheteEntradaOuSaida::setNome( const QString& nome ) { _nome = nome; }

QString BilheteEntradaOuSaida::getAssinatura() const { return _assinatura; }
void BilheteEntradaOuSaida::setAssinatura( const QString& assinatura ) { _assinatura = assinatura; }

QString BilheteEntradaOuSaida::getMotivo() const { return _motivo; }
void BilheteEntradaOuSaida::setMotivo( const QString& motivo ) { _motivo = motivo; }

QString BilheteEntradaOuSaida::getDescriprion() const { return _descriprion; }
void BilheteEntradaOuSaida::setDescriprion( const QString& descriprion ) { _descriprion = descriprion; }

QString BilheteEntradaOuSaida::getNomePdf() const { return _nomePdf; }
void BilheteEntradaOuSaida::setNomePdf( const QString& value ) { _nomePdf = value; }

void BilheteEntradaOuSaida::setArquivoPrintar( const QString& arquivoPrintar ) { _arquivoPrintar = arquivoPrintar; }

QString BilheteEntradaOuSaida::getTurno() const { return _turno; }
void BilheteEntradaOuSaida::setTurno( const QString& turno ) { _turno = turno; }

QString BilheteEntradaOuSaida::getTurma() const { return _turma; }
void BilheteEntradaOuSaida::setTurma( const QString& turma ) { _turma = turma; }

QList<TodoDtoInformacoesTelaDebusca*> BilheteEntradaOuSaida::getDtosTelaBusca() const { return _dtosTelaBusca; }
void BilheteEntradaOuSaida::setDtosTelaBusca( const QList<TodoDtoInformacoesTelaDebusca*>& dtosTelaBusca ) { _dtosTelaBusca = dtosTelaBusca; }




