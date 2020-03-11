#ifndef TODODTO_H
#define TODODTO_H

#include <QObject>

class Tododto : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString description READ getDescription WRITE setDescription NOTIFY descriptionChanged )
    Q_PROPERTY( QString nome READ getNome WRITE setNome NOTIFY nomeChanged )
    Q_PROPERTY( QString assinatura READ getAssinatura WRITE setAssinatura NOTIFY assinaturaChanged )
    Q_PROPERTY( QString motivo READ getMotivo WRITE setMotivo NOTIFY motivoChanged )
    Q_PROPERTY( QString turno READ getTurno WRITE setTurno NOTIFY turnoChanged )
    Q_PROPERTY( QString turma READ getTurma WRITE setTurma NOTIFY turmaChanged )
    Q_PROPERTY( QString tipoBilhete READ getTipoBilhete WRITE setTipoBilhete NOTIFY tipoBilheteChanged )
    Q_PROPERTY( QString emitidoPor READ getEmitidoPor WRITE setEmitidoPor NOTIFY emitidoPorChanged )
    Q_PROPERTY( QString hora READ getHora WRITE setHora NOTIFY horaChanged )
    Q_PROPERTY( QString data READ getData WRITE setData NOTIFY dataChanged )


public:
    explicit Tododto( QObject* parent = nullptr );
    ~Tododto();

    QString getDescription() const;
    void setDescription( const QString& descriprion );

    QString getNome() const;
    void setNome( const QString& nome );

    QString getAssinatura() const;
    void setAssinatura( const QString& assinatura );

    QString getMotivo() const;
    void setMotivo( const QString& motivo );

    QString getData() const;
    void setData( const QString& data );

    QString retornaNome() const;

    QString getHora() const;
    void setHora( const QString& hora );

    QString getEmitidoPor() const;
    void setEmitidoPor( const QString& emitidoPor );

    QString getTipoBilhete() const;
    void setTipoBilhete( const QString& tipoBilhete );

    QString getTurma() const;
    void setTurma( const QString& turma );

    QString getTurno() const;
    void setTurno( const QString& turno );

signals:
    void textChanged();
    void descriptionChanged();
    void nomeChanged();
    void assinaturaChanged();
    void motivoChanged();
    void dataChanged();
    void turnoChanged();
    void turmaChanged();
    void tipoBilheteChanged();
    void emitidoPorChanged();
    void horaChanged();

public slots:

private:
    QString _descriprion;
    QString _motivo;
    QString _assinatura;
    QString _nome;
    QString _data;
    QString _hora;
    QString _emitidoPor;
    QString _tipoBilhete;
    QString _turma;
    QString _turno;

};
#endif // TODODTO_H
