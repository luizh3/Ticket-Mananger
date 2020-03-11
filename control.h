#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include "tododto.h"
#include "tododtoinformacoesteladebusca.h"

class Control : public QObject {
    Q_OBJECT
public:
    explicit Control( QObject* parent = nullptr );
    void chamarSignal();

    QString nome() const;
    void setNome(const QString &nome);

signals:
    void nomeChanged( const QString &nome );
    void nadaChanged();
public slots:
        void slotTeste( QString calros );
        void apenasImprime();
private slots:
         void imprimirNumeros( int var );
private:
 QString _nome;
 Tododto *todoDto;

};

#endif // CONTROL_H
