#ifndef DIGIT_H
#define DIGIT_H
#include <QVBoxLayout>
#include <QLabel>
#include <QLCDNumber>


class Digit
{
private:
    QVBoxLayout *layout;
    QLabel *label;
    QLCDNumber *number;
public:
    Digit();
    QVBoxLayout getDigit();

};

#endif // DIGIT_H
