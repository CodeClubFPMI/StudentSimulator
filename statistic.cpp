#include <QString>
#include <QDebug>
#include <QFile>
#include "statistic.h"

Statistic::Statistic(QWidget *parent) : QWidget(parent), layout_(this)
{
    QString file_path =  PRO_FILE_PWD;
    file_path += + "/statistic.txt";
    QFile file(file_path);
//    if ((file.exists())&&(file.open(QIODevice::ReadOnly))){
//        QString str="";
//        while(!file.atEnd())
//        {
//           str=str+file.readLine();
//        }
//        file.close();
//        qDebug() << str;
//    }
}
