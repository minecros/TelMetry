#include "digit.h"

Digit::Digit()
{
    QVBoxLayout *layout = new QVBoxLayout;
    QLabel *label = new QLabel;
    QLCDNumber *number = new QLCDNumber;
    
   label->setText("asfasfa");
   number->display(12222);
   label->setLayout(layout);
   number->setLayout(layout);
   
    
}
