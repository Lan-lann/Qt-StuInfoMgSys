#pragma once
#include <QString>
#include <iostream>
#include <string>

class CStudentInfo
{
private:
    QString Name, Number, Sex;
    int Chinese, Math, English, Age;

public:
    ~CStudentInfo();
    CStudentInfo(QString Name, QString Number, QString Sex,int Age, int Chinese, int Math, int English);
    QString getName();

    QString getNumber();
    
    QString getSex();
    
    int getChinese();
   
    int getEnglish();
   
    int getMath();

    int getAge();

    QString toString(int);
    
   /* void setId(int tid) {
        id = tid;
    }
    void setName(QString tname) {
        name = tname;
    }
    void setMath(int tmath) {
        math = tmath;
        avg = (math + english + languageC) / 3.0;
    }
    void setEnglish(int tenglish) {
        english = tenglish;
        avg = (math + english + languageC) / 3.0;
    }
    void setLanguageC(int tlanguageC) {
        languageC = tlanguageC;
        avg = (math + english + languageC) / 3.0;
    }*/
};



