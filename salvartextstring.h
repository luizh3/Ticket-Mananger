#ifndef SALVARTEXTSTRING_H
#define SALVARTEXTSTRING_H
#include "iostream"

using namespace std;

#include <QObject>

class SalvarTextString : public QObject {
    Q_OBJECT
public:

    explicit SalvarTextString( QObject* parent = nullptr );
    void salvarArquivoText( string text );
    void salvarTextoQFile( QString texto );

signals:

public slots:
};

#endif // SALVARTEXTSTRING_H
