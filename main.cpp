#include <iostream>
#include <cassert>
#include <cmath>

//Zad 5a
void zad_5a_1(int a, int b) {
    for (int i = a; i <= b; ++i) std::cout << i << " ";
}
int sumap(int a, int b){
    int res = 0;
    for (int i = a; i <= b; ++i){
        if (i%2 == 0) {
            res +=i ;
        }
    }
    return res;
}
void test_sumap(){
    assert(sumap(2, 4) == 6);  // 2 + 4 = 6
    assert(sumap(1, 2) == 2);  // 2 (jedyna parzysta liczba)
    assert(sumap(-2, 4) == 4); // -2 + 0 + 2 + 4 = 4
    assert(sumap(0, 0) == 0);  // 0 jest parzyste
    assert(sumap(1, 1) == 0);  // Brak parzystych liczb w tym przedziale
}
double odleglosc(double x1, double x2, double y1, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
void test_odleglosc(){
    // Test dla punktów (0, 0) i (3, 4) - punkty na prostej 3-4-5
    assert(odleglosc(0, 3, 0, 4) == 5.0);

    // Test dla punktów (1, 1) i (4, 5) - również punkty na prostej 3-4-5
    assert(odleglosc(1, 4, 1, 5) == 5.0);

    // Test dla dwóch takich samych punktów (powinien zwrócić odległość 0)
    assert(odleglosc(2, 2, 3, 3) == 0.0);

    // Test dla punktów w odległości 1 jednostki od siebie
    assert(odleglosc(0, 1, 0, 0) == 1.0);

    // Punkty symetryczne względem początku układu współrzędnych
    assert(odleglosc(3, -3, 4, -4) == odleglosc(-3, 3, -4, 4));

    // Test dla punktów, gdzie jedna z wartości x lub y wynosi 0
    assert(odleglosc(0, 3, 0, 0) == 3.0);
    assert(odleglosc(0, 0, 0, 3) == 3.0);
}
//End 5a

//Zad 5b
bool czy_przestepny(int rok){
    return rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0;
}
void test_czy_przestepny(){
    assert(czy_przestepny(2024) == true);
    assert(czy_przestepny(2000) == true);
    assert(czy_przestepny(1900) == false);
    assert(czy_przestepny(2023) == false);
    assert(czy_przestepny(0) == true);
}
int ile_dni_w_roku(int rok){
    return czy_przestepny(rok) ? 366 : 365;
}
void test_ile_dni_w_roku(){
    assert(ile_dni_w_roku(2020) == 366);
    assert(ile_dni_w_roku(2021) == 365);
    assert(ile_dni_w_roku(0) == 366);
    assert(ile_dni_w_roku(1900) == 365);
    assert(ile_dni_w_roku(2000) == 366);
}
int ile_dni_w_miesiacu_if(int rok, int miesiac){
    int res = 0;
    if (miesiac == 1) res = 31;
    if (miesiac == 2) czy_przestepny(rok) ? res =  29: res = 28;
    if (miesiac == 3) res =  31;
    if (miesiac == 4) res =  30;
    if (miesiac == 5) res =  31;
    if (miesiac == 6) res =  30;
    if (miesiac == 7) res =  31;
    if (miesiac == 8) res =  31;
    if (miesiac == 9) res =  30;
    if (miesiac == 10) res = 31;
    if (miesiac == 11) res =  30;
    if (miesiac == 12) res = 31;
    return res;
}
void test_ile_dni_w_miesiacu_if(){
    assert(ile_dni_w_miesiacu_if(2020, 2) == 29);
    assert(ile_dni_w_miesiacu_if(2021, 2) == 28);
    assert(ile_dni_w_miesiacu_if(2022, 1) == 31);
    assert(ile_dni_w_miesiacu_if(2023, 4) == 30);
    assert(ile_dni_w_miesiacu_if(2024, 12) == 31);
}
int ile_dni_w_miesiacu_switch(int rok, int miesiac){
    int res = 0;
    switch(miesiac){
        case 1: res = 31; break;
        case 2: czy_przestepny(rok) ? res = 29 : res = 28; break;
        case 3: res = 31; break;
        case 4: res = 30; break;
        case 5: res = 31; break;
        case 6: res = 30; break;
        case 7: res = 31;
        case 8: break;
        case 9: res = 30; break;
        case 10: res = 31; break;
        case 11: res = 30; break;
        case 12: res = 31; break;
        default: break;
    }
    return res;
}
void test_ile_dni_w_miesiacu_switch(){
    assert(ile_dni_w_miesiacu_switch(2020, 2) == 29);
    assert(ile_dni_w_miesiacu_switch(2021, 2) == 28);
    assert(ile_dni_w_miesiacu_switch(2022, 1) == 31);
    assert(ile_dni_w_miesiacu_switch(2023, 4) == 30);
    assert(ile_dni_w_miesiacu_switch(2024, 12) == 31);
}
int ile_dni_w_miesiacu_array(int rok, int miesiac){
    int dni[12] = {31, czy_przestepny(rok) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dni[miesiac-1];
}
void test_ile_dni_w_miesiacu_array(){
    assert(ile_dni_w_miesiacu_array(2020, 2) == 29);
    assert(ile_dni_w_miesiacu_array(2021, 2) == 28);
    assert(ile_dni_w_miesiacu_array(2022, 1) == 31);
    assert(ile_dni_w_miesiacu_array(2023, 4) == 30);
    assert(ile_dni_w_miesiacu_array(2024, 12) == 31);
}
int ile_dni(int rok, int miesiac, int dzien){
    int dni = -1;

    for (int start = 1900; start < rok; ++start) dni += ile_dni_w_roku(start);

    for (int m = 0; m < miesiac; ++m)
        dni += ile_dni_w_miesiacu_array(rok, m);

    dni+=dzien;

    return dni;
}
//ToDo Sprawdz czemu nie bangla, zrob zadanie 5
void test_ile_dni(){
    assert(ile_dni(2023, 6, 15) == 45092);
    assert(ile_dni(1975, 12, 31) == 27757);
    assert(ile_dni(2024, 2, 29) == 43949);
    assert(ile_dni(2023, 2, 28) == 43853);
}
//End 5b

//Zad 5c
int NWD_2(int a, int b){
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
void test_NWD_2(){
    assert(NWD_2(12, 18) == 6);
    assert(NWD_2(25, 35) == 5);
    assert(NWD_2(17, 5) == 1);
}
int NWD_4(int tab[], int n){
    int res = tab[0];
    for (int i = 1; i < n; i++) res = NWD_2(res, tab[i]);
    return res;
}
void test_NWD_4(){
    int testTablica[] = {24, 36, 48, 60};
    assert(NWD_4(testTablica, 4) == 12);

    int testTablica2[] = {15, 25, 35, 45};
    assert(NWD_4(testTablica2, 4) == 5);
}
bool isPrime(int a, int b){
    return NWD_2(a, b) == 1;
}
void test_isPrime(){
    assert(isPrime(15, 28) == true);
    assert(isPrime(9, 12) == false);
    assert(isPrime(17, 31) == true);
}
bool czy_pitagorejska(int a, int b, int c){
    return pow(a, 2) + pow(b, 2) == pow(c,2);
}
void test_czy_pitagorejska(){
    assert(czy_pitagorejska(3, 4, 5) == true);
    assert(czy_pitagorejska(1, 2, 3) == false);
    assert(czy_pitagorejska(5, 12, 13) == true);
}
int liczbaCyfr(int n){
    int c = 0;

    if(n == 0) return 1;

    while(n != 0){
        c++;
        n/=10;
    }
    return c;
}
void test_liczbaCyfr(){
    assert(liczbaCyfr(5467) == 4);
    assert(liczbaCyfr(0) == 1);
    assert(liczbaCyfr(123456789) == 9);
}
int iloczynCyfr(int n){
    int c = 1;

    if (n == 0) return 0;

    while(n != 0){
        int cyfra = n % 10;
        c*=cyfra;
        n/=10;
    }
    return c;
}
void test_iloczynCyfr(){
    assert(iloczynCyfr(2361) == 36);
    assert(iloczynCyfr(12345) == 120);
    assert(iloczynCyfr(999) == 729);
}
//End 5c

int main() {
//    int a, b;
//    std::cin >> a >> b;

//    zad_5a_1(a ,b);
//    test_sumap();
//    test_odleglosc();

//    test_czy_przestepny();
//    test_ile_dni_w_roku();
//    test_ile_dni_w_miesiacu_if();
//    test_ile_dni_w_miesiacu_switch();
//    test_ile_dni_w_miesiacu_array();
//    test_ile_dni();

//    test_NWD_2();
//    test_NWD_4();
//    test_isPrime();
//    test_czy_pitagorejska();
//    test_liczbaCyfr();
//    test_iloczynCyfr();

    return 0;
}

