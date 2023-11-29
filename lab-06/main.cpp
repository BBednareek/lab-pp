#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void wyswietl_tab(const int tab[], int size){

    for(int idx=0; idx<size; idx++){
        std::cout << tab[idx] << " ";
    }
    std::cout << std::endl;
}

void wyswietl_vec(const std::vector<int> &tab){
    for(int idx : tab){
        std::cout << idx << " ";
    }
    std::cout << std::endl;
}

void wyswietl_tab_n(const int tab[], int size, int n){
    for (int i = 0; i<size; i+=n){
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

void wyswietl_vec_n(const std::vector<int> &tab, int n){
    for (int i = 0; i < tab.size(); i += n)
        std::cout << tab[i] << " ";

    std::cout << std::endl;
}

void srednia_tab(const int tab[], int size){
    int c = 0;
    float res = 0;
    for (int i = 0; i < size; i++){
        c+=tab[i];
    }
    res = static_cast<float>(c)/static_cast<float>(size);
    std::cout<<res;
}
void srednia_vec(const std::vector<int> &tab){}

int main() {

    /* Zad 1

    int a, n = 100;
    std::cin >> a;

    int tab[n];
    std::vector<int> vec;

    for(int i = 0; i<n; ++i){
        tab[i] = a;
    }

    wyswietl_tab(tab, n);

    for(int i = 0; i<n; ++i){
        vec.push_back(a);
    }

    wyswietl_vec(vec);

     END
    */

    /* Zadanie 2
    std::srand(std::time(nullptr));
    int a,b,n;
    std::cin >> a >> b >> n;
    std::vector<int> vec;

    for (int i = 0; i < n; ++i)
        vec.push_back(rand() % b + a);

    wyswietl_vec(vec);

     END
     */

//    ZAD 3
//    int tab[10];
//    std::srand(std::time(nullptr));
//    for (int &i: tab)
//        i = rand() % 10;
//
//    wyswietl_tab(tab, 10);
//    std::cout << std::endl;
//    wyswietl_tab_n(tab, 10, 5);
//
//    std::vector<int> vec;
//
//    for (int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    wyswietl_vec_n(vec, 5);
//
// END
    int tab[10];
    std::srand(std::time(nullptr));
    for (int &i: tab)
        i = rand() % 10;

    wyswietl_tab(tab, 10);
    std::cout << std::endl;
    srednia_tab(tab, 10);


    return 0;
}
