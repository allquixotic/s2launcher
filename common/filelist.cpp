#include "filelist.h"
#include "handler.h"
#include "savage2.hxx"
#include <QtXml>
#include <QtXmlPatterns>

//Just pass in the url path to the XML instance file, filelist.xml
FileList::FileList(QObject *parent, QUrl instance)
    : QObject(parent), origDocument(instance)
{
    this->schema.load(QUrl("qrc:/files/savage2.xsd"));
    this->validSchema = schema.isValid();

    if(this->validSchema)
    {
        dater.setSchema(this->schema);

        if(instance == QUrl() || !instance.isValid())
        {
            this->validDocument = true;
        }
        else
        {
            this->validDocument = dater.validate(instance);
        }

        if(isDocumentValid())
        {
            QIODevice de;
            qnam = new QNetworkAccessManager(this);
            connect(qnam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
            qnam->get(QNetworkRequest(this->origDocument));
        }
    }
    else
    {
        this->validDocument = false;
    }
}

FileList::~FileList()
{
    delete qnam;
}

//Gets the XML Instance document's bytes and then parses them out into the mods list.
void FileList::replyFinished(QNetworkReply* qnr)
{
    QByteArray lolbytes = qnr->readAll();
    QBuffer buf(lolbytes, this);






#if 0
    QXmlInputSource qxis(buf);
    QXmlSimpleReader qxsr;
    Handler hndl;
    qxsr.setContentHandler(hndl);
    qxsr.setErrorHandler(hndl);
    bool ok = qxsr.parse(qxis);
    if(!ok)
    {
        this->validDocument = false;
    }
#endif
    qnr->deleteLater();
}

bool FileList::isSchemaValid()
{
    return this->validSchema;
}

bool FileList::isDocumentValid()
{
    return this->validDocument;
}

void FileList::Serialize(QIODevice &dest)
{
    if(mods.length > 0)
    {

    }
    else
    {

    }
}
