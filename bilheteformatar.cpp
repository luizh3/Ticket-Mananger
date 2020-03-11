#include "bilheteformatar.h"
#include <QtDebug>
#define MAXIMOCARCL ConfigBancoGeral::selectMaximoCarcterLinha()
#include <QRegularExpression>
#include <QByteArray>
#include "configbancogeral.h"

BilheteFormatar::BilheteFormatar() {}

QString BilheteFormatar::toUpper( QString& retornarUpper ) {
    return retornarUpper.toUpper();
}

QStringList BilheteFormatar::formatarBilheteInformacoes( QString nome, QString descricao,
                                                         QString assinatura, QString turma, QString turno ) {

    nome.prepend( "NOME ALUNO:" );
    descricao.prepend( "COMPLEMENTO:" );
    assinatura.prepend( "ASSINATURA:" );
    turma.prepend( "TURMA DO ALUNO:" );
    turno.prepend( "TURNO:" );

    QStringList retorno;
    retorno.append( nome );
    retorno.append( descricao );
    retorno.append( assinatura );
    retorno.prepend( turma );
    retorno.prepend( turno );
    return retorno;

}

QStringList BilheteFormatar::formatarBilhete( QList<QString>& formatar ) {

    QStringList qStringList;

    QString stringLinhaControle;

    QRegularExpression regExp1 ( "\\s+" );

    QStringList linhas = formatar;

    while( linhas.first().trimmed().isEmpty() ) {
        linhas.removeAt( 0 );
    }

    QListIterator<QString> it( linhas );

    while( it.hasNext() ) {

        QString qStringLinha = it.next();
        QString qStringLinhaFormata = qStringLinha.replace( regExp1, " " );
        qStringLinhaFormata.append( " " );

        if ( qStringLinhaFormata.trimmed().isEmpty() ) {
            qStringLinhaFormata = QString( "" ).fill( ' ', MAXIMOCARCL );
        }

        int numTotalColums = stringLinhaControle.length() + qStringLinhaFormata.length();

        if( qStringLinhaFormata.contains( "PARCELA" ) ) {

            int adicionar = MAXIMOCARCL - numTotalColums;
            qStringList.append( QString( "" ).fill( ' ', adicionar ) );

            qStringList.append( qStringLinhaFormata );

            while ( it.hasNext() ) {
                qStringList.append( it.next() );
            }
            return qStringList;
        }
        if( numTotalColums <= MAXIMOCARCL ) {
            stringLinhaControle.append( qStringLinhaFormata );
        } else {
            if( stringLinhaControle.trimmed().isEmpty() && qStringLinhaFormata.trimmed().isEmpty() ) {
                continue;
            }
            qStringList.append( stringLinhaControle.leftJustified( MAXIMOCARCL, ' ' ) );
            stringLinhaControle = qStringLinhaFormata;
        }
        if( !it.hasNext() ) {
            qStringList.append( stringLinhaControle.leftJustified( MAXIMOCARCL, ' ' ) );
        }
    }
    return qStringList;
};

QString BilheteFormatar::formatarTamnhoBilhete( QStringList text ) {

    QString chegadaText;
    QString retornoString;

    chegadaText = text.join( "" );

    QString linhaFormatarString = chegadaText.toUtf8();

    QString textoTamanho;

    for ( int num = 0; num < linhaFormatarString.length(); num++ ) {

        QString letra;
        letra = linhaFormatarString[num];
        textoTamanho.append( letra );

        if( textoTamanho.length() == MAXIMOCARCL ) {
            if( textoTamanho.trimmed().isEmpty() ) {
                textoTamanho.clear();
                continue;
            }
            retornoString.append( textoTamanho );
            retornoString.append( "\n" );
            textoTamanho.clear();
        }

        if( num + 1 == linhaFormatarString.length() ) {
            retornoString.append( " " );
            retornoString.append( textoTamanho );
            retornoString.append( "\n" );
            textoTamanho.clear();
        }

    }
    return retornoString;
}

QString BilheteFormatar::pegarHora( ) {

    time_t timer;
    struct tm* horarioLocal;

    time( &timer ); // Obtem informações de data e hora
    horarioLocal = localtime( &timer ); // Converte a hora atual para a hora local

    int hora = horarioLocal->tm_hour;
    int min  = horarioLocal->tm_min;
    int sec  = horarioLocal->tm_sec;

    QString horaAtual;

    QString str;

    str.setNum( hora );
    hora < 10 ? horaAtual.append( "0" + str ) : horaAtual.append( str );
    horaAtual.append( ":" );

    str.setNum( min );
    min < 10 ? horaAtual.append( "0" + str ) : horaAtual.append( str );
    horaAtual.append( ":" );

    str.setNum( sec );
    horaAtual.append( str );

    return horaAtual /*.prepend("Hora Da Emissão : ")*/;
}

QString BilheteFormatar::intToString( int num ) {
    QString str;
    str.setNum( num );
    return str;
}

QString BilheteFormatar::adicionarQuebraLinha( QStringList parametro ) {
    QString retorno;
    for ( QString receber : parametro ) {
        retorno.append( receber );
        retorno.append( "\n" );
    }
    return retorno;
};
