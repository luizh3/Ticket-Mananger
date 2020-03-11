#include "gerararquivopdf.h"
#include <QPrinter>
#include <QPainter>
#include <QDir>
#include <QDebug>
#include <QPixmap>
#include <QtSql>
GerarArquivoPdf::GerarArquivoPdf( QObject* parent ) :
    QObject( parent ) {}

void GerarArquivoPdf::gerarArquivoPdf( QString pdf, QString nomeArquivo ) {

    QString local = qApp->applicationDirPath() +"/Pdf/"+ nomeArquivo;
    QString retornoString;

    QPrinter printer;
    printer.setOutputFormat( QPrinter::PdfFormat );
    printer.setOutputFileName( local );

    QPainter painter;
    if( !painter.begin( &printer ) ) {
        qCritical() << "Erro Ao Criar Pdf GerarArquivoPdf::gerarArquivoPdf ";
        return;
    }

    QString linhaFormatarString = pdf.toUtf8();
    QString textoTamanho;
    int controlePularLinha = 400;

    QPixmap img1 ( "/home/luizhenrique/Downloads/img12.jpg" );
    QPixmap img2 ( "/home/luizhenrique/Downloads/img3.png" );
    painter.drawPixmap( 0, 0, img1.scaled( 200, 200, Qt::KeepAspectRatio ) );
    painter.drawPixmap( 450, 0, img2.scaled( 350, 350, Qt::KeepAspectRatio ) );
    painter.drawText( 250, 225, "Bilhete Emitido Pela One World School" );
    painter.drawText( 50, 1050, "Assinatura Responsavel:____________________________________________" );

    for ( int num = 0; num < linhaFormatarString.length(); num++ ) {

        QString letra;
        letra = linhaFormatarString[num];
        textoTamanho.append( letra );

        if( textoTamanho.length() == 45 ) {
            controlePularLinha = controlePularLinha + 25;
            if( textoTamanho.trimmed().isEmpty() ) {
                textoTamanho.clear();
                continue;
            }
            if( textoTamanho.at( 0 ) == ' ' ) {
                textoTamanho = textoTamanho.trimmed();
            }
            painter.drawText( 50, controlePularLinha, ( textoTamanho ) );
            textoTamanho.clear();
        }

        if( num + 1 == linhaFormatarString.length() ) {
            controlePularLinha = controlePularLinha + 25;
            painter.drawText( 50, controlePularLinha, textoTamanho );
            textoTamanho.clear();
        }
    }
    painter.end();
}

