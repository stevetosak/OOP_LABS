/*
 * За програмски јазик да се употреби C.

Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen

For example:

Input	Result
3
1 100 10 0
2 202 20 1
3 10 1 1
2 222
3 11
 */

#include <stdio.h>
typedef struct{
    int id_broj;
    int platena_suma;
    int provizija;
    int isplateno;
}transaction;

int main() {
    int n;
    scanf("%d", &n);

    transaction tr[100];

    int i,flag = 1;

    for(i = 0; i < n; i++){
        scanf("%d %d %d %d",&tr[i].id_broj, &tr[i].platena_suma, &tr[i].provizija, &tr[i].isplateno);
    }

    for(i = 0; i < n; i++){
        if(tr[i].isplateno){
            flag = 0;
            int vk = tr[i].platena_suma + tr[i].provizija;
            printf("%d %d\n",tr[i].id_broj,vk);
        }
    }

    if(flag){
        printf("No credit card transaction");
    }



    return 0;
}