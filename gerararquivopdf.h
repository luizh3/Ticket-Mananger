#ifndef GERARARQUIVOPDF_H
#define GERARARQUIVOPDF_H

#include <QObject>

class GerarArquivoPdf : public QObject {
    Q_OBJECT
public:
    explicit GerarArquivoPdf( QObject* parent = nullptr );
    void gerarArquivoPdf( QString pdf, QString nomeArquivo );
signals:

public slots:
};

#endif // GERARARQUIVOPDF_H
