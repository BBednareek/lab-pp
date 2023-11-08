#include <iostream>
#include <cmath>

using namespace std;

int zadanie_1();
double zadanie_2();
double zadanie_3();
bool zadanie_4();
string zadanie_5();
void zadanie_6();
int zadanie_7();
void zadanie_8();
void zadanie_9();

int main() {
//    cout << zadanie_1();
//    cout << zadanie_2();
//    cout << zadanie_3();
//    cout << zadanie_4();
//    cout << zadanie_5();
//    zadanie_6();
//    cout << zadanie_7();
//    zadanie_8();
    zadanie_9();
    return 0;
}

int zadanie_1(){
    int a,b;
    cin >> a >> b;
    if(a>b) return b;
    else if(a==b) return a;
    else return a;
 }

 double zadanie_2(){
    double a,b;
    cin >> a >> b;

    if(a>b) return b/a;
    else return a/b;

}

double zadanie_3(){
    int a,b;
    cin >> a >> b;

    if (a%b==0) return a/b;
    else return a%b;
}

bool zadanie_4() {
    int a,b,c;
    cin >> a >> b >> c;

    if (a > 0 && a <= 10 && a < b && b > 15 || c == 5) return true;
    else return false;
}

string zadanie_5(){
    int punkty, max, res;
    cin >> punkty >> max;

    res = punkty/max;

    if (res >= 0 && res < 50) return "niedostateczna";
    else if (res >=50 && res < 60) return "dostateczna";
    else if (res >=60 && res < 70) return "dostateczna plus";
    else if (res >=70 && res < 80) return "dobra";
    else if (res >=80 && res < 90) return "dobra plus";
    else if (res >=90 && res < 100) return "bardzo dobra";
    else if(res==100) return "celująca";
    else return "Błąd! Ilość punktów musi zawierać się w przedziale [0,max]";
}

void zadanie_6(){
    int a,b,c;
    double res;

    cin >> a >> b >> c;

    res = pow(b,2) - 4*a*c;

    if (res>0) {
        int x1, x2;
        x1 = -b - sqrt(res)/2*a;
        x2 = -b + sqrt(res)/2*a;
        cout << x1 << " " << x2;
    }
    else if (res==0) {
        int x0;
        x0 = -b/2*a;
        cout << x0;
    }
    else cout << "Brak rozwiązań rzeczywistych";
}

int zadanie_7(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;



    return a;
}

void zadanie_8() {
    int zadanie;
    cout <<"Które zadanie chcesz wykonać: " << endl;
    cout << "1 Zad.1" << endl;
    cout << "2 Zad.2" << endl;
    cout << "3 Zad.3" << endl;
    cout << "4 Zad.4" << endl;
    cout << "5 Zad.5" << endl;
    cout << "6 Zad.6" << endl;
    cout << "7 Zad.7" << endl;
    cin >> zadanie;

    switch(zadanie){
        case 1: cout << zadanie_1(); break;
        case 2: cout << zadanie_2(); break;
        case 3: cout << zadanie_3(); break;
        case 4: cout << zadanie_4(); break;
        case 5: cout << zadanie_5(); break;
        case 6: zadanie_6(); break;
        case 7: cout << zadanie_7(); break;
        default: cout << "Wprowadź poprawny numer zadania!";
    }

}

void zadanie_9(){
    int tarcza[20][20];
    double oczko = .8;

    for(int i = 0; i < 10; i++){
        oczko += .8;
        for (int j =0; j<i; j++){
            tarcza[i][j] = oczko;
        }
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            cout << tarcza[i][j] << " ";
        }
    }

}
