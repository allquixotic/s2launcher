#ifndef HASH_H
#define HASH_H

#include <QtCore>

bool HashEquals(const QString& hash, const QFile&);
QByteArray& HashCompute(const QFile&);
QString& HashByteToAscii(const QByteArray&);
QByteArray& HashAsciiToByte(QString&);

#endif // HASH_H
