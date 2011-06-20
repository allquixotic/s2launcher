#ifndef HANDLER_H
#define HANDLER_H

#include <QXmlDefaultHandler>

class Handler : public QXmlDefaultHandler
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = 0);

signals:

public slots:

};

#endif // HANDLER_H
