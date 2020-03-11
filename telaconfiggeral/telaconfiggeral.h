#ifndef TELACONFIGGERAL_H
#define TELACONFIGGERAL_H

#include <QObject>

class TelaConfigGeral : public QObject {
    Q_OBJECT
    Q_PROPERTY( QStringList comboBox READ comboBoxPrintar NOTIFY comboBoxChanged )
    Q_PROPERTY( bool selectAnimationFailOrSucess READ selectAnimationFailOrSucess WRITE setSelectAnimationFailOrSucess NOTIFY selectAnimationFailOrSucessChanged )
public:
    explicit TelaConfigGeral( QObject* parent = nullptr );
    QStringList comboBoxPrintar() const;
    bool selectAnimationFailOrSucess() const;
    void setSelectAnimationFailOrSucess( bool selectAnimationFailOrSucess );

public Q_SLOTS:
    void insertNomeTurma( const QString& nomeTurma );

signals:
    void comboBoxChanged();
    void selectAnimationFailOrSucessChanged();
public slots:
    void salvarNomeEscola ( QString nomeEscola  , QString maximoCaraLinha);
    QString retornoNomeEscola();
    int retornoMaximoCaracterLinha();
    void deletarTurma( const QString& nomeTurma);

private:
    bool _selectAnimationFailOrSucess = false;
};

#endif // TELACONFIGGERAL_H
