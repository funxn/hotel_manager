#ifndef BASEINFO_H
#define BASEINFO_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>

class CallCheckin : public QWidget
{
    Q_OBJECT
public:
    CallCheckin(QWidget *parent = 0, Qt::WindowFlags f1 = 0);

    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * label4;
    QLabel * label5;
    QLabel * label6;
    QLabel * label7;
    QLabel * labelOther;
    QLineEdit * lineEditName;
    QComboBox * comboBoxSex;
    QLineEdit * lineEditAge;
    QLineEdit * lineEditRoomNumber;
    QLineEdit * lineEditID;
    QLineEdit * lineEditCompany;
    QLineEdit * lineEditCity;
    QPushButton * pushButtonAmend;
    QPushButton * pushButtonClose;

private slots:
    // slots ---> by xiaofeng
    void slotCheckin();
};

#endif
