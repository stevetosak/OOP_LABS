/*
 * Да се имплементира класа Course за која се чуваат информации за:
име на курс (низа од карактери)
Во класата да се имплементира виртуелна функција void displayInfo() која
 на екран печати информации за дадениот курс и виртуелна функција int level() која го враќа нивото на курсот.

Потребно е да се имплементират класите RegularCourse и SpecialCourse кои што ќе наследуваат од класата Course.

За класата RegularCourse дополнително се чуваат:

maxStudents - максимален број на студенти (цел број)
Доколку бројот на студенти е помал од 10, нивото е 10, ако бројот на студенти
 е помеѓу 10 и 30 нивото е 7, и ако бројот на студенти е над 30 нивото е 5. Печатењето е во следен формат:

Name: [име на курс]

Students: [број на студенти]

Level: [ниво]

За класата SpecialCourse дополнително се чуваат:

numTeachers - број на предавачи (цел број)
Доколку бројот на предавачи е помал од 3 нивото е 6, ако бројот на предавачи
 е поголем од 3 и помал од 5 нивото е 8, а во спротивно е 10. Печатењето е во следен формат:
Name: [име на курс]

Teachers: [број на предавачи]

Level: [ниво]

Потребно е да се имплементира класата RSCourse која што ќе наследува од класите RegularCourse и SpecialCourse.

Нивото се пресметува: (ниво на RegularCourse + 2) + (ниво на SpecialCourse -1). Печатењето е во следен формат:
Name: [име на курс]

Level: [ниво]

Да се направи глобална функција Course *bestCourse(Course**courses, int n) што ќе врати покажувач до курсот со највисоко ниво.





For example:

Input	Result
1
OOP
150
--- Testing RegularCourse class ---
Name: OOP
Students: 150
Level: 5
 */

#include <iostream>
#include <cstring>

using namespace std;
class Course{
protected:
    char name[64];
public:
    Course(char* name = ""){
        strcpy(this->name,name);
    }
    virtual void displayInfo(){
        cout << "Name: " << name << endl;
    }
    virtual int level() = 0;
};

class RegularCourse : virtual public Course{
private:
    int maxStudents;
public:
    RegularCourse(char* name, int maxstudents) : Course(name){
        this->maxStudents = maxstudents;
    }
    int level() override{
        if(maxStudents < 10){
            return 10;
        }
        else if(maxStudents > 10 && maxStudents < 30){
            return 7;
        }
        else{
            return 5;
        }
    }
    void displayInfo() override{
        Course::displayInfo();
        cout << "Students: " << maxStudents << endl;
        cout << "Level: " << level() << endl;
    }
};

class SpecialCourse : virtual public Course{
private:
    int numTeachers;
public:
    SpecialCourse(char* name, int numTeachers) : Course(name){
        this->numTeachers = numTeachers;
    }
    int level() override{
        if(numTeachers < 3){
            return 6;
        }
        else if(numTeachers == 4){
            return 8;
        }
        else{
            return 10;
        }
    }
    void displayInfo() override{
        Course::displayInfo();
        cout << "Teachers: " << numTeachers << endl;
        cout << "Level: " << level() << endl;
    }
};

class RSCourse :public RegularCourse, public SpecialCourse{
public:
    RSCourse(char* name, int maxStudents, int numTeachers) : Course(name),
                                                             RegularCourse(name,maxStudents), SpecialCourse(name,numTeachers){}
    int level(){
        return (RegularCourse::level() + 2) + (SpecialCourse::level() -1);
    }
    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Level: " << level() << endl;
    }
};

Course *bestCourse(Course**courses, int n){
    int max = 0;
    Course* memptr;
    for(int i = 0; i < n; i++){
        if(courses[i]->level() > max){
            max = courses[i]->level();
            memptr = courses[i];
        }
    }
    return memptr;
}

using namespace std;
int main()
{
    int choice;
    cin>>choice;
    if(choice==1)
    {
        char name[50];
        int maxStudents;
        cin>>name>>maxStudents;
        RegularCourse regularCourse(name, maxStudents);
        cout<<"--- Testing RegularCourse class ---"<<endl;
        regularCourse.displayInfo();
    }
    else if(choice==2)
    {
        char name[50];
        int numTeachers;
        cin>>name>>numTeachers;
        SpecialCourse specialCourse(name, numTeachers);
        cout<<"--- Testing SpecialCourse class ---"<<endl;
        specialCourse.displayInfo();
    }
    else if(choice==3)
    {
        char name[50];
        int maxStudents, numTeachers;
        cin>>name>>maxStudents>>numTeachers;
        RSCourse rsCourse(name, maxStudents, numTeachers);
        cout<<"--- Testing RSCourse class ---"<<endl;
        rsCourse.displayInfo();
    }
    else if(choice==4)
    {
        Course **c = new Course *[5];
        for(int i=0; i<5; i++)
        {
            if(i%2==0)
            {
                char name[50];
                int numTeachers;
                cin>>name>>numTeachers;
                c[i]=new SpecialCourse(name, numTeachers);
            }
            else {
                char name[50];
                int maxStudents;
                cin>>name>>maxStudents;
                c[i]=new RegularCourse(name, maxStudents);
            }
            c[i]->displayInfo();
            cout<<endl;
        }
        cout<<"Best Course:"<<endl;
        bestCourse(c, 5)->displayInfo();
    }
    return 0;
}
