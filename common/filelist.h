#ifndef FILELIST_H
#define FILELIST_H

#include <QtCore>
#include <QtXml>
#include <QtXmlPatterns>
#include <QtNetwork>

class FileList : public QObject
{
    Q_OBJECT
public:
    explicit FileList(QObject *parent = 0, QUrl);
    ~FileList();
    void Serialize(QIODevice &);
    bool isSchemaValid();
    bool isDocumentValid();
    void replyFinished(QNetworkReply*);

signals:

public slots:

private:
    QList<ModInfo> mods;
    QXmlSchema schema;
    QXmlSchemaValidator dater;
    QUrl origDocument;
    bool validSchema;
    bool validDocument;
    QNetworkAccessManager *qnam;
};

#endif // FILELIST_H
