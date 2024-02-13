/*
 * Треба да се напише класа FoodItem која што ги има овие две чисти виртуелни функции:

getPrice() - цена на храната
getTime() - време за подготвување на храната
Исто така, треба класата да ги има следните информации:

type (динамички алоцирана низа од карактери) - типот на храната
num(int)- количина на храната
Понатаму, треба да креирате 2 подкласи на FoodItem наречени:

Pizza
Steak
Класата Pizza треба да ги има овие информации:

dough (динамички алоцирана низа од карактери) - какво тесто е пицата
Цана на едно тесто:
- "wholeWheat" : 250
- "glutenFree" : 350

Време на правење на пица е 25 минути, независно од колку пици има.
Ако се прават n пици потребна е n количина на тесто.
Класата Steak треба да ги има овие информации:

bool cooked (дали е well done или medium rare)
Време на правење, независно колку steaks има:

-  well done : 20 min

-  medium rare: 15 min

Цена на еден стек е 1300 ден.



Треба исто така да напишете глобална функција:

getMaxFoodItem(FoodItem *pItem[], int n) , која што ќе враќа покажувач до најскапиот FoodItem

Не ја променувајте main функцијата!
 */

#include <iostream>
#include <cstring>

class FoodItem{
protected:
    char* TypeofFood;
    int Size;
public:
    FoodItem(){
        TypeofFood = new char [0];
        Size = 0;
    }
    FoodItem(char* type, int size){
        this->TypeofFood = new char[strlen(type) +1];
        strcpy(this->TypeofFood, type);
        this->Size = size;
    }
    char* getType(){
        return TypeofFood;
    }
    virtual int getPrice() = 0;
    virtual int getTime() = 0;
};

class Pizza : public FoodItem{
private:
    char* doughType;
public:
    Pizza(){
        doughType = new char [0];
    }
    Pizza(char* type, int size, char* dough) : FoodItem(type,size){
        this->doughType = new char[strlen(dough) +1];
        strcpy(this->doughType,dough);
    }

    int getPrice() override{
        if(!strcmp(doughType,"wholeWheat")){
            return Size * 250;
        }
        else if (!strcmp(doughType,"glutenFree")){
            return Size * 350;
        }
        else return 0;
    }

    int getTime(){
        return 25;
    }
};
class Steak : public FoodItem{
private:
    bool cooked; // well done == true, medium rare == false;
public:
    Steak(char* type, int size, bool cooked = false) : FoodItem(type,size){
        this->cooked = cooked;
    }

    int getPrice() override{
        return Size * 1300;
    }

    int getTime(){
        if(cooked){
            return 20;
        }
        else{
            return 15;
        }
    }
};

FoodItem* getMaxFoodItem(FoodItem *pItem[], int n){
    int max = 0;
    FoodItem* maxPtr = pItem[0];
    for(int i = 0; i < n; i++){
        if(pItem[i]->getPrice() > max){
            max = pItem[i]->getPrice();
            maxPtr = pItem[i];
        }
    }
    return maxPtr;
}

using namespace std;

int main() {
    FoodItem *p;
    int n;
    cin>>n;

    char type[30];
    char dough[30];
    bool cooked;
    int size;

    FoodItem *items[n];

    for (int i = 0; i <n; ++i) {
        cin>>type;
        cin>>size;


        if(strcmp(type, "pizza")==0 ) {
            cin>>dough;
            items[i] = new Pizza(type, size, dough);
        }else{
            cin>>cooked;
            items[i] = new Steak(type, size, cooked);
        }


    }

    FoodItem *it = getMaxFoodItem(items, n);
    cout<<"Type: "<<it->getType()<<endl;
    cout<<"The max price is: "<<it->getPrice()<<endl;
    cout<<"Time to cook: "<<it->getTime();
    return 0;
}