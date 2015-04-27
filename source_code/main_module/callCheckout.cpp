/*
 * 本文件用于负责客户登出的界面处理
 * @ by xiaofeng
 *
 */

#include "callCheckout.h"
#include <QLayout>
#include <QTextCodec>
#include <QPixmap>
#include <string.h>
#include "const.h"
#include "type.h"
#include "global.h"
#include "proto.h"

CallCheckout::CallCheckout(QWidget *parent, Qt::WindowFlags f1)
        : QWidget(parent,f1)
{
    label1 = new QLabel(tr("请输入登出客户的证件号:"));
    lineEditID = new QLineEdit();

    
    QGridLayout * leftLayout = new QGridLayout();

    leftLayout->addWidget(label1,0,0);		// age row
    leftLayout->addWidget(lineEditID,1,0);

    
/*
    leftLayout->setColumnStretch(0,1);
    leftLayout->setColumnStretch(1,3);
    
    leftLayout->setRowStretch(0,1);
    leftLayout->setRowStretch(3,3);
  */  
    pushButtonAmend = new QPushButton();
    pushButtonAmend->setText(tr("确 认"));
    pushButtonClose = new QPushButton();
    pushButtonClose->setText(tr("取 消"));
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(pushButtonAmend);
    buttonLayout->addWidget(pushButtonClose);
    

    
    // main layout -- is a hBoxLayout
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(buttonLayout);

    connect(pushButtonAmend,SIGNAL(clicked()),this,SLOT(slotCheckout())); 
}

void CallCheckout::slotCheckout(){
	char temp[ID_SIZE];
	strcpy(temp, lineEditID->text().toStdString().c_str());
	check_out(temp);

}
