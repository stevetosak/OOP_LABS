/*
 * Да се напише класа Book во која се чуваат информации за името на книгата (динамички алоцирана низа од знаци), isbn на книгата (динамички алоцирана низа од 5 цели броја) и број на страници (цел број). За класата да се обезбедат set и get методите што се користат и да се преоптоварат следните оператори:

оператор == за споредување на две книги според isbn-от

оператор << за печатење на податоци за книгата во формат Title: наслов ISBN:[x y z k l]

Да се напише класа BorrowABook за библиотека за изнајмување книги  во која се чуваат информација за името на бибилиотеката (низа од 100 знци), низа од книги (динамички алоцирана низа од објекти од класата Book) и број на книги со кој располага (цел број). Во класата BorrowABook да се напише конструктор со еден аргумент за иницијализација на името на библиотеката. При секое додавање на нова книга во библиотеката, динамички алоцираната низа да го зголемува капацитетот за 1 елемент. Во оваа класа да се преоптоварат операторите:

+= за додавање на нова книга во библиотеката и

-= за отстранување на дадена книга од библиотеката (онаа со веќепостоечки ISBN кој се поклопува со ISBN-от на друга книга).

На излез да се отпечатат името на библиотеката и листа на книги што таа ги изнајмува, а чиј број на страници е поголем од 150. Последново да се направи со функција printNumberOfPages(int max) што треба да се дефинира во класата BorrowABook.

Појаснување на main функцијата: Информациите за книгите се читаат од тастатура со операторот +=. Во последниот ред од влезот дадени се информации за книгата која што се внесува грешно бидејќи има ист isbn како и друга книга. Потребно е истата да биде избришана.
!!! ДА НЕ СЕ ПРАВАТ ПРОМЕНИ ВО MAIN() ФУНКЦИЈАТА !!!

For example:

Input	Result
3
Hamlet 4 5 6 7 4 200
Macbeth 2 3 4 1 2 120
Dracula 1 2 1 1 1 130
Rebecca 1 2 1 1 1 100
FINKI-Library
Title: Hamlet ISBN: [ 4 5 6 7 4 ]
 */

/// Do NOT edit the main() function
#include <iostream>
#include <cstring>
using namespace std;
class Book{
private:
    char* name;
    int* ISBN;
    int no_Pages;
private:
    void copy(const Book& other){
        this-> name = new char [strlen(other.name) +1];
        this->ISBN = new int [5];
        strcpy(this-> name, other.name);
        for(int i = 0; i < 5; i++){
            this-> ISBN[i] = other.ISBN[i];
        }
        this->no_Pages = other.no_Pages;
    }
public:
    Book(){
        name = new char [0];
        ISBN = new int [0];
    }

    Book(char* name,int* isbn, int pages){
        this-> name = new char [strlen(name) +1];
        this->ISBN = new int [5];
        strcpy(this-> name, name);
        for(int i = 0; i < 5; i++){
            this-> ISBN[i] = isbn[i];
        }
        this->no_Pages = pages;
    }

    Book(const Book& other){
        copy(other);
    }

    Book& operator = (const Book& other){
        if(this != &other){
            delete [] name;
            delete [] ISBN;
            copy(other);
            return *this;
        }
        return *this;
    }

    bool operator == (const Book& other){
        for(int i = 0; i < 5; i++){
            if(ISBN[i] != other.ISBN[i]){
                return false;
            }
        }
        return true;
    }

    void printISBN(){
        for(int i = 0; i < 5; i++){
            cout << " " <<ISBN[i];
        }
    }

    friend ostream& operator << (ostream& os, Book& p);
    friend class BorrowABook;
};

class BorrowABook{
private:
    char name[100];
    Book* books;
    int no_books;
public:
    BorrowABook(char* name){
        strcpy(this-> name, name);
        no_books = 0;
        books = new Book [no_books];
    }


    void addBook(Book& p){
        Book* temp = new Book [no_books +1];
        for(int i = 0; i < no_books; i++){
            temp[i] = books[i];
        }
        temp[no_books] = p;
        delete [] books;
        books = temp;
        no_books ++;
    }
    void removeBook(Book& p){
        int memID = -1;
        for(int i = 0; i < no_books; i++){
            if(books[i] == p){
                memID = i;
                break;
            }
        }

        if(memID != -1){
            Book* temp = new Book[no_books -1];

            for(int i = 0, j = 0; i < no_books; i++){
                if(i != memID){
                    temp[j++] = books[i];
                }
            }
            delete [] books;
            books = temp;
            no_books --;
        }
        else{
            return;
        }
    }

    BorrowABook& operator += (Book& p){
        addBook(p);
        return* this;
    }
    BorrowABook& operator -= (Book& p){
        removeBook(p);
        return* this;
    }

    void printNumberOfPages(int max){
        cout << name << endl;

        for(int i = 0; i < no_books; i++){
            if(books[i].no_Pages > max){
                cout << books[i];
            }
        }
    }

};


ostream& operator << (ostream& os, Book& p){
    os << "Title: " << p.name << " ISBN: [";
    p.printISBN();
    os << " ]" << endl;

    return os;
}
int main()
{
    BorrowABook library("FINKI-Library");
    int n;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        char title[100];
        int isbn[5];
        int pages;

        cin>>title;

        for (int j=0;j<5;j++)
            cin>>isbn[j];

        cin>>pages;

        Book nov=Book(title,isbn,pages);

        //adding a new book
        library+=nov;

    }
    //the book which has the same isbn as some previous one
    char title[100];
    int isbn[5];
    int pages;
    cin>>title;
    for (int i=0;i<5;i++)
        cin>>isbn[i];
    cin>>pages;

    Book greshka=Book(title,isbn,pages);

    //deleting a book
    library-=greshka;

    library.printNumberOfPages(150);

    return 0;
}