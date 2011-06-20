#ifndef MODINFO_H
#define MODINFO_H

#include <QtCore>

class ModInfo : public QObject
{
    Q_OBJECT
public:
    explicit ModInfo(QObject *parent = 0);
    QString name;
    QString description;
    QString hash;
    qint bytesize;
    QUrl urldownload;
    QUrl urlpic;
signals:

public slots:

private:
};

#endif // MODINFO_H
