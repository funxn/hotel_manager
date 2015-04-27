#include "callCheckin.h"
#include "const.h"
#include "type.h"
#include "global.h"
#include "proto.h"

#include <QLayout>
#include <QTextCodec>
#include <QPixmap>
#include <QString>
#include <stdio.h>
#include <string.h>

void addNode(LNode head, CUSTOMER temp){						// 考虑将addNode()函数交给QTGui按下按钮时调用
	LNode p = (LNode)malloc(sizeof(Node));
	p->customer=temp;
	p->next = head->next;			//头插式注意!
	head->next = p;

	check_in(temp);							// 在此处调用checkIn()对客户进行注册
}


CallCheckin::CallCheckin(QWidget *parent, Qt::WindowFlags f1)
        : QWidget(parent,f1)
{
   
    // create 
    label1 = new QLabel(tr("姓  名:"));
    label2 = new QLabel(tr("性  别:"));
    label3 = new QLabel(tr("年  龄:"));
    label4 = new QLabel(tr("房间号:"));
    label5 = new QLabel(tr("证件号:"));
    labelOther = new QLabel(tr("备 注:"));
    labelOther->setFrameStyle(QFrame::Panel|QFrame::Sunken);  
    label6 = new QLabel(tr("单  位:"));
    label7 = new QLabel(tr("城  市:"));
    
    lineEditName = new QLineEdit();
    lineEditAge = new QLineEdit();
    lineEditRoomNumber = new QLineEdit();
    lineEditID = new QLineEdit();

    lineEditCompany = new QLineEdit();
    lineEditCity = new QLineEdit();
    
    comboBoxSex = new QComboBox();
    comboBoxSex->insertItem(0,tr("男"));
    comboBoxSex->insertItem(1,tr("女"));
    
    
    //  Lay out
    // left layout -- is a grid layout
    QGridLayout * leftLayout = new QGridLayout();

    int labelCol = 0;
    int contentCol = 1;
    
    leftLayout->addWidget(label1,0,labelCol);		// user name row
    leftLayout->addWidget(lineEditName,0,contentCol);
    
    leftLayout->addWidget(label2,1,labelCol);		// name row
    leftLayout->addWidget(comboBoxSex,1,contentCol);
    
    leftLayout->addWidget(label3,2,labelCol);		// sex row
    leftLayout->addWidget(lineEditAge,2,contentCol);
    
    leftLayout->addWidget(label4,3,labelCol);  // department row
    leftLayout->addWidget(lineEditRoomNumber,3,contentCol);

    leftLayout->addWidget(label5,4,labelCol);		// age row
    leftLayout->addWidget(lineEditID,4,contentCol);
    

    leftLayout->setColumnStretch(0,1);
    leftLayout->setColumnStretch(1,3);
    
    leftLayout->setRowStretch(0,1);
    leftLayout->setRowStretch(3,3);
    
    leftLayout->addWidget(label6,5,labelCol);
    leftLayout->addWidget(lineEditCompany,5,contentCol);
    
    leftLayout->addWidget(label7,6,labelCol);
    leftLayout->addWidget(lineEditCity,6,contentCol);

    leftLayout->addWidget(labelOther,7,0,1,1);		// other
/*  
    // right layout -- is a vBoxLayout
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->setMargin(10);
    rightLayout->addWidget(label6);
    rightLayout->addWidget(lineEditCompany);
    
    rightLayout->addWidget(label7);
    rightLayout->addWidget(lineEditCity);
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

    
    //connect(pushButtonClose,SIGNAL(clicked()),qApp,SLOT(quit()));   
    connect(pushButtonAmend,SIGNAL(clicked()),this,SLOT(slotCheckin()));   

}

void CallCheckin::slotCheckin(){
	CUSTOMER temp;
	strcpy(temp.name, lineEditName->text().toStdString().c_str());
	temp.sex = comboBoxSex->count();
	temp.age = lineEditAge->text().toInt();
	temp.roomNumber = lineEditRoomNumber->text().toInt();
	strcpy(temp.id, lineEditID->text().toStdString().c_str());
	strcpy(temp.company,  lineEditCompany->text().toStdString().c_str());
	strcpy(temp.city,  lineEditCity->text().toStdString().c_str());

/*
	printf("%s, %d, %d, %d, %s, %s, %s", temp.name, temp.sex, 
		temp.age, temp.roomNumber, temp.id, temp.company, 
		temp.city);
*/
	
	addNode(head, temp);

}
