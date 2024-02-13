/*
 * Да се имплементира класа Race во која се чува:

името на градот во кој се изведува(низа од најмногу 40 знаци)
година на одржување(цел број)
месец на одржување(цел број)
најдобро време во секунди (децимален број)
должина во km (децимален број)
За оваа класа да се имплементираат следните методи:

функција heaviness() што ја пресметува тежината на трката според следната формула:
     (најдобро време во секунди / должина во km)
operator<< за печатење на трката во формат:
[ Град Месец Година Тежина ]

Да се имплементира класа CarRace во која покрај основните информации за трката дополнително се чува:

низа од најдобри времиња на припреми (динамички резервирана низа од децимални броеви)
бројот на најдобри времиња (цел број)
број на кругови (цел број)
Во оваа класа да се препокрие соодветно функцијата heaviness() така што на
 основната тежина од трката ќе се додаде и просекот од најдобрите времиња од
 припремите помножен по CAR_COEF коефициентот. CAR_COEF коефициентот е ист за сите CAR_COEF трки и
 може да се промени од страна на комисијата(иницијално е 0.3). Дополнително, доколку бројот на кругови е поголем од 15,
 тежината се зголемува за 10%. За оваа класа да се обезбеди:

оператор +=за додавање ново време од припреми во динамички алоцираната низа од најдобри времиња на припреми.
 Ако се направи обид да се додаде време што е помало од 10 да се фрли исклучок (објект од класата InvalidTimeException).
 Справувањето со исклучокот треба да се реализира во главната функција main каде што е потребно.
 Ако бил генериран исклучок треба да се отпечати соодветна порака за грешка "Vremeto ne e validno",
 а новото време од припреми нема да се внесе во низата.
For example:

Input	Result
1
Paris
2011
5
1986.3
49.6
Jerez
2017
6
41.53
4.429
24
5
49.2
39.11
42.4
54.3
44.4
===== Testiranje na klasite ======
Paris 5.2011 40.0464
Jerez 6.2017 25.4556

 Mala greska vo decimali na tezina
 */

#include <iostream>
#include <cstring>
using namespace std;
class InvalidTimeException{
    char msg[64];
public:
    InvalidTimeException(char* msg){
        strcpy(this->msg,msg);
    }
    void print(){
        cout << msg << endl;
    }
    //TODO
};
class Race{
protected:
    char cityName[40];
    int yearHeld;
    int monthHeld;
    float bestTime;
    float lengthKM;
public:
    Race() = default;
    Race(const Race& other){
        strcpy(this->cityName,other.cityName);
        this->yearHeld = other.yearHeld;
        this->monthHeld = other.monthHeld;
        this->bestTime = other.bestTime;
        this->lengthKM = other.lengthKM;
    }
    //  Race t(city, year, month, bestTime, length);
    Race(char* city, int year, int month, float bestTime, float length){
        strcpy(this->cityName,city);
        this->yearHeld = year;
        this->monthHeld = month;
        this->bestTime = bestTime;
        this->lengthKM = length;
    }
    virtual float heaviness(){
        return (float)bestTime/lengthKM;
    }
    friend ostream& operator << (ostream& os, Race& R);
};

ostream& operator << (ostream& os, Race& R){
    os << R.cityName << " " << R.monthHeld << "." << R.yearHeld << " " << R.heaviness() << endl;
    return os;
}
class CarRace : public Race{
private:
    float* bestTimes;
    int numBT;
    int laps;
    static float CAR_COEF;
public:
    CarRace() : Race() {
        numBT = 0;
        bestTimes = new float[numBT];
    }
    //CarRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
    CarRace(char* city, int year, int month, float bestTime, float length,float* bestTimes,int numbt,int laps) : Race (city, year, month, bestTime, length){
        this->laps = laps;
        this -> numBT = numbt;
        this->bestTimes = new float[numbt];
        for(int i = 0; i < numbt; i++){
            this->bestTimes[i] = bestTimes[i];
        }
    }
    CarRace(char* city, int year, int month, float bestTime, float length) : Race (city, year, month, bestTime, length){
        numBT = 0;
        bestTimes = new float[numBT];
    }

    float heaviness() override{
        float total = 0;
        for(int i = 0; i < numBT; i++){
            total += bestTimes[i];
        }
        float newtotal = total/numBT;
        newtotal *= CAR_COEF;

        if(laps > 15){
            newtotal += newtotal * 0.1;
        }

        return Race::heaviness() + newtotal;
    }
    CarRace& operator += (float newtime){
        if(newtime < 10){
            throw InvalidTimeException("Vremeto ne e validno");
        }
        float* temp = new float[numBT +1];
        for(int i = 0; i < numBT; i++){
            temp[i] = bestTimes[i];
        }
        temp[numBT] = newtime;
        delete [] bestTimes;
        bestTimes = temp;
        numBT++;
        return *this;
    }

    void setNumberLaps(int a){
        laps = a;
    }

    static void setKoeficient(float a){
        CAR_COEF = a;
    }

private:
    void copy(const CarRace& other){
        Race(Race(other));
        this->numBT = other.numBT;
        this->bestTimes = new float [numBT];

    }
};
float CarRace::CAR_COEF = 0.3;
int main(){
    int testCase;
    cin >> testCase;
    char city[50];
    int year;
    int month;
    float bestTime;
    float length;
    float bestTimes[50];
    int n;
    int m;
    int izbor;
    int numberLaps;

    if (testCase == 1){
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        Race t(city, year, month, bestTime, length);
        cout<<t;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        cin>>n;
        for (int j = 0; j < n; j++)
            cin >> bestTimes[j];

        CarRace mgt(city, year, month, bestTime, length, bestTimes, n, numberLaps);
        cout << mgt;
        CarRace mgt2;
    }
    if (testCase == 2){
        cout << "===== Testiranje na operatorot += ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        // dodavanje novo najdobro vreme za prvata CarRace
        float best;
        cin >> best;
        int flag = 1;
        for (int i = 0; i < m; i++){
            CarRace* nn = dynamic_cast<CarRace*>(niza[i]);
            if (nn != 0){
                flag = 0;
                (*nn) += best;
                break;
            }
        }


        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }
    if (testCase == 3){
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> city;
        cin >> year;
        cin >> month;
        cin >> bestTime;
        cin>>length;
        cin>>numberLaps;
        CarRace mgt(city, year, month, bestTime, length);
        mgt.setNumberLaps(numberLaps);
        float vreme1,vreme2;
        cin>>vreme1>>vreme2;
        try{
            mgt+=vreme1;
            mgt+=vreme2;
        }
        catch(InvalidTimeException e)
        {
            e.print();
        }
        cout<<mgt;
    }

    if (testCase == 5){
        cout << "===== Testiranje na static clenovi ======" << endl;
        Race **niza;
        cin >> m;
        niza = new Race *[m];
        for (int i = 0; i<m; i++){
            cin >> izbor;
            cin >> city;
            cin >> year;
            cin >> month;
            cin >> bestTime;
            cin >>length;
            if (izbor == 1){
                niza[i] = new Race(city, year, month, bestTime, length);
            }
            else{
                cin>>numberLaps;
                cin>>n;
                for (int j = 0; j < n; j++)
                    cin >> bestTimes[j];
                niza[i] = new CarRace(city, year, month, bestTime, length, bestTimes, n, numberLaps);
            }
        }
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];

        CarRace::setKoeficient(0.7);
        // pecatenje na site Trki
        cout << "\nLista na site Trki:\n";
        for (int i = 0; i < m; i++)
            cout << *niza[i];
    }



    return 0;
}