/*
 * Да се креира структура Vehicle во која што ќе се чуваат следните податоци:

модел (максимум 100 карактери)
марка (максимум 100 карактери)
година на производство (цел број)
поминати километри (цел број)
Од стандарден влез се внесуваат најпрво број на возила, па потоа возилата со сите нивни податоци по редлоследот даден погоре.

Да се креира функција getNewestVehicle() која што ќе го испечати на екран моделот и марката на возилото што што е најново.
 Доколку постојат повеќе такви возила, да се испечати возилото со помалку поминати километри.

For example:

Input	Result
2
Peugeot
508
2021
1000
Audi
A3
2020
10000
Peugeot 508

 */

// Se koristi C

#include <stdio.h>
typedef struct{
    char model[100];
    char marka[100];
    int godina;
    int kilometri;
}Vehicle;

void getNewestVehicle(Vehicle *tr, int n){
    int newest = tr[0].godina;
    int mem;
    for(int i = 0; i < n; i++){
        if(tr[i].godina > newest){
            newest = tr[i].godina;
            mem = i;
        }
        else if(tr[i].godina == newest){
            if(tr[i].kilometri < tr[mem].kilometri){
                newest = tr[i].godina;
                mem = i;
            }
        }
    }

    printf("%s %s",tr[mem].model, tr[mem].marka);

}

int main()
{
    int n;
    scanf("%d",&n);

    Vehicle vi[20];

    for(int i = 0; i < n; i++){
        scanf("%s %s %d %d", vi[i].model, vi[i].marka,&vi[i].godina,&vi[i].kilometri);
    }

    getNewestVehicle(vi,n);


}