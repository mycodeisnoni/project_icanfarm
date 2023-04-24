
#include "mainwindow.h"

#include <QApplication>

#include <QLocale>
#include <QTranslator>
#include <QSize>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "main_ssafy_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    QSize size(800, 480);
    w.resize(size);
    w.show();
    return a.exec();
}
