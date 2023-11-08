#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void zadanie_1(int a, int b){
    for(; a<b; a++) cout << a << endl;
}

void zadanie_2(int a, int b, int c){
    for(; a<b; a+=c) cout << a << endl;
}

void zadanie_3(int n, int k){
    int a;
    for(;n<k;n++) {
        a = 2*n+1;
        cout << a << endl;
    }
}

void zadanie_4(int n) {
    int a;
    double b, res, srednia;
    if(n>0){
        for(;a<n;a++) {
            cout << "Podaj liczbę";
            cin >> b;
            res += b;
        }
        srednia = res/n;
        cout << "Suma" << res << endl;
        cout << "Srednia" << srednia << endl;
    } else cout << "To nie jest liczba naturalna";
}

void zadanie_5(){
    int a, dodatnie=0, przez6=0, mniejsze=0, tmp=0;
    do{
        cin >> a;

        if(a>0) dodatnie++;
        if(a%6==0) przez6++;
        if(a<tmp) mniejsze++;

        tmp = a;
    } while(a!=0);
    cout << dodatnie << endl;
    cout << przez6-1 << endl;
    cout << mniejsze;
}

int zadanie_6(int n){
    int i, res=1;
    for(i=1; i<=n; i++) {
        res *= i;
    }
    return res;
}

int zadanie_7_nwd(int a, int b){
    int tmp;
    while(b!=0){
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int zadanie_7_nww(int a, int b){
    return a*b/zadanie_7_nwd(a, b);
}

void zadanie_8(){
    for(int i = 0; i < 10; ++i){
        cout << rand() % 10 << " ";
    }
}
string bin(int n){
    string res = "";

    while(n){
        if(n==1) res+="1";
        n%2==0 ? res+="0" : res+="1";
        n%=2;
    }

    return res;
}

void rev(string res){
    for(int i = res.size()-1; i>=0; --i) cout << res[i];
}


long int silnia(int n){
    int res = 1;
    for (int i = 1; i<n; i++){
        res *= 1;
    }
    return res;
}

int zadanie_11(int x, int N, int n){
    int res;
    for(; n<N; n++){
        res += pow(x, n)/silnia(n);
    }
    return res;
}

int main() {
//    cin >> a >> b;
//    zadanie_1(a, b);

//    cin >> a >> b >> c;
//    zadanie_2(a,b,c);

//    cin >> n >> k;
//    zadanie_3(n,k);

//    cin >> n;
//    zadanie_4(n);

//    cin >> n;
//    zadanie_6(n);

//    cin >> a >> b;
//    zadanie_7_nwd(a, b);
//    zadanie_7_nww(a,b);

//    srand(time(nullptr));
//    zadanie_8();

//    int n;
//    cin >> n;
//    cout << bin(n);

    int n,N,x;
    cin >> n >> N >> x;
    cout << zadanie_11(x, N, n);

    return 0;
}