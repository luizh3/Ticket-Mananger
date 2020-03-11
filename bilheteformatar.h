#ifndef BILHETEFORMATAR_H
#define BILHETEFORMATAR_H

#include <QObject>
#include "iostream"
#include <string.h>
using namespace std;

class BilheteFormatar : public QObject {
    Q_OBJECT
public:

    BilheteFormatar();
    QString toUpper( QString& retornarUpper );
    QStringList formatarBilheteInformacoes( QString nome, QString descricao, QString assinatura, QString turma, QString turno );
    QStringList formatarBilhete( QList<QString>& formatar );
    QString formatarTamnhoBilhete( QStringList text );
    QString intToString( int num );
    static QString pegarHora();
    static QString adicionarQuebraLinha( QStringList parametro );


};

#endif // BILHETEFORMATAR_H
