#ifndef CONFIGBANCOGERAL_H
#define CONFIGBANCOGERAL_H

#include <QObject>
#include "tododto.h"

class ConfigBancoGeral : public QObject {
    Q_OBJECT
public:
    explicit ConfigBancoGeral( QObject* parent = nullptr );
    static void dataBaseOpenConexion();
    void insertBilhete( Tododto* dto );
    QList<Tododto*> selectPeloNomeETurma( QString nome, QString turma );
    static int selectUltimoIdBanco();
    void insertOrUpdateConfigGeral( QString dsNomeEscola , QString numMaximoCaracter );
    static QString selectNomeEscola();
    static bool validarTurmaEAlunoExistente( const QString nome, const QString turma );
    static void insertNomeTurma( const QString& nomeTurma );
    static QStringList selectTurmas();
    static int selectMaximoCarcterLinha();
    static void deleteTurma( const QString& nomeTurma );
    
    static constexpr const char* DS_NOME_ALUNO = "ds_nome_aluno";
    static constexpr const char* DS_NOME_ESCOLA = "ds_nome_escola";
    static constexpr const char* TP_BILHETE = "tp_bilhete";
    static constexpr const char* DS_DESCRICAO_BILHETE = "ds_descricao_bilhete";
    static constexpr const char* DS_ASSINATURA_PEDAGOGO = "ds_assinatura_pedagogo";
    static constexpr const char* DT_EMISSAO = "dt_data_emissao";
    static constexpr const char* DH_HORA_EMISSAO = "dh_hora_emissao";
    static constexpr const char* DS_MOTIVO = "ds_motivo";
    static constexpr const char* DS_TURMA = "ds_turma";
    static constexpr const char* DS_TURNO = "ds_turno_aluno";
    static constexpr const char* DS_TURMA_ALUNO = "ds_nome_turma";

    bool getFailOrSucess() const;
    void setFailOrSucess(bool value);

private:
    bool failOrSucess = false;

signals:



public slots:
};

#endif // CONFIGBANCOGERAL_H
