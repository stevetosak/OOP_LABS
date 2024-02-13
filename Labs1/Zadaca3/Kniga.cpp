/*
 * Во програмскиот јазик C да се креира структура Книга за која се чува името на книгата (низа од карактери),
 * ISBN (низа од карактери), број на луѓе кои ја имаат прочитано книгата и рејтинг на книгата.

Потоа да се дефинира структура Автор за која се чува името на авторот (низа од карактери), презиме (низа од карактери),
 број на книги што ги има напишано и низа од книги што ги има напишано.

Да се надополни main функцијата така што ќе се прочитаат n автори заедно со книгите што ги имаат напишано.

Потребно е да се креираат две функции:

- void mostPopularAuthor(author authors[100], int n) која на екран ќе испечати Most popular author: ИМЕ

- void mostPopularBookByAuthor(author authors[100], int n) која на екран ќе ја испечати најпопуларната книга на авторот
 кој има напишано најмалку книги во формат Author: ИМЕ ПРЕЗИМЕ, Most popular book: ИМЕ, ISBN на книгата

Напомена: најпопуларна книга е онаа со најголем рејтинг, најпопуларен автор е оној чии книги ги прочитале најголем број луѓе
For example:

Input	Result
3
J.K
Rowling
3
Stone
ISBN12345
5000
9.3
Secrets
ISBN67890
4000
8.8
Azkaban
ISBN11121
333
9.5
George
Martin
1
Thrones
ISBN56565
1500
8.5
J.R.R
Tolkien
2
Hobbit
ISBN121212
200
5.3
Rings
ISBN32363
3500
2.2
Most popular author: J.K Rowling
Author: George Martin, Most popular book: Thrones, ISBN56565

 */


#include <stdio.h>
typedef struct{
    char ime[50];
    char ISBN[50];
    int procitano;
    float rating;
}Kniga;

typedef struct{
    char ime[30];
    char prezime[30];
    int napisani_knigi;
    Kniga knigi[20];
}Author;

void mostPopularAuthor(Author authors[100], int n){
    int max = 0,sum;
    int mem;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < authors[i].napisani_knigi; j++){
            sum += authors[i].knigi[j].procitano;
        }
        if(sum > max){
            max = sum;
            mem = i;
        }
    }

    printf("Most popular author: %s %s\n",authors[mem].ime,authors[mem].prezime);
}
void mostPopularBookByAuthor(Author authors[100], int n){
    //int min = authors[0].napisani_knigi;
    int mem_avtor;
    int min = 100000;

    for(int i = 0; i < n; i++){
        if(authors[i].napisani_knigi < min){
            min = authors[i].napisani_knigi;
            mem_avtor = i;
        }
    }

    float max = 0;
    int mem_kniga;

    for(int i = 0; i < authors[mem_avtor].napisani_knigi; i++){
        if(authors[mem_avtor].knigi[i].rating > max){
            max = authors[mem_avtor].knigi[i].rating;
            mem_kniga = i;
        }
    }

    printf("Author: %s %s, Most popular book: %s, %s", authors[mem_avtor].ime,
           authors[mem_avtor].prezime, authors[mem_avtor].knigi[mem_kniga].ime,
           authors[mem_avtor].knigi[mem_kniga].ISBN);
}
int main()
{
    int n;
    scanf("%d", &n);
    Author authors[100];
    //dopolni
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", authors[i].ime, authors[i].prezime, &authors[i].napisani_knigi);

        for(int j = 0; j < authors[i].napisani_knigi; j++){
            scanf("%s %s %d %f",authors[i].knigi[j].ime,authors[i].knigi[j].ISBN,
                  &authors[i].knigi[j].procitano, &authors[i].knigi[j].rating);
        }
    }
    mostPopularAuthor(authors, n);
    mostPopularBookByAuthor(authors, n);
    return 0;
}

