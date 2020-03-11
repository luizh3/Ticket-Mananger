#include "configbancogeral.h"
#include <QtSql>
#include <QFileInfo>
#include <tododto.h>
#include "bilheteformatar.h"
#define SELECT_NOME_TURMA "SELECT ds_nome_turma FROM turmas_cadastradas WHERE ds_nome_turma /*IS NOT NULL;*/"

ConfigBancoGeral::ConfigBancoGeral( QObject* parent ) :
    QObject( parent ) {}

void ConfigBancoGeral::dataBaseOpenConexion() {

    QSqlDatabase database = QSqlDatabase::addDatabase( "QSQLITE" );
    QString local = qApp->applicationDirPath();
    database.setDatabaseName( local + "/BancoDedados/databasebilhete.db" );

    if( !database.open() ) {
        qCritical() << "Banco Nao Abriu configBancoGeral::dataBaseOpenConexion";
    }
    ;
}

void ConfigBancoGeral::insertBilhete( Tododto* dto ) {
    QSqlQuery query;

    query.prepare( " insert into informacao_bilhete( ds_nome_aluno, ds_nome_escola , tp_bilhete , ds_descricao_bilhete , ds_assinatura_pedagogo , dt_data_emissao , dh_hora_emissao  , ds_motivo , ds_turma , ds_turno_aluno ) values ( '" + dto->getNome() + "' , '" + dto->getEmitidoPor() + "' , '" + dto->getTipoBilhete() + "' , '" + dto->getDescription() + "','" + dto->getAssinatura() + "','" + dto->getData() + "','" + dto->getHora() + "','" + dto->getMotivo() + "','" + dto->getTurma() + "','" + dto->getTurno() + "' ) " );
    if( query.exec() ) {     
        qDebug() << " Arquivo Salvo Com sucesso ";
        setFailOrSucess( true );
    }else {
        qCritical() << "Erro Ao Salvar Dados Do Bilhete configBancoGeral::insertBilhete ";
        setFailOrSucess( false );
    }
}

QList<Tododto*> ConfigBancoGeral::selectPeloNomeETurma( QString nome, QString turma ) {

    QList<Tododto*> retorno = {};
    QSqlQuery query;
    if( !turma.trimmed().isEmpty() && validarTurmaEAlunoExistente( nome, turma ) == true ) {
        query.prepare( "select ds_nome_aluno, ds_nome_escola , tp_bilhete , ds_descricao_bilhete , ds_assinatura_pedagogo , dt_data_emissao , dh_hora_emissao  , ds_motivo , ds_turma , ds_turno_aluno from informacao_bilhete where ds_nome_aluno like '" + nome + "' and ds_turma like '" + turma + "' " );
    }else if( !nome.isEmpty() && turma.trimmed().isEmpty() ) {
        query.prepare( "select ds_nome_aluno, ds_nome_escola , tp_bilhete , ds_descricao_bilhete , ds_assinatura_pedagogo , dt_data_emissao , dh_hora_emissao  , ds_motivo , ds_turma , ds_turno_aluno from informacao_bilhete where ds_nome_aluno like '" + nome + "'" );
    }
    if( query.exec() ) {
        qDebug() << "Select Sucess";
        while( query.next() ) {            // select.append("Nome Escola:" + query.value( ConfigBancoGeral::DS_NOME_ESCOLA ).toString());
            Tododto* dto = new Tododto();
            dto->setTipoBilhete( query.value( ConfigBancoGeral::TP_BILHETE ).toString() );
            dto->setTurma( query.value( ConfigBancoGeral::DS_TURMA ).toString() );
            dto->setNome( query.value( ConfigBancoGeral::DS_NOME_ALUNO ).toString() );
            dto->setTurno( query.value( ConfigBancoGeral::DS_TURNO ).toString() );
            dto->setMotivo( query.value( ConfigBancoGeral::DS_MOTIVO ).toString() );
            dto->setDescription( query.value( ConfigBancoGeral::DS_DESCRICAO_BILHETE ).toString() );
            dto->setAssinatura( query.value( ConfigBancoGeral::DS_ASSINATURA_PEDAGOGO ).toString() );
            dto->setHora( query.value( ConfigBancoGeral::DH_HORA_EMISSAO ).toString() );
            dto->setData( query.value( ConfigBancoGeral::DT_EMISSAO ).toString() );
            retorno.append( dto );
        }
    }else {
        qDebug() << "Erro Select Por Nome configBancoGeral::selectPeloNome";
    }
    //  qDebug()<<select;
    return retorno;
}

int ConfigBancoGeral::selectUltimoIdBanco() {

    QSqlQuery query;
    QString teste;
    int retorno;
    query.prepare( "select id_bilhete from informacao_bilhete where id_bilhete = (SELECT MAX(id_bilhete) FROM informacao_bilhete)" );
    if( query.exec() ) {
        query.value( 1 );
    }

    query.record();
    qDebug() << query.value( query.next() );
    teste = query.value( "id_bilhete" ).toString();
    return retorno = teste.toInt();
}

void ConfigBancoGeral::insertOrUpdateConfigGeral( QString dsNomeEscola , QString numMaximoCaracter) {

    QSqlQuery query;

    if( selectNomeEscola().isEmpty() && !dsNomeEscola.isEmpty() ) {

        query.prepare( "insert into config_geral (ds_nome_escola , maximo_caracter_linha ) values ('" + dsNomeEscola + "' , '"+numMaximoCaracter+"')" );
        if( query.exec() ) {
            setFailOrSucess( true );
            qDebug() << "insert sucess configBancoGeral::insertConfigGeral ";
        }else {
            setFailOrSucess( false );
            qCritical() << "Erro Insert configBancoGeral::insertConfigGeral";
        }

    }else if( !selectNomeEscola().isEmpty() && !dsNomeEscola.isEmpty() ) {
        query.prepare( "update config_geral set ds_nome_escola = '" + dsNomeEscola + "' , maximo_caracter_linha = '"+numMaximoCaracter+"' where id_config_geral='1' " );
        if( query.exec() ) {
            setFailOrSucess( true );
            qCritical() << "sucesso update";
        }else {
            setFailOrSucess( false );
            qDebug() << "erro update";
        }
    }
}



QString ConfigBancoGeral::selectNomeEscola() {

    QSqlQuery query;
    QString retorno;

    query.prepare( "select ds_nome_escola from config_geral where id_config_geral = '1' " );
    query.exec();

    query.value( query.next() ).toString();
    retorno = query.value( ConfigBancoGeral::DS_NOME_ESCOLA ).toString();
    return retorno;
}

bool ConfigBancoGeral::validarTurmaEAlunoExistente( const QString nome, const QString turma ) {
    QSqlQuery query;
    QString retorno;
    query.prepare( "select ds_nome_aluno, ds_turma from informacao_bilhete where ds_nome_aluno like '" + nome + "' and ds_turma like '" + turma + "' " );
    query.exec();
    while( query.next() ) {
        retorno.append( query.value( ConfigBancoGeral::DS_NOME_ALUNO ).toString() );
        retorno.append( query.value( ConfigBancoGeral::DS_TURMA ).toString() );
    }
    return !retorno.isEmpty();
}

void ConfigBancoGeral::insertNomeTurma( const QString& nomeTurma ) {
    QSqlQuery query;

    QStringList retornoTurmas = selectTurmas();
    int turmasIguais = 0;

    for( QString turmas : retornoTurmas ){
        if( turmas == nomeTurma ){
        turmasIguais++;
        }
    }

    if( !nomeTurma.isEmpty() && turmasIguais == 0 ){
    query.prepare( "insert into turmas_cadastradas (ds_nome_turma) values ('" + nomeTurma + "')" );
    if( query.exec() ) {
        qDebug() << "insertSucess ConfigBancoGeral::insertNomeTurma ";
    }else {
        qCritical() << "insertFail ConfigBancoGeral::insertNomeTurma";
    }
  }
}

QStringList ConfigBancoGeral::selectTurmas() {
    QSqlQuery query;
    QString turmaDaVez;
    QStringList retorno;

    query.prepare( SELECT_NOME_TURMA );
    query.exec();
    while ( query.next() ) {
        turmaDaVez.append( query.value( ConfigBancoGeral::DS_TURMA_ALUNO ).toString() );
        retorno.append( turmaDaVez );
        turmaDaVez.clear();
    }
    return retorno;
}

int ConfigBancoGeral::selectMaximoCarcterLinha(){

QSqlQuery query;
int retorno;

query.prepare( "select maximo_caracter_linha from config_geral where id_config_geral = '1' " );
query.exec();

query.value( query.next() ).toInt();
retorno = query.value( "maximo_caracter_linha" ).toInt();
return retorno;

}

void ConfigBancoGeral::deleteTurma( const QString &nomeTurma ){
    QSqlQuery query;
    query.prepare("delete from turmas_cadastradas where ds_nome_turma ='"+nomeTurma+"'");
    query.exec();
}

bool ConfigBancoGeral::getFailOrSucess() const{
    return failOrSucess;
}

void ConfigBancoGeral::setFailOrSucess( bool value ){
    failOrSucess = value;
};


