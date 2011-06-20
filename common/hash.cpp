#include "hash.h"

static QCryptographicHash hash(QCryptographicHash::Sha1);
static qint chunksize = 1048576;
static char *buffer = malloc(chunksize);

bool HashEquals(const QString& hash, const QFile &file)
{
    QByteArray lhs = HashAsciiToByte(hash);
    QByteArray rhs = HashCompute(file);
    return lhs.size() > 0 && rhs.size() > 0 && lhs == rhs;
}

QByteArray& HashCompute(const QFile& f)
{
    QByteArray empty;

    if((!f.isOpen() && !f.open(QIODevice::ReadOnly)) || !f.isReadable())
        return empty;

    hash.reset();

    qint64 bytesread = 0;
    do
    {
        bytesread = f.read(buffer, chunksize);
        if(bytesread > 0)
            hash.addData(buffer, bytesread);
    }
    while(bytesread > 0);

    f.close();
    return hash.result();
}

QString& HashByteToAscii(const QByteArray& bhash)
{
    //SHA1 hashes are 20 bytes (160 bits) / 40 hexadecimal digits
    if(bhash.size() != 20)
        return QString();

    QString retval(bhash.toHex().data());
    if(retval.length() < 40)
    {
        QString fill = QString::fill('0', 40 - retval.length());
        retval.prepend(fill);
    }
    return retval;
}

QByteArray& HashAsciiToByte(QString& shash)
{
    if(shash.length() < 40)
    {
        QString fill = QString::fill('0', 40 - shash.length());
        shash.prepend(fill);
    }

    return QByteArray::fromHex(shash.toAscii());
}
