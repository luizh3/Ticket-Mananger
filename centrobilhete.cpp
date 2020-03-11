#include "centrobilhete.h"
#include "tododto.h"
#include "bilheteformatar.h"
#include "control.h"

CentroBilhete::CentroBilhete( QObject* parent ) :
    QObject( parent ) {}

QString CentroBilhete::centroBilheteFormatar( const QString& description, const QString& nome,
                                              const QString& assinatura, const QString& data, const QString& turma, const QString& turno ) {

    BilheteFormatar* bilhete = new BilheteFormatar();
    QStringList retorno, cabecalho;
    QString retornoCabecalho, retornoInformacoes;

    retorno.append( bilhete->formatarBilheteInformacoes( nome, description, assinatura, turma, turno ) );
    retorno.append( data );
    QStringList retornoMetodo = bilhete->formatarBilhete( retorno );

    retornoInformacoes = bilhete->formatarTamnhoBilhete( retornoMetodo );

    this->retorno = retornoInformacoes;

    return retornoInformacoes;
}

QString CentroBilhete::getRetorno() const { return retorno; }
void CentroBilhete::setRetorno( const QString& value ) { retorno = value; }



