#include "cabecalhobilhete.h"
#include "bilheteformatar.h"
#define MAXIMOCARCL 44

CabecalhoBilhete::CabecalhoBilhete( QObject* parent ) :
    QObject( parent ) {}

QString CabecalhoBilhete::cabesalhoBilhete( QString tipoBilhete, QString emitopor, QString motivo ) {

    QString formata;
    QStringList formataRetorno;

    formataRetorno.append( "BILHETE DE " + tipoBilhete );
    formataRetorno.append( "BILHETE EMITIDO POR " + BilheteFormatar().toUpper( emitopor ) );
    formataRetorno.append( "PELO MOTIVO " + BilheteFormatar().toUpper( motivo ) );
    formataRetorno = BilheteFormatar().formatarBilhete( formataRetorno );
    formata = BilheteFormatar().formatarTamnhoBilhete( formataRetorno );
    return formata;
}
