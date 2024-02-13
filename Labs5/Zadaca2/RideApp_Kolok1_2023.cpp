/*
 * За потребите на апликации за (такси) превоз како што е Uber, потребно е да се имплементира модул за управување со возачите и превозите.

Да се имплементира класа Vehicle во која ќе се чуваат информации за:

Регистрацискиот број на возилото (низа од 8 знаци)
Име на возачот (динамички алоцирана низа од знаци)
Локација - реон во кој се наоѓа возилото моментално (цел број)
Максимален број на патници кои може да се возат во едно патување (цел број)
Број на извозени километри на возилото (децимален број, иницијално нула)
За класата да се имплементираат потребните конструктори, оператор = и методи за да функционира решението.
 (10 поени). Дополнително за класата да се имплементира метод void print() за печатење на информациите за возилото. (5 поени)

Да се имплементира класа RideApp во која ќе се чуваат информации за:

Име на апликацијата (низа од најмногу 20 знаци)
Листа на возила кои возат преку ова апликација (динимички алоцирана низа од објекти од класата Vehicle, иницијално без елементи)
Број на возила (број на елементи во низата од возачи - цел број, иницијално е 0)
За класата да се имплементираат потребните конструктори и методи со цел да функционира решението.
 (5 поени) Дополнително во класата да се имплементираат:

метод void signUpVehicle (const Vehicle & vehicle) - за додавање ново возило во апликацијата. (10 поени)
 Едно возило смее само еднаш да фигурира во апликацијата, па да не се дозволи додавање на возило со веќе
 постоечки број на регистрација. (5 поени)
метод void addRide (int area, int passengers, int distanceKm) - за доделување на превоз на возило коe е
 најблиску до реонот area и коe има можност да изврши превоз на најмалку passenger број на патници. При доделување на превоз на
 возило важат следните правила:

Просторот на кој функционира апликацијата е поделен на 10 соседни реони. Пример доколку патниците се наоѓаат во реон 5,
 прво се проверува дали има достапно возило во самиот тој реон (5), па потоа дали има возила во првите соседни реони (4 и 6),
 па во вторите соседни реони (3 и 7) итн.
Доколку има повеќе слободни возила во реонот што е најблиску до посакуваниот реон, се избира возилото кое има извозено најмалку километри до сега.
Откако превозот е доделен на возилото, се менува неговата локација на дестинацискиот реон (area) и се зголемува бројот на извозени километри
 со бројот на километри на превозот (distanceKm). (15 поени)
метод void print()- за печатење на информации за сите возила кои работат за апликацијата (формат во тест примери). (10 поени)
Објаснување на вториот тест пример:

Апликацијата има 4 возила управувани од Стефан (лоциран во реон 2, капацитет 3), Влатко (лоциран во реон 3, капацитет 5),
 Стојменски (лоциран во реон 8, капацитет 2) и Тенев (лоциран во реон 1, капацитет 6).

2 4 3

3 4 4

2 2 5


8 3 10

Првото возење е побарано за во реон 2 и е потребно возило со најмалку 4 места. Од 4-те возила,
 2 имаат капацитет од најмалку 4 места (Влатко и Тенев). Најблиску е Влатко (оддалечен 1 реон),
 па ова возење му се доделува на него. Сега неговата локација од 3 се менува на 2 и му се зголемува бројот на извозени километри од 0 на 3 (+3).

Второто возење е побарано за во реон 3 и е потребно возило со најмалку 4 места. Од 4-те возила,
 2 имаат капацитет од најмалку 4 места (Влатко и Тенев). Најблиску е Влатко (оддалечен 1 реон),
 па ова возење му се доделува на него. Сега неговата локација од 2 се менува на 3 и му се зголемува бројот на извозени километри од 3 на 7 (+4).

Третото возење е побарано за во реон 2 и е потребно возило со најмалку 2 места. Сите 4 возила го
 исполнуваат овој услов. Најблиску е Стефан (оддалечен 0 реони), па ова возење му се доделува на него.
 Сега неговата локација се менува од 3 во 2 и му се зголемува бројот на извозени километри од 0 на 5 (+5).

Четвртото возење е побарано за во реон 8 и е потребно возило со најмалку 3 места. Од 4-те возила, 3
 имаат капацитет од најмалку 3 места (Стефан, Влатко и Тенев). Најблиску е Влатко (оддалечен 5 реони),
 па ова возење му се доделува на него. Сега неговата локација се менува од 3 во 8 и му се зголемува бројот на
 извозени километри од 7 на 17 (+10).



For example:

Input	Result
5
Uber
4
NE1234SA Stefan 2 3
SN1234VS Vlatko 3 5
SK1234AS Stojmenski 8 2
SU1234AT Tenev 1 6
RideApp signUpVehicle test
Uber
ID: NE1234SA Driver's name: Stefan Passenger capacity: 3 Location: 2 kms driven: 0
ID: SN1234VS Driver's name: Vlatko Passenger capacity: 5 Location: 3 kms driven: 0
ID: SK1234AS Driver's name: Stojmenski Passenger capacity: 2 Location: 8 kms driven: 0
ID: SU1234AT Driver's name: Tenev Passenger capacity: 6 Location: 1 kms driven: 0
6
Uber
4
NE1234SA Stefan 2 3
SN1234VS Vlatko 3 5
SK1234AS Stojmenski 8 2
SU1234AT Tenev 1 6
4
2 4 3
3 4 4
2 2 5
8 3 10
RideApp addRide test
Uber
ID: NE1234SA Driver's name: Stefan Passenger capacity: 3 Location: 2 kms driven: 5
ID: SN1234VS Driver's name: Vlatko Passenger capacity: 5 Location: 8 kms driven: 17
ID: SK1234AS Driver's name: Stojmenski Passenger capacity: 2 Location: 8 kms driven: 0
ID: SU1234AT Driver's name: Tenev Passenger capacity: 6 Location: 1 kms driven: 0
 */


#include<iostream>
#include<cstring>
using namespace std;

class Vehicle {
    char ID [9];
    char * name;
    int location;
    int capacity;
    int kms;

    void copy (const Vehicle & other){
        this->location = other.location;
        this->kms = other.kms;
        this->capacity = other.capacity;
        strcpy(this->ID, other.ID);
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
public:
    Vehicle(char *id = "", char *name = "", int location = 0, int capacity = 0, int kms = 0) : location(location),
                                                                                               capacity(capacity), kms(kms) {
        strcpy(this->ID, id);
        this->name = new char [strlen(name)+1];
        strcpy(this->name, name);
    }

    Vehicle (const Vehicle & other){
        copy (other);
    }

    Vehicle &operator = (const Vehicle & other){
        if (this!=&other){
            delete [] name;
            copy(other);
        }
        return *this;
    }

    ~Vehicle() {
        delete [] name;
    }

    void print () {
        cout << "ID: " << ID << " Driver's name: " <<
        name << " Passenger capacity: " << capacity <<
        " Location: " << location << " kms driven: " << kms << endl;
    }

    bool isSame(const Vehicle &vehicle) {
        return strcmp(this->ID, vehicle.ID)==0;
    }

    int distance (int area) const{
        return abs(this->location - area);
    }

    bool compare (Vehicle & other, int area) const {
        if (this->distance(area) < other.distance(area)){
            return true;
        } else if (this->distance(area) == other.distance(area)) {
            return this->kms < other.kms;
        } else {
            return false;
        }
    }

    friend class RideApp;

    void setLocation(int area) {
        this->location = area;
    }

    void addKms(int distance) {
        this->kms += distance;
    }
};

class RideApp {
private:
    char name [50];
    Vehicle * vehicles;
    int count;
public:
    RideApp(char * name = "") {
        strcpy(this->name, name);
        count = 0;
        this->vehicles = new Vehicle [0];
    }

    void signUpVehicle (const Vehicle & vehicle) {
        for (int i = 0; i < count; ++i) {
            if (vehicles[i].isSame(vehicle)) {
                return;
            }
        }

        Vehicle *tmp = new Vehicle[count + 1];
        for (int i = 0; i < count; ++i) {
            tmp[i] = vehicles[i];
        }
        tmp[count++] = vehicle;
        delete[] vehicles;
        vehicles = tmp;
    }

    void addRide (int area, int passengers, int distanceKm) {
        int idx = -1;
        for (int i=0;i<count;i++){
            if (vehicles[i].capacity >= passengers){
                if (idx == -1 || vehicles[i].compare(vehicles[idx], area)){
                    idx = i;
                }
            }
        }

        vehicles[idx].setLocation(area);
        vehicles[idx].addKms(distanceKm);
    }

    void print (){
        cout << name << endl;
        if (count == 0) {
            cout << "EMPTY" << endl;
        }
        for (int i = 0; i < count; ++i) {
            vehicles[i].print();
        }
    }
};

int main () {
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle("NE1234SA", "Stefan", 5, 4);
        vehicle.print();
        cout << "CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR Vehicle" << endl;
        Vehicle vehicle = Vehicle("NE1234SA", "Stefan", 5, 4);
        vehicle.print();
        cout << "COPY-CONSTRUCTOR Vehicle OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle" << endl;
        Vehicle vehicle;
        Vehicle vehicle2("NE1234SA", "Stefan", 5, 4);
        vehicle = vehicle2;
        vehicle.print();
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = Vehicle OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR RideApp" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        app.print();
        cout << "CONSTRUCTOR RideApp OK" << endl;
    } else if (testCase == 5) {
        cout << "RideApp signUpVehicle test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[9];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app.signUpVehicle(Vehicle(ID, name, location, capacity));
        }
        app.print();
    } else if (testCase == 6) {
        cout << "RideApp addRide test" << endl;
        char appName[50];
        cin >> appName;
        RideApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        int capacity;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location >> capacity;
            app.signUpVehicle(Vehicle(ID, name, location, capacity));
        }
        cin >> n;
        for (int i=0;i<n;i++){
            int area, passengers, kms;
            cin >> area >> passengers >> kms;
            app.addRide(area, passengers, kms);
        }

        app.print();
    }
    return 0;
}
