#include <QtGui/QApplication>
#include <QtCore>
#include "mainwindow.h"
#include "common/savage2.hxx"

using namespace std;
using namespace ::s2launcher;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QSettings settings("playsavage2", "savage2");
    QVariant qv = settings.value("baseurl", "http://playsavage2.com/mods/");
    QString filelistname = qv.toString() + "filelist.xml";

    xml_schema::Properties props;
    props.schema_location ("http://www.w3.org/XML/1998/namespace", "xml.xsd");
    props.no_namespace_schema_location(qv.toString() + "filelist.xsd");

    auto_ptr<::s2launcher::Base> pbase = ::s2launcher::parseBase(filelistname.toStdString(), 0, props);
    Base *base = pbase.get();
    ::xsd::cxx::tree::sequence<::s2launcher::Mod> &seq = base->getMod();


    return a.exec();
}
