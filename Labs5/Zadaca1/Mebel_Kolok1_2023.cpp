/*
 * Во програмскиот јазик C да се креира структура Mebel за опишување на мебел во даден продажен салон. Структурата треба да содржи: (5 поени)

Шифра (низа од 20 знаци)

Цена(реален број)

Тип на мебел(цел број со вредност 1 за канцелариски мебел, 2 за санитарии)

Да се креира структура ProdazenSalon, што содржи: (5 поени)

Име на продажниот салон (низа од 50 знаци)

Достапен мебел(низа од максимум 30 елементи од структурата Mebel)

Број на елементи во низата (цел број)

Да се креира глобална функција print за печатење на информациите за даден продажен салон во следниот формат: (10 поени)

[Ime na prodazniot salon]

[Sifra1] [Cena1] [Tip1]

[Sifra2] [Cena2] [Tip2]

[Sifra3] [Cena3] [Tip3]

...

Да се креира функција najdobra_ponuda, што прима низа од променливи од типот ProdazenSalon, и променлива tipNaMebel. Оваа функција треба да го испечати името на продажниот салон кој нуди најевтин мебел од соодветен тип (доколку tipNaMebel има вредност 1, ќе се испечати името на салонот кој нуди најевтин канцелариски мебел, доколку променливата има вредност 2 ќе се испечати името на салонот со најевтини санитарии). Најевтин мебел во даден продажен салон е мебелот кој има најнска цена. Ако има повеќе такви продажни салони, се печати првиот.(15 поени)

Да се дополни функцијата main (5 поени).
For example:

Input	Result
3
BKmebel 3
M00155 500 1
M00233 1000 2
M00311 800 1
Kare 2
C02322 450 1
A00544 900 2
Nordic 2
B00633 700 1
K00798 950 2
1
BKmebel
M00155 500.00 kancelariski
M00233 1000.00 sanitarii
M00311 800.00 kancelariski
Kare
C02322 450.00 kancelariski
A00544 900.00 sanitarii
Nordic
B00633 700.00 kancelariski
K00798 950.00 sanitarii
Najdobra ponuda nudi salon: Kare
3
MebelVi 3
M001 500 1
M002 1000 2
M003 800 1
Yusk 2
M004 450 1
M005 900 2
Natuzzi 2
M006 700 1
M007 950 2
2
MebelVi
M001 500.00 kancelariski
M002 1000.00 sanitarii
M003 800.00 kancelariski
Yusk
M004 450.00 kancelariski
M005 900.00 sanitarii
Natuzzi
M006 700.00 kancelariski
M007 950.00 sanitarii
Najdobra ponuda nudi salon: Yusk
4
BKmebel 3
M100 1500 1
M101 1200 2
M102 1800 1
MebelVi 2
M103 1100 1
M104 1700 2
Natuzzi 3
M105 1300 1
M106 1600 2
M107 1400 1
NewShop 1
M108 1000 2
1
BKmebel
M100 1500.00 kancelariski
M101 1200.00 sanitarii
M102 1800.00 kancelariski
MebelVi
M103 1100.00 kancelariski
M104 1700.00 sanitarii
Natuzzi
M105 1300.00 kancelariski
M106 1600.00 sanitarii
M107 1400.00 kancelariski
NewShop
M108 1000.00 sanitarii
Najdobra ponuda nudi salon: MebelVi
 */