/*
 * Да се дефинира класа MarathonRunner за која ќе се чуваат:

динамички алоцирана низа од карактери за името на тркачот
низа од максимум 40 карактери за земјата во која тркачот живее
просечна брзина на трчање на тркачот на маратоните оваа година (double)
вкупна должина (во километри) на маратоните на кои учествувал тркачот оваа година (double)
вкупно време (во часови) потребно за завршување на маратоните на кои учествувал тркачот оваа година (double)
За потребите на класата да се дефинираат:

default конструктор и конструктор со аргументи
copy constructor и оператор =
деструктор
метод rating() кој го враќа рејтингот на тркачот кој се пресметува како:


((brzina*0.45) + (dolzina*0.3) + (vreme*0.25))
метод print() кој го печати тркачот во следниот формат:

Име - земја

Average speed: просечна брзина на трчање

Total distance: вкупна должина на маратоните на кои учествувал

Тotal time: вкупно време потребно за завршување на маратоните

Rating: рејтинг

Од претходната класа MarathonRunner да се изведе класата EliteMarathonRunner за која дополнително ќе се чуваат и:

просечна брзина на трчање на тркачот EliteInternational маратоните  (double)
вкупна должина (во километри) на EliteInternational маратоните на кои учествувал тркачот  (double)
вкупно време (во часови) потребно за завршување на EliteInternational маратоните на кои учествувал тркачот (double)
За потребите на класата да се дефинираат:

default конструктор
конструктор кој прима објект од MarathonRunner и плус додатните информации (погледни main)
конструктор кој ги прима сите аргументи (погледни main)
copy constructor, оператор =, деструктор
метод eliteRating() кој го враќа рејтингот на тркачот од EliteInternational маратоните и кој се пресметува како:

70% од просечната брзина + 10% од вкупната должина + 30% од вкупното време

Да се препокријат методите:

rating() кој го враќа просекот од обичниот рејтинг на тркачот и неговиот Elite рејтинг
print() кој покрај основните информации за тркачот печати и:

Elite Rating: рејтингот од EliteInternational маратоните

New Rating: просечниот рејтинг


For example:

Input	Result
1
Brigid_Kosgei Kenya 7.5 600.1 10.6
Amane_Beriso Ethiopia 9.2 150.2 61.9
Paula_Radcliffe Great_Britain 20.4 300.6 30.7
Kelvin_Kiptum Kenya 10.2 180.2 80.2
Birhanu_Legese Ethiopia 7.7 150.2 60.6
MARATHON RUNNERS:
=====================================
Brigid_Kosgei - Kenya
Average speed: 7.5
Total distance: 600.1
Total time: 10.6
Rating: 186.055
Amane_Beriso - Ethiopia
Average speed: 9.2
Total distance: 150.2
Total time: 61.9
Rating: 64.675
Paula_Radcliffe - Great_Britain
Average speed: 20.4
Total distance: 300.6
Total time: 30.7
Rating: 107.035
Kelvin_Kiptum - Kenya
Average speed: 10.2
Total distance: 180.2
Total time: 80.2
Rating: 78.7
Birhanu_Legese - Ethiopia
Average speed: 7.7
Total distance: 150.2
Total time: 60.6
Rating: 63.675

 Mala greska vo presmetka na rating ima negde
 */

#include <iostream>
#include <cstring>
using namespace std;
class MarathonRunner{
protected:
    char* name;
    char country[40];
    double avg_run_Speed;
    double total_length;
    double total_time;
    void copy(const MarathonRunner& other){
        this->name = new char [strlen(other.name) +1];
        strcpy(this-> name, other.name);
        strcpy(this->country, other.country);
        avg_run_Speed = other.avg_run_Speed;
        total_length = other.total_length;
        total_time = other.total_time;
    }
public:
    MarathonRunner(){
        name = new char[0];
    }
    MarathonRunner(char* name, char* country, double speed, double length, double time ){
        this->name = new char [strlen(name) +1];
        strcpy(this-> name, name);
        strcpy(this->country, country);
        avg_run_Speed = speed;
        total_length = length;
        total_time = time;
    }
    MarathonRunner(const MarathonRunner& other){
        copy(other);
    }

    MarathonRunner& operator = (const MarathonRunner& other){
        if(this != &other){
            delete [] name;
            copy(other);
            return *this;
        }
        return *this;
    }

    virtual ~MarathonRunner(){
        delete [] name;
    }

    virtual double rating(){
        return ((avg_run_Speed * 0.45) + (total_length * 0.3) + (total_time) * 0.25);
    }

    virtual void print(){
        cout << name << " - " << country << endl;
        cout << "Average speed: " << avg_run_Speed <<endl;
        cout << "Total distance: " << total_length << endl;
        cout << "Total time: " << total_time << endl;
        cout << "Rating: " << rating() << endl;
    }
};

class EliteMarathonRunner : public MarathonRunner{
private:
    double EliteSpeed;
    double EliteDistance;
    double EliteTime;
    void eliteCopy(const EliteMarathonRunner& other){
        this->name = new char [strlen(other.name) +1];
        strcpy(this-> name, other.name);
        strcpy(this->country, other.country);
        avg_run_Speed = other.avg_run_Speed;
        total_length = other.total_length;
        total_time = other.total_time;
        EliteSpeed = other.EliteSpeed;
        EliteTime = other.EliteTime;
        EliteDistance = other.EliteDistance;
    }
public:
    EliteMarathonRunner(){}

    EliteMarathonRunner(MarathonRunner& m, double elitespeed, double elitedistance, double elitetime) : MarathonRunner(m){
        this->EliteSpeed = elitespeed;
        this-> EliteDistance = elitedistance;
        this-> EliteTime = elitetime;
    }
    EliteMarathonRunner(char* name, char* country, double avgspeed, double avglength, double avgtime,
                        double elitespeed, double elitedistance, double elitetime) :
            MarathonRunner(name,country,avgspeed,avglength,avgtime){
        this->EliteSpeed = elitespeed;
        this->EliteDistance = elitedistance;
        this-> EliteTime = elitetime;

    }

    EliteMarathonRunner(const EliteMarathonRunner& other){
        eliteCopy(other);
    }

    EliteMarathonRunner& operator = (const EliteMarathonRunner& other){
        if(this != &other){
            delete [] name;
            eliteCopy(other);
            return *this;
        }
        return *this;
    }

    double eliteRating(){
        return ((EliteSpeed * 0.7) + (EliteDistance * 0.1) + (EliteTime * 0.3));
    }

    double rating(){
        return (MarathonRunner::rating() + eliteRating()) / 2.0;
    }

    void print(){
        MarathonRunner::print();
        cout << "Elite Rating: " << eliteRating() << endl;
        cout << "New Rating: " << rating() << endl;
    }

    ~EliteMarathonRunner(){
    }

};


int main() {

    char name[50];
    char country[40];
    double avgSpeed;
    double distance;
    double time;
    double EliteavgSpeed;
    double Elitedistance;
    double Elitetime;

    MarathonRunner * RUNNERs = new MarathonRunner[5];
    EliteMarathonRunner * elRUNNERs = new EliteMarathonRunner[5];
    int n;
    cin >> n;

    if (n == 1) {

        cout << "MARATHON RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i = 0; i < 5; ++i) {
            cin >> name >> country >> avgSpeed >> distance >> time;
            RUNNERs[i] = MarathonRunner(name,country,avgSpeed,distance,time);
            RUNNERs[i].print();
        }
    }
    else if (n == 2) {

        for (int i=0; i < 5; ++i){
            cin >> name >> country >> avgSpeed >> distance >> time;
            cin >> EliteavgSpeed >> Elitedistance >> Elitetime;
            RUNNERs[i] = MarathonRunner(name,country,avgSpeed,distance,time);
            elRUNNERs[i] = EliteMarathonRunner(RUNNERs[i],EliteavgSpeed,Elitedistance,Elitetime);
        }

        cout << "NBA RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            RUNNERs[i].print();

        cout << "ELITE RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            elRUNNERs[i].print();

    }
    else if (n == 3) {

        for (int i=0; i < 5; ++i){
            cin >> name >> country >> avgSpeed >> distance >> time;
            cin >> EliteavgSpeed >> Elitedistance >> Elitetime;
            elRUNNERs[i] = EliteMarathonRunner(name, country, avgSpeed, distance, time,
                                               EliteavgSpeed,Elitedistance,Elitetime);
        }
        cout << "ELITE RUNNERS:" << endl;
        cout << "=====================================" << endl;
        for (int i=0; i < 5; ++i)
            elRUNNERs[i].print();

    }

    delete [] RUNNERs;
    delete [] elRUNNERs;
}


