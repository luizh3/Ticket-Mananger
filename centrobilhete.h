#ifndef CENTROBILHETE_H
#define CENTROBILHETE_H
#include <QObject>
#include "tododto.h"

using namespace  std;

class CentroBilhete : public QObject {
    Q_OBJECT
public:

    explicit CentroBilhete( QObject* parent = nullptr );
    QString getRetorno() const;
    void setRetorno( const QString& value );

public slots:
    QString centroBilheteFormatar( const QString& description, const QString& nome,
                                   const QString& assinatura, const QString& data, const QString& turma, const QString& turno );
private:
    QString retorno;
};

#endif // CENTROBILHETE_H
