/*
 * Да се имплементира класа Employee за која се чува:
име (низа од карактери)
години (цел број)
Во класата да се имплементира виртуелна функција displayInfo()
 која на екран печати информации за вработениот.

Потоа да се имплементира класа Payable за која се чува:

плата (децимален број)
За класата да се креира чисто виртуелна функција calculateSalary()

Од овие класи потребно е да се изведат Developer и Manager.

За класата Developer дополнително се чува и програмскиот јазик
 (низа од карактери). Потребно е да се препокријат соодветните функции.
 Платата се пресметува така што од основната плата се одзема данок од 10%.

За класата Manager дополнително се чува и број на оддели за кои е одговорен.
 Потребно е да се препокријат соодветните функции. Платата се пресметува така што
 на основната плата се додава бонус од 5% за секој еден оддел.

For example:

Input	Result
John
30
5000
C++
Mike
40
8000
3
Jane
45
6000
Java
Smith
28
5700
2
Ana
33
6200
Python
-- Developer Information --
Name: John
Age: 30
Salary: $4500
Programming Language: C++
-- Manager Information --
Name: Mike
Age: 40
Salary: $9200
Number of Departments: 3
-- Developer Information --
Name: Jane
Age: 45
Salary: $5400
Programming Language: Java
-- Manager Information --
Name: Smith
Age: 28
Salary: $6270
Number of Departments: 2
-- Developer Information --
Name: Ana
Age: 33
Salary: $5580
Programming Language: Python

Biggest Salary: 9200
 */

#include <iostream>
#include <cstring>
using namespace std;

class Employee{
protected:
    char name[60];
    int age;
public:
    Employee() = default;
    Employee(char* name, int age){
        strcpy(this->name,name);
        this->age = age;
    }
    virtual void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Payable{
protected:
    double salary;
public:
    Payable(double salary = 0){
        this->salary = salary;
    }
    virtual double calculateSalary() = 0;
};


class Developer : public Employee, public Payable{
private:
    char programmingLanguage[20];
public:
    Developer() = default;
    Developer(char* name, int age, double salary, char* prog) : Employee(name,age), Payable(salary){
        strcpy(this->programmingLanguage,prog);
    }
    double calculateSalary () override{
        return salary - (salary * 0.1);
    }
    void displayInfo(){
        cout << "-- Developer Information --" << endl;
        Employee::displayInfo();
        cout << "Salary: $" <<  calculateSalary() << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};
class Manager : public Employee, public Payable{
private:
    int num_Departments;
public:
    Manager() = default;
    Manager(char* name, int age, double salary,int departments) : Employee(name,age), Payable(salary) {
        this->num_Departments = departments;
    }
    double calculateSalary () override{
        double bonus = 5;
        bonus *= num_Departments;
        bonus/=100;
        return salary + (salary * bonus);
    }

    void displayInfo(){
        cout << "-- Manager Information --" << endl;
        Employee::displayInfo();
        cout << "Salary: $" <<  calculateSalary() << endl;
        cout << "Number of Departments: " << num_Departments << endl;
    }

};

double biggestSalary(Payable* payable[], int n) {
    Payable* maxSalaryEmployee = payable[0];

    for (int i = 1; i < n; i++) {
        if (payable[i]->calculateSalary() > maxSalaryEmployee->calculateSalary()) {
            maxSalaryEmployee = payable[i];
        }
    }

    return maxSalaryEmployee->calculateSalary();
}

int main()
{
    Payable* payable[5];
    Developer developers[5];
    Manager managers[5];
    int j=0, k=0;
    for(int i=0; i<5; i++)
    {
        char name[50];
        int age;
        double salary;
        cin>>name>>age>>salary;
        if(i%2==0)
        {
            char programmingLanguage[50];
            cin>>programmingLanguage;
            developers[j]=Developer(name, age, salary, programmingLanguage);
            developers[j].displayInfo();
            payable[i]=&developers[j];
            j++;
        }
        else {
            int numberOfDepartments;
            cin>>numberOfDepartments;
            managers[k]=Manager(name, age, salary, numberOfDepartments);
            managers[k].displayInfo();
            payable[i]=&managers[k];
            k++;
        }
    }
    cout<<endl<<"Biggest Salary: "<<biggestSalary(payable, 5);
    return 0;
}
