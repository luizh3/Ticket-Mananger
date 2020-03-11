#ifndef TODODTOINFORMACOESTELADEBUSCA_H
#define TODODTOINFORMACOESTELADEBUSCA_H

#include <QObject>

class TodoDtoInformacoesTelaDebusca : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString nome READ nome WRITE setNome NOTIFY nomeChanged )
    Q_PROPERTY( QString numeroTotalBilhetes READ numeroTotalBilhetes WRITE setNumeroTotalBilhetes NOTIFY numeroTotalBilhetesChanged )
    Q_PROPERTY( QString numeroBilhetesEntrada READ numeroBilhetesEntrada WRITE setNumeroBilhetesEntrada NOTIFY numeroBilhetesEntradaChanged )
    Q_PROPERTY( QString numeroBilhetesSaida READ numeroBilhetesSaida WRITE setNumeroBilhetesSaida NOTIFY numeroBilhetesSaidaChanged )
    Q_PROPERTY( QString dataUltimoBilhete READ dataUltimoBilhete WRITE setDataUltimoBilhete NOTIFY dataUltimoBilheteChanged )
    Q_PROPERTY( QString turmaDoAluno READ turmaDoAluno WRITE setTurmaDoAluno NOTIFY turmaDoAlunoChanged )
    Q_PROPERTY( QString turnoDoAluno READ turnoDoAluno WRITE setTurnoDoAluno NOTIFY turnoDoAlunoChanged )
    Q_PROPERTY( QString bilhetesSuspenssao READ bilhetesSuspenssao WRITE setBilhetesSuspenssao NOTIFY bilhetesSuspenssaoChanged )

public:
    explicit TodoDtoInformacoesTelaDebusca( QObject* parent = nullptr );

    QString nome() const;
    void setNome( const QString& nome );

    QString numeroTotalBilhetes() const;
    void setNumeroTotalBilhetes( const QString& numeroTotalBilhetes );

    QString numeroBilhetesEntrada() const;
    void setNumeroBilhetesEntrada( const QString& numeroBilhetesEntrada );

    QString numeroBilhetesSaida() const;
    void setNumeroBilhetesSaida( const QString& numeroBilhetesSaida );

    QString dataUltimoBilhete() const;
    void setDataUltimoBilhete( const QString& dataUltimoBilhete );

    QString bilhetesSuspenssao() const;
    void setBilhetesSuspenssao( const QString& bilhetesSuspenssao );

    QString turnoDoAluno() const;
    void setTurnoDoAluno( const QString& turnoDoAluno );

    QString turmaDoAluno() const;
    void setTurmaDoAluno( const QString& turmaDoAluno );

signals:

    void nomeChanged();
    void numeroTotalBilhetesChanged();
    void numeroBilhetesEntradaChanged();
    void numeroBilhetesSaidaChanged();
    void dataUltimoBilheteChanged();
    void bilhetesSuspenssaoChanged();
    void turnoDoAlunoChanged();
    void turmaDoAlunoChanged();

public slots:

private:
    QString _nome;
    QString _numeroTotalBilhetes;
    QString _numeroBilhetesEntrada;
    QString _numeroBilhetesSaida;
    QString _dataUltimoBilhete;
    QString _turmaDoAluno;
    QString _turnoDoAluno;
    QString _bilhetesSuspenssao;
};

#endif // TODODTOINFORMACOESTELADEBUSCA_H
