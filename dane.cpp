#include "dane.h"
Dane::Dane(QString fileName){

        file.setFileName(fileName);

         if(file.open(QIODevice::ReadOnly | QFile::Text)){
             //gdy udalo sie otworzyc plik
             isFileOpen = true;
             setRow();

         }else{
             isFileOpen = false;
         }
}

QStringList Dane::getLabel(){

    if(isLabelSet)
    {
        return label;

    }else
    {

        return label;

    }
}

QStringList Dane::getRow()
{
    return row;   
}

void Dane::setRow()
{

    QTextStream in(&file);

    while(!in.atEnd())
    {

        text = in.readLine();

        if(isLabelSet)
        {

            row = text.split(',');

        }else
        {

            row = text.split(',');
            label = row;
            isLabelSet = true;

        }

        allData.append(row);

    }

}

void Dane::readAll()
{

}
Dane::~Dane()
{
    file.close(); 
}

