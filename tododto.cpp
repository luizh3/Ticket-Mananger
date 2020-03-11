#include "tododto.h"
#include "QDebug"

Tododto::Tododto( QObject* parent ) :
    QObject( parent ) {}

Tododto::~Tododto() {
    qCritical() << "Objeto Destruido";
}

QString Tododto::getDescription() const {
    return _descriprion;
}

void Tododto::setDescription( const QString& description ) {
    _descriprion = description;
    emit descriptionChanged();
}

QString Tododto::getNome() const {
    return _nome;
}

void Tododto::setNome( const QString& nome ) {
    _nome = nome;
    emit nomeChanged();
}

QString Tododto::getAssinatura() const {
    return _assinatura;
}

void Tododto::setAssinatura( const QString& assinatura ) {
    _assinatura = assinatura;
    emit assinaturaChanged();
}

QString Tododto::getMotivo() const {
    return _motivo;
}

void Tododto::setMotivo( const QString& motivo ) {
    _motivo = motivo;
    emit motivoChanged();
}

QString Tododto::getData() const {
    return _data;
}

void Tododto::setData( const QString& data ) {
    _data = data;
    emit dataChanged();
}

QString Tododto::retornaNome() const {
    static QString printar;
    printar = _nome;
    return printar;
}

QString Tododto::getHora() const {
    return _hora;
}

void Tododto::setHora( const QString& hora ) {
    _hora = hora;
}

QString Tododto::getEmitidoPor() const {
    return _emitidoPor;
}

void Tododto::setEmitidoPor( const QString& emitidoPor ) {
    _emitidoPor = emitidoPor;
}

QString Tododto::getTipoBilhete() const {
    return _tipoBilhete;
}

void Tododto::setTipoBilhete( const QString& tipoBilhete ) {
    _tipoBilhete = tipoBilhete;
}

QString Tododto::getTurma() const {
    return _turma;
}

void Tododto::setTurma( const QString& turma ) {
    _turma = turma;
}

QString Tododto::getTurno() const {
    return _turno;
}

void Tododto::setTurno( const QString& turno ) {
    _turno = turno;
}


