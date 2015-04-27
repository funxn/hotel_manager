#include <QApplication>
#include <QLayout>
#include <QTextCodec>

#include "content.h"


Content::Content(QWidget *parent, Qt::WindowFlags f1)
	: QFrame(parent,f1)
{
    stack = new QStackedWidget();
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    callCheckin = new CallCheckin();
    callCheckout = new CallCheckout();
    detail = new Detail();
    stack->addWidget(callCheckin);
    stack->addWidget(callCheckout);
    stack->addWidget(detail);
    //stack->addWidget(wait??);
    
    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->setMargin(10);
    mainlayout->setSpacing(6);
    mainlayout->addWidget(stack);
}
