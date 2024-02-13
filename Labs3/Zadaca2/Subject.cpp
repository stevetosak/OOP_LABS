/*
 * Да се дефинира класа Subject  за која се чува:
име (низа од карактери)
број на кредити (цел број)
За класата да се дефинира default конструктор, конструктор со аргументи и copy конструктор.

Потоа да се дефинира класа Student за која се чува:
име (низа од карактери)
презиме (низа од карактери)
индекс (низа од карактери)
5 предмети што ги слуша (низа од објекти од класата Subject)
метод total() што ќе го пресметува вкупниот број на кредити што ќе ги има студентот откако ќе ги положи предметите
метод display() кој што ќе испечати информации во формат:
Име презиме -> индекс -> кредити
За класата да се дефинира  default конструктор и конструктор со аргументи.

По потреба може да се креираат get и set методи.

Да не се менува main функцијата.
For example:

Input	Result
Ana
Anovska
333333
IT
4
OOP
8
BP
13
OS
7
APS
2
Ana Anovska -> 333333 -> 34

 */

#include <iostream>
#include <cstring>
using namespace std;

class Subject{
private:
    char name[30];
    int no_credits;
public:
    Subject() = default;
    Subject(char* name,int no_credits){
        strcpy(this->name,name);
        this-> no_credits = no_credits;
    }
    Subject(const Subject& other){
        strcpy(this->name,other.name);
        this-> no_credits = other.no_credits;
    }

    friend class Student;
};

class Student{
private:
    char name[30];
    char surname [30];
    char ID[10];
    Subject subjects[5];
public:
    Student() = default;
    Student(char * name, char* surname,char *ID, Subject *subjects){
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        strcpy(this->ID,ID);
        for(int i = 0; i < 5; i++){
            this->subjects[i] = subjects[i];
        }
    }

    int total(){
        int sum = 0;
        for(int i = 0;  i < 5; i++){
            sum+=subjects[i].no_credits;
        }
        return sum;
    }

    void display(){
        cout << name << " " << surname << " -> " << ID << " -> " << total() <<endl;
    }
};

//DO NOT CHANGE THE MAIN FUNCTION
int main()
{
    char stName[100], stSurname[100], stIndex[100];
    cin>>stName>>stSurname>>stIndex;
    //Testing default constructor for Subject
    Subject subjects[5];
    for(int i=0; i<5; i++)
    {
        char sbName[100];
        int c;
        cin>>sbName>>c;
        //Testing constructor with arguments for Subject
        subjects[i]=Subject(sbName, c);
    }
    //Testing default constructor for Student
    Student student;
    //Testing constructor with arguments for Student and copy constructor for Subject
    student=Student(stName, stSurname, stIndex, subjects);
    //Testing display() and total() methods
    student.display();
    return 0;
}
