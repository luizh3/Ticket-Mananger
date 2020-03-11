#ifndef BILHETEENTRADAOUSAIDA_H
#define BILHETEENTRADAOUSAIDA_H

#include <QObject>
#include <QObject>
#include "tododto.h"
#include "tododtoinformacoesteladebusca.h"

class QNetworkAccessManager;

class BilheteEntradaOuSaida : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QList<QObject*> dtosTelaBusca READ dtosToObject NOTIFY dtosTelaBuscaChanged )
    Q_PROPERTY( QList<QObject*> dtos READ dtosToObject NOTIFY dtosChanged )
    Q_PROPERTY( QString printar READ arquivoPrintar NOTIFY arquivoPrintarChanged )
    Q_PROPERTY( bool selectAnimationFailOrSucess READ selectAnimationFailOrSucessPrintar WRITE setSelectAnimationFailOrSucessPrintar NOTIFY selectAnimationFailOrSucessChanged )
    Q_PROPERTY( bool animationRunnig READ animationRunnigPrintar WRITE setAnimationRunnigPrintar NOTIFY animationRunnigChanged )

public:

    void post( const QString& nome , const QString& data , const QString& hora , const QString& tipoBilhete , const QString& motivo );

    double selectAnimationFailOrSucessPrintar();
    void setSelectAnimationFailOrSucessPrintar( bool var );

    double animationRunnigPrintar();
    void setAnimationRunnigPrintar( bool var );

    explicit BilheteEntradaOuSaida( QObject* parent = nullptr );

    void telaDireita( QList<Tododto*> list );

    QList <QObject*> dtosToObject() const;

    void setArquivoPrintar( const QString& arquivoPrintar );

    QString getNomePdf() const;
    void setNomePdf( const QString& value );
    static QString retornoDto();

    QStringList getListDados() const;
    void setListDados( const QStringList& listDados );

    QString getDescriprion() const;
    void setDescriprion( const QString& descriprion );

    QString getMotivo() const;
    void setMotivo( const QString& motivo );

    QString getAssinatura() const;
    void setAssinatura( const QString& assinatura );

    QString getNome() const;
    void setNome( const QString& nome );

    QString getData() const;
    void setData( const QString& data );

    QString getHora() const;
    void setHora( const QString& hora );

    QString getEmitidoPor() const;
    void setEmitidoPor( const QString& emitidoPor );

    QString getTipoBilhete() const;
    void setTipoBilhete( const QString& tipoBilhete );

    int getOpcaoGerarPdf() const;

    QString getTurma() const;
    void setTurma( const QString& turma );

    QString getTurno() const;
    void setTurno( const QString& turno );

    QList<TodoDtoInformacoesTelaDebusca*> getDtosTelaBusca() const;
    void setDtosTelaBusca( const QList<TodoDtoInformacoesTelaDebusca*>& dtosTelaBusca );

    static constexpr const char* NOME = "nome";
    static constexpr const char* TIPO_BILHETE = "tipoBilhete";
    static constexpr const char* DATA = "data";
    static constexpr const char* HORA = "hora";
    static constexpr const char* MOTIVO = "motivo";

signals:
    void dtosChanged();
    void arquivoPrintarChanged();
    void mudarDeTela();
    void dtosTelaBuscaChanged();
    void selectAnimationFailOrSucessChanged( bool failOrSucess );
    void animationRunnigChanged();

public slots:

    void centroBilhete( const QString& description, const QString& nome, const QString& assinatura, const QString& data, const QString& turma, const QString& turno );
    void cabesalhoBilhete( const QString& tipoBilhete, const QString& motivo );
    void footer();
    void salvarArquivoFormatado();
    QString arquivoPrintar() const;
    void emitMudarTelaFundo();
    void buscarPorNomeDto( QString nome, QString turma );
    void listarNovoDto( Tododto* dto );
    void setOpcaoGerarPdf( int opcaoGerarPdf );
    void insertSalvarBancoDadosAluno();
    bool hasDtos();
    void pararAnimation();

private:
    QList<TodoDtoInformacoesTelaDebusca*> _dtosTelaBusca = {};
    QList<Tododto*> _dtos = {};
    QString _centro;
    QString _cabesalho;
    QString _footer;
    QString _arquivoPrintar;
    QString _nomePdf;
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
    int _opcaoGerarPdf;
    bool _selectAnimationFailOrSucess = false;
    bool _runnigAnimation = true;
    QNetworkAccessManager *mManager;

};

#endif // BILHETEENTRADAOUSAIDA_H
