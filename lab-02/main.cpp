#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void zadanie_1();
void zadanie_2();
void zadanie_3();
void zadanie_4();
void zadanie_5();
void zadanie_6();
void zadanie_7();
void zadanie_8();
void zadanie_9();
void zadanie_10();
void zadanie_11();

int main()
{
//    zadanie_1();
//    zadanie_2();
//    zadanie_3();
//    zadanie_4();
//    zadanie_5();
//    zadanie_6();
//    zadanie_7();
//    zadanie_8();
//    zadanie_9();
//    zadanie_10();
//    zadanie_11();

    return 0;
}

void zadanie_1(){
    int x;

    x = 2+3*4;
    cout << x << endl;

    x = 20/10/2;
    cout << x << endl;

    x = 20-10+5;
    cout << x << endl;

    x = 5+10/2;
    cout << x << endl;

    x = (5+10)/3;
    cout << x << endl;

    x = 10%3;
    cout << x << endl;

    x = 10%4;
    cout << x << endl;

}

void zadanie_2(){
    int x,y, res;

    cin >> x >> y;

    res = x+y;
    cout << res << endl;

    res = x-y;
    cout << res << endl;

    res = x*y;
    cout << res << endl;

    res = x/y;
    cout << res << endl;
}

void zadanie_3(){
    int x,y, resI;
    float resF;

    cin >> x >> y;

    resI = x/y;
    resF = x/y;
    cout << resI << endl;
    cout << resF << endl;

}

void zadanie_4(){
    int x = 10;
    int z = 0;
    double y = 5.2;
    int res;

//    res = x/z;
//    cout << res << endl;
//
//    res = x/0;
//    cout << res << endl;

    res = x/y;
    cout << res << endl;

}

void zadanie_5(){
    int R;
    float pole, obwod;
    float pi = M_PI;
    cin >> R;

    pole = pi * pow(R,2);
    cout << pole << endl;

    obwod = 2*pi*R;
    cout << obwod << endl;
}

void zadanie_6(){
    int xi,yi,xj,yj;
    double odcinek;

    cin >> xi >> yi;
    cin >> xj >> yj;

    odcinek = sqrt(pow(xj-xi, 2) + pow(yj-yi,2));
    cout << odcinek << endl;

}

void zadanie_7(){
    int r;
    double pi = M_PI;
    double res;

    cin >> r;

    res = 4.0/3.0 * pi * pow(r, 3);

    cout << res << endl;
}

void zadanie_8(){
    double pi = M_PI;
    cout << sin(0) << endl;
    cout << sin(pi/4) << endl;
    cout << sin(pi/2) << endl;
    cout << sin(pi) << endl;
    cout << sin(45) << endl;
    cout << sin(90) << endl;
    cout << sin(180) << endl;
}

void zadanie_9(){
    double pi = M_PI;

    cout << setprecision(1) << pi << endl;
    cout << setprecision(3) << pi << endl;
    cout << setprecision(7) << pi << endl;
    cout << pi << fixed;
}

void zadanie_10(){
    int x = 3;
    int y = 4;
    int z = 5;
    int res;

    res = x + y/z;
    cout << res << endl;

    res = x + (y/(z+3));
    cout << res << endl;

    res = (x+y)/(z+(x/y));
    cout << res << endl;

    res = 1/(x+(1/(y+(1/(x-1)))));
    cout << res << endl;

}

void zadanie_11(){
    double x = M_PI * 100;
    float y = M_PI * 100;

    cout << x << setprecision(1) << endl;
    cout << x << setprecision(3) << endl;
    cout << x << setprecision(7) << endl;
    cout << x << setprecision(12) << endl;

    cout << y << setprecision(1) << endl;
    cout << y << setprecision(3) << endl;
    cout << y << setprecision(7) << endl;
    cout << y << setprecision(12) << endl;

}