#include <QApplication>
#include <QTranslator>
#include <QTextEdit>
#include <QListWidget>
#include <QSplitter>
#include <QTextCodec>
#include <QStackedWidget>
// added by xiaofeng ---> for fonts problems
#include <QTextCodec>

// added by xiaofeng --> for splash image before start the program
#include <QSplashScreen>
#include <QPixmap>

#include <unistd.h>

#include "content.h"


int main( int argc, char * argv[] )
{
    QApplication app(argc, argv);
    QPixmap pixmap("pic.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    app.processEvents();

/*
    QFont font("AR PL KaitiM GB",12);
    app.setFont(font);
    
    QTranslator translator;
    translator.load("combine_zh");
    app.installTranslator(&translator);    
*/

    // using UTF-8 coding ---> by xiaofeng
    QTextCodec * codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);


    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0,QObject::tr("客户入住登记"));
    list->insertItem(1,QObject::tr("客户退房登记"));
    list->insertItem(2,QObject::tr("系统查询"));
    list->insertItem(3,QObject::tr("系统管理"));
    
    Content *content = new Content(splitterMain);
    
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));
    
    splitterMain->setWindowTitle(QObject::tr("酒店管理系统"));
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());

    sleep(1);

    splitterMain->show();

    splash.finish(splitterMain);

    return app.exec();
}
