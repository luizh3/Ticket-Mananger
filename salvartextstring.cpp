#include "salvartextstring.h"
#include "iostream"
#include "fstream"
#include "list"
#include <QFile>
#include <QTextStream>
#include <QFileDevice>
#include <QTemporaryFile>
#include <gerararquivopdf.h>
#include <QDebug>
#include <QtSql>

using namespace std;

SalvarTextString::SalvarTextString( QObject* parent ) :
    QObject( parent ) {};

void SalvarTextString::salvarArquivoText( string text ) {
    ofstream outFile;
    outFile.open( "/home/luizhenrique/Music/qt.txt" );
    if ( !outFile ) {
        cout << "Erro em Criar test.txt" << endl;
        abort();
    }

    outFile << text;
    outFile.close();
}

void SalvarTextString::salvarTextoQFile( QString texto ) {

    QString local = qApp->applicationDirPath();
    QFile file( local + "/TxtArquivo/bilhetes.txt" );
    static QString printar;
    printar.append( texto );
    printar.append( "\n" );
    printar.append( QString( "" ).leftJustified( 45, '_' ) );
    printar.append( "\n" );

    if ( file.open( QIODevice::WriteOnly ) ) {
        file.write( printar.toUtf8() );
        file.close();
        qDebug() << "Arquivo TxtCriado Com Sucesso SalvarTextString::salvarTextoQFile";
    }else {
        qCritical() << "Arquivo Txt Nao Gerado SalvarTextString::salvarTextoQFile ";
    }
}
