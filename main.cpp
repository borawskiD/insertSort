#include <iostream>

/* funkcja do wyświetlania zawartości tablicy,
 * będę jej używał zamiast powtarzania po kilka razy tej samej pętli
 * funkcja jest typu void, jako argumenty przyjmuje tablice typu int
 * oraz zmienna odpowiadajaca za rozmiar (size, typ int).*/
void arrayDisplayer(int tab [], int size){
    for (int i = 0; i<size; i++){
        std::cout<<tab[i] << " ";
    }
}
/* Algorytm sortowania przez wybieranie prezentuje nieco odmienne podejście do tematu - zaczynamy przeszukiwanie tablicy
od końca, i z każdą iteracją pętli zewnętrznej zwiększamy o jeden zasięg działania pętli wewnętrznej, która przeszukuje
elementy tablicy od elementu na którym znajduje się pętla zewnętrzna do końca. W skrócie, algorytm działa w taki sposób,
że zajmuje się elementami od punktu w którym jest aktualnie pętla (w tym przypadku od elementu którego indeksem jest
zmienna j), do końca, szukając elementu tablicy w tym zakresie który jest większy (!) od elementu badanego pętlą zewnętrzną.
Jeśli znajdziemy taki punkt, to wstawiamy nasz element o indeksie j przed większy punkt o indeksie i (lub przed końcem).
Jeśli dojdziemy do końca tablicy, zmniejszamy j o jeden i zabawa rozpoczyna się od nowa. */
void sort(int tab [], int n){
    //wyświetlam stan początkowy
    std::cout<<"Dane wejściowe: " <<std::endl;
    arrayDisplayer(tab, n);
    std::cout<<std::endl;
    std::cout<<std::endl;
    /*definiuje zmienną pomocniczą, opcjonalną - służy jako licznik iteracji
    zmieniłem trochę output w porównaniu do poprzednich - nie wyswietlam za
    każdym razem stanu tablicy przed wykonaniem pętli, trochę za mało się dzieje
    żeby było to konieczne. */
    int counter = 0;
    /*Definiuję pętlę zewnętrzną, zaczynam od punktu j = n-2, ponieważ jakbym zaczął
    od punktu j = n-1, to byłaby to po prostu pusta iteracja (pętla wewnętrzna nie miałaby sensu).
    Pętla działa dekrementując się do 0, tak żeby przeanalizować każdy element tablicy.*/
    for (int j = n-2; j>= 0; j--){
        //definiuję zmienną pomocniczą, żeby łatwiej było porównywać
        int temp = tab[j];
        /* wartość i będzie o jeden większa od wartości j, również dlatego j = n-2, w przeciwnym wypadku pierwsze
        wykonanie pętli nie miałoby żadnego sensu */
        int i = j +1;
        /* pętla while (wyżej nazywana pętlą wewnętrzną), działająca w bardzo intuicyjny sposób; wykonujemy przeszukania
        wtedy i tylko wtedy, gdy i jest mniejsze od n ORAZ zmienna temp jest większa od zmiennej tab[i]; */
        while (i < n && temp > tab[i]){
            /* przesuwanie naszego elementu o indeksie j (robienie mu miejsca) w tablicy przesuwając elementy w lewo
            o 1 aż do chwili gdy pętla się urwie (znajdziemy element większy bądź dojdziemy do końca [nasz element będzie
            największy w zakresie]) */
            tab[i-1] = tab[i];
            i++;
        }
        /* jeśli któryś z tych warunków przestaje być spełniony, następuje przypisanie do wartości temp
            elementu tab pod indeksem [i-1]
         */
        tab[i-1] = temp;
        //później już tylko inkrementacja licznika pętli i wyświetlanie wyników pośrednich, a dalej końcowego.
        counter++;
        std::cout<<"Tablica po " << counter << " iteracji algorytmu sortowania przez wybieranie:";
        std::cout<<std::endl;
        arrayDisplayer(tab, n);
        std::cout<<std::endl;
        std::cout<<"---"<<std::endl;
    }
    std::cout<<"Ostateczny wynik dzialania algorytmu: "<<std::endl;
    arrayDisplayer(tab,n);
}
int main() {
    int n; //deklaracja zmiennej przechowujacej rozmiar tablicy
    std::cout<<"Podaj rozmiar tablicy: ";
    std::cin >> n; //pobieranie rozmiaru tablicy od uzytkownika
    int tab[n]; //deklaracja tablicy o rozmiarze n
    std::cout<<"Wprowadz elementy tablicy: ";
    /* prosta petla pozwalajaca na umieszczenie elementow  podanych przez
     * uzytkownika do tablicy; petla konczy się na n-1, ponieważ zaczynamy iteracje
     * od 0. */
    for (int i = 0; i<n; i++){
        std::cin >> tab[i];
    }
    //wywołanie funkcji odpowiadajacej za sortowanie przez wybieranie
    sort(tab,n);
    return 0;
}

/* Dominik Borawski
 * Grupa A1 215IC
 * Sortowanie przez wybieranie
 */

/*
Podaj rozmiar tablicy: 10
Wprowadz elementy tablicy: 0 3 2 9 6 4 7 1 8 5
Dane wejściowe:
0 3 2 9 6 4 7 1 8 5

Tablica po 1 iteracji algorytmu sortowania przez wybieranie:
0 3 2 9 6 4 7 1 5 8
---
Tablica po 2 iteracji algorytmu sortowania przez wybieranie:
0 3 2 9 6 4 7 1 5 8
---
Tablica po 3 iteracji algorytmu sortowania przez wybieranie:
0 3 2 9 6 4 1 5 7 8
---
Tablica po 4 iteracji algorytmu sortowania przez wybieranie:
0 3 2 9 6 1 4 5 7 8
---
Tablica po 5 iteracji algorytmu sortowania przez wybieranie:
0 3 2 9 1 4 5 6 7 8
---
Tablica po 6 iteracji algorytmu sortowania przez wybieranie:
0 3 2 1 4 5 6 7 8 9
---
Tablica po 7 iteracji algorytmu sortowania przez wybieranie:
0 3 1 2 4 5 6 7 8 9
---
Tablica po 8 iteracji algorytmu sortowania przez wybieranie:
0 1 2 3 4 5 6 7 8 9
---
Tablica po 9 iteracji algorytmu sortowania przez wybieranie:
0 1 2 3 4 5 6 7 8 9
---
Ostateczny wynik dzialania algorytmu:
0 1 2 3 4 5 6 7 8 9

 */