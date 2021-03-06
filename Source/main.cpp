#include <QApplication>
#include <QTranslator>
#include "window.h"
#include "splash.h"

void Translate()
{
    QLocale::Language lang = QLocale::system().language();
    QStringList files;
    if(lang == QLocale::Language::Russian) files = {":/root/Resources/ru.qm"};
    else files = {":/root/Resources/en.qm"};
    foreach (QString file, files)
    {
        QTranslator* trans = new QTranslator(qApp);
        if(trans->load(file)) qApp->installTranslator(trans);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Translate();

    Splash s;
    s.exec();

    Window w;
    w.show();
    return a.exec();
}
