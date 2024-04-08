#include "CStudentInfo.h"

CStudentInfo::CStudentInfo(QString Name, QString Number, QString Sex, int Age, int Chinese, int Math, int English) 
{
    this->Name = Name;
    this->Number = Number;
    this->Sex = Sex;
    this->Chinese = Chinese;
    this->Math = Math;
    this->English = English;
    this->Age = Age;
}

CStudentInfo::~CStudentInfo()
{

}

QString CStudentInfo::getName()
{
    return Name;
}

QString CStudentInfo::getNumber()
{
    return Number;
}

QString CStudentInfo::getSex()
{
    return Sex;
}

int CStudentInfo::getChinese()
{
    return Chinese;
}

int CStudentInfo::getEnglish()
{
    return English;
}

int CStudentInfo::getMath()
{
    return Math;
}

int CStudentInfo::getAge()
{
    return Age;
}

QString CStudentInfo::toString(int a)
{
    return QString::number(a);
}