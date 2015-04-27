#ifndef CONTACT_H
#define CONTACT_H

//#include <qvariant.h>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class CallCheckout : public QWidget
{
    Q_OBJECT

public:
    CallCheckout( QWidget* parent = 0, Qt::WindowFlags fl = 0 );
    //~CallCheckout();

    QLabel* label1;
    QLineEdit* lineEditID;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonAmend;

private slots:
    void slotCheckout();
};

#endif // CONTACT_H
