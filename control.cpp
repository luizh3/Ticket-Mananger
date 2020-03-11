#include <QDebug>
#include "control.h"
#include "telaconfiggeral/telaconfiggeral.h"
#include "QFuture"
#include "QtConcurrent"
#include "QKeyEvent"
Control::Control( QObject* parent ) :
    QObject( parent ) {}

void Control::chamarSignal(){

 TelaConfigGeral telaConfig;

 Control a , b;

 Tododto aluk1 , aluk2;

 QObject::connect( &a , &Control::nomeChanged , this , &Control::slotTeste );
// QObject::connect( &aluk1, &Tododto::nomeChanged , &aluk2 , &Tododto::setNome );
 QObject::connect( &a , &Control::nadaChanged , this , &Control::apenasImprime );

 aluk1.setNome("s");
 a.setNome("carlos");
 b.setNome("carlinhos");

}

void Control::imprimirNumeros( int var ){
        qDebug()<<"carlos"<< var;
}

QString Control::nome() const
{
    return _nome;
}

void Control::setNome(const QString &nome){
    if( !nome.isEmpty() ){
    _nome = nome;
    emit nadaChanged();
    emit nomeChanged( nome );
    }
}

void Control::slotTeste(QString calros){
    qDebug()<<calros;
}

void Control::apenasImprime(){
    for (int i = 0 ; i < 10;i++) {
       qCritical()<<"Numeros"<<i;
    }
}



