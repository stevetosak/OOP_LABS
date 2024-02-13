/*
 * Да се дефинира класа MobilePhone во која ќе се чуваат податоци за еден мобилен телефон:

модел (низа од карактери не подолга од 20 карактери)
број на модел (цел број)
година на издавање (цел број)
За класата да се дефинира default конструктор, конструктор со аргументи, copy конструктор, деструктор
 и доколку има потреба get методи. Исто така да се дефинира и фунцкија за печатење на информации за класата која
 ќе печати во следниот формат „(модел) (број на модел) release year: (година на издавање)“.

Потоа да се дефинира класа Owner во која се чуваат следните информации:

име (низа од карактери не подолга од 20 карактери)
презиме (низа од карактери не подолга од 20 карактери)
мобилен телефон (објект од класа MobilePhone)
Да се креира default конструктор, конструктор со аргументи, деструктор и доколку има потреба get методи.
 Исто така да се дефинира и функција за печатење на информации за класата која ќе печати во следниот формат:

„(име) (презиме) has a mobile phone:

(информации за мобилен телефон)“

ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА!!!

For example:

Input	Result
1
Iphone
12
2020
Marko
Petrov
Marko Petrov has a mobile phone:
Iphone 12 release year: 2020

 */

#include <iostream>
#include <cstring>
using namespace std;
class MobilePhone{
private:
    char model[20];
    int no_model;
    int year;
public:
    MobilePhone() = default;

    MobilePhone(char *model, int noModel, int year): no_model(noModel), year(year) {
        strcpy(this-> model,model);
    }
    MobilePhone(const MobilePhone& other){
        strcpy(this-> model,other.model);
        this-> no_model =other.no_model;
        this-> year = other.year;
    }
    ~MobilePhone(){
        //empty
    }

    void print(){
        cout << model<< " "<<no_model << " " <<"release year:" << " " <<  year << endl;
    }

};

class Owner{
private:
    char name[20];
    char surname[20];
    MobilePhone mphone;
public:
    Owner() = default;
    Owner(char *name, char *surname, const MobilePhone &mphone) : mphone(mphone) {
        strcpy(this -> name,name);
        strcpy(this->surname, surname);
    }
    Owner(const Owner& other){
        strcpy(this -> name,other.name);
        strcpy(this->surname, other.surname);
        this->mphone = other.mphone;
    }
    ~Owner(){
        //empty
    }

    void print(){
        cout << name << " " << surname << " " << "has a mobile phone:" <<endl;
        mphone.print();
    }


};


int main() {
    char model[20];
    int modelNumber;
    int year;
    char name[20];
    char surname[20];

    int testCase;

    cin>>testCase;

    cin>>model;
    cin>>modelNumber;
    cin>>year;
    cin>>name;
    cin>>surname;

    if(testCase==1){
        MobilePhone mobilePhone(model,modelNumber,year);

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }
    if(testCase==2){
        MobilePhone mobilePhone(MobilePhone(model,modelNumber,year));

        Owner owner(name,surname,mobilePhone);
        owner.print();
    }

}


