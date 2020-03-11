#ifndef CABECALHOBILHETE_H
#define CABECALHOBILHETE_H

#include <QObject>

class CabecalhoBilhete : public QObject {
    Q_OBJECT
public:

    explicit CabecalhoBilhete( QObject* parent = nullptr );

signals:

public slots:
    QString cabesalhoBilhete( QString tipoBilhete, QString emitopor, QString motivo );
};

#endif // CABECALHOBILHETE_H
