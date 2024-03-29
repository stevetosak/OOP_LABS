/*
 * Да се дефинира класата Kvadrat во која што се чува информација за:

должината на страната а на квадратот (double)
За класата да се дефинираат:

default конструктор
конструктор со аргументи
copy конструктор
double perimetar () што пресметува периметар на квадратот
double plostina () што пресметува плоштина на квадратот
void pecati () што печати информации за квадратот како во тест примерите
Да се имплементира класа Pravoagolnik што наследува од класата Kvadrat. Во неа се чуваат дополнителни информации за:

проширувањето x на двете паралелни страни на квадратот (double)
проширувањето у на другите две паралелни страни (double)
Правоаголникот всушност сега ќе има 2 страни со должина a+x и две страни со должина a+y.

За класата да се дефинираат:

default конструктор
конструктор Pravoagolnik (const Kvadrat &k, double x, double y)
copy конструктор
Да се препокријат трите методи дефинирани погоре за класата Kvadrat.

Напомени:

Ако x и y се исти, тогаш формата не е правоаголник туку е повторно квадрат. Во тој случај pecati() се повикува исто како за квадрат.
При препокривање на методите во класата Pravoagolnik мора да има повик кон истоимените методи од класата Kvadrat
For example:

Input	Result
5
4.5
4
10
17.5
8.9
1 2
1.5 2.5
3 4.5
7 7
8 9
2
===Testiranje na klasata Pravoagolnik===
Pravoagolnik so strani: 5.5 i 6.5 ima plostina P=35.75 i perimetar L=24
Pravoagolnik so strani: 5.5 i 6.5 ima plostina P=35.75 i perimetar L=24
Pravoagolnik so strani: 13 i 14.5 ima plostina P=188.5 i perimetar L=55
Kvadrat so dolzina a=24.5 ima plostina P=600.25 i perimetar L=98
Pravoagolnik so strani: 16.9 i 17.9 ima plostina P=302.51 i perimetar L=69.6
 */

#include <iostream>
using namespace std;
class Kvadrat {
protected:
    double a;
    //TODO da se deklariraat promenlivite

public:
    //TODO default konstruktor

    //TODO konstruktor so argumenti
    Kvadrat(double a = 0){
        this->a = a;
    }

    //TODO copy konstruktor
    Kvadrat(const Kvadrat& other){
        this->a = other.a;
    }

    //TODO double perimentar() {}
    virtual double perimetar(){
        return 4 * a;
    }
    //TODO double plostina() {}
    virtual double plostina () {
        return a * a;
    };

    double getA()const{
        return  a;
    }



    //Kvadrat so dolzina a=24.5 ima plostina P=600.25 i perimetar L=98
    //TODO void pecati();
    virtual void pecati(){
        std::cout << "Kvadrat so dolzina a=" << this->a << " ima plostina P=" << plostina()
                  << " i perimetar L=" << perimetar() << std::endl;
    }
};

class Pravoagolnik : public Kvadrat { //da se vmetni nasleduvanjeto
private:
    //deklariranje na promenlivite
    double ax;
    double ay;

public:
    //TODO default konstruktor
    Pravoagolnik(){};


    //TODO konstruktor
    Pravoagolnik (const Kvadrat &k, double x, double y) : Kvadrat(k){
        this->ax = a + x;
        this->ay = a + y;
    }

    //TODO copy konstruktor
    Pravoagolnik(const Pravoagolnik& other){
        this-> ax = other.ax;
        this-> ay = other.ay;
    }

    //TODO prepokrivanje na metodite perimetar, plostina i pecati od klasata Kvadrat
    double perimetar(){
        return 2 * ax + 2 * ay;
    }
    double plostina(){
        return ax * ay;
    }
    void pecati(){
        if(ax == ay){
            //Kvadrat::pecati();
            std::cout << "Kvadrat so dolzina a=" << ax << " ima plostina P=" << plostina()
                      << " i perimetar L=" << perimetar() << std::endl;
            return;
        }
            //Pravoagolnik so strani: 13 i 14.5 ima plostina P=188.5 i perimetar L=55
        else{
            std::cout << "Pravoagolnik so strani: " << ax <<" i " << ay << " ima plostina P="
                      << plostina() << " i perimetar L=" << perimetar() << std::endl;
        }
    }
};

int main() {
    int n;
    double a,x,y;
    Kvadrat * kvadrati;
    Pravoagolnik * pravoagolnici;

    cin>>n;

    kvadrati = new Kvadrat [n];
    pravoagolnici = new Pravoagolnik [n];

    for (int i=0;i<n;i++){
        cin>>a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i=0;i<n;i++){
        cin>>x>>y;

        pravoagolnici[i]=Pravoagolnik(kvadrati[i],x,y);
    }

    int testCase;
    cin>>testCase;

    if (testCase==1){
        cout<<"===Testiranje na klasata Kvadrat==="<<endl;
        for (int i=0;i<n;i++)
            kvadrati[i].pecati();
    }
    else {
        cout<<"===Testiranje na klasata Pravoagolnik==="<<endl;
        for (int i=0;i<n;i++)
            pravoagolnici[i].pecati();
    }
}