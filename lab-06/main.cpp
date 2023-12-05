#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

void wyswietl_tab(const int tab[], int size){

    for(int idx=0; idx<size; idx++){
        std::cout << tab[idx] << " ";
    }
    std::cout << std::endl;
}

void wyswietl_vec(const std::vector<int> &vec){
    for(int idx : vec){
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

void wyswietl_vec_n(const std::vector<int> &vec, int n){
    for (int i = 0; i < vec.size(); i += n)
        std::cout << vec[i] << " ";

    std::cout << std::endl;
}

double srednia_tab(const int tab[], int size){
    int c = 0;
    double res;
    for (int i = 0; i < size; i++){
        c+=tab[i];
    }
    res = static_cast<double>(c)/static_cast<double>(size);

    return res;
}
double srednia_vec(const std::vector<int> &vec){
    int c = 0;
    double res;
    for(int i : vec)
        c += i;
    res = static_cast<double>(c)/static_cast<double>(vec.size());
    return res;
}

double variance_tab(const int tab[], int size){
    double avg = srednia_tab(tab, size);
    double c = 0;

    for (int i = 0; i < size; ++i)
        c += pow(tab[i] - avg, 2);

    return c/size;
}

double variance_vec(const std::vector<int> &vec){
    double avg = srednia_vec(vec);
    double c = 0;

    for(int i : vec)
        c += pow(i - avg, 2);

    return c/static_cast<double>(vec.size());
}

std::vector<int> fib(int n){
    std::vector<int> res;

    if (n <= 0) return res;
    res.push_back(0);

    if (n == 1) return res;
    res.push_back(1);

    for (int i = 2; i < n; ++i) {
        int next = res[i - 1] + res[i - 2];
        res.push_back(next);
    }
    return res;
}

void copyTab(const int tab1[], int tab2[2], int size){
    for (int i = 0; i < size; ++i)
        tab2[i] = tab1[i];
}

void reverseTab(int tab[], int size){
    int l = 0;
    int r = size - 1;
    while (l < r) {
        int tmp = tab[l];
        tab[l] = tab[r];
        tab[r] = tmp;
        l++;
        r--;
    }
}

void reverseVec(std::vector<int> &vec){
    for (int i = 0; i < vec.size()/2; ++i){
        int tmp = vec[i];
        vec[i] = vec[vec.size() - 1 - i];
        vec[vec.size() - 1 - i] = tmp;
    }
}

std::vector<int> evenVec(const std::vector<int> &vec){
    std::vector<int> res;
    for (int e: vec)
        if (e % 2 == 0)
            res.push_back(e);
    return res;
}

bool containsVal(const std::vector<int> &vec, int val){
//  any_of
    return std::any_of(vec.begin(), vec.end(), [val](int i){
        return i == val;
    });

//  for
//    for(int i : vec)
//        if(i == val) return true;
//    return false;
}

int indexAt(const std::vector<int> &vec, int val){
    int c = 0;
    for(int i = 0; i < vec.size(); ++i)
        if(vec[i] == val){
            c+=i+1;
            break;
        } else
            c = -1;
    return c;
}

int lastIndexAt(const std::vector<int> &vec, int val){
    int c = 0;
    for (int i = static_cast<int>(vec.size()); i>=0; --i)
        if(vec[i] == val){
            c+=i+1;
            break;
        } else
            c = -1;
    return c;
}

void oneR(std::vector<int> &vec){
    for(int i = static_cast<int>(vec.size())-1; i>0; --i)
        vec[i] = vec[i-1];
    vec[0]=0;
}

void oneL(std::vector<int> &vec){
    for (int i = 0; i < vec.size()-1; ++i)
        vec[i] = vec[i+1];
    vec[vec.size()-1] = 0;
}

void rotate(std::vector<int> &vec, int d){
    if (d == 1){
        int tmp = vec[vec.size()-1];
        oneR(vec);
        vec[0] = tmp;
    } else if (d == -1){
        int tmp = vec[0];
        oneL(vec);
        vec[vec.size()-1] = tmp;
    }
}

bool areEqual(const std::vector<int> &vec1, const std::vector<int> &vec2){
    for(int i = 0; i < vec1.size(); ++i)
        if(abs(vec1[i]) != abs(vec2[i]))
            return false;
    return true;
}

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

    /*
    Zadanie 2
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

//Zad 4
//    int tab[10];
//    std::srand(std::time(nullptr));
//    for (int &i: tab)
//        i = rand() % 10;
//
//    wyswietl_tab(tab, 10);
//    std::cout << std::endl;
//    std::cout << srednia_tab(tab, 10);

//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    std::cout << srednia_vec(vec);

// END

//Zad 5
//    int tab[10];
//    std::srand(std::time(nullptr));
//    for(int &i : tab)
//        i = rand() % 10;
//
//    wyswietl_tab(tab, 10);
//    std::cout << std::endl;
//    std::cout << srednia_tab(tab, 10);
//    std::cout << std::endl;
//    std::cout << variance_tab(tab, 10);

//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    std::cout << srednia_vec(vec);
//    std::cout << std::endl;
//    std::cout << variance_vec(vec);

// END

// Zadanie 6
//    int n = 10;
//    std::vector<int> fibo = fib(n);
//    wyswietl_vec(fibo);
// END

// Zadanie 7
//    const int n = 5;
//    int tab1[n], tab2[n];
//    std::srand(std::time(nullptr));
//    for(int &i : tab1)
//        i = rand() % 10;
//
//    wyswietl_tab(tab1, n);
//    std::cout << std::endl;
//    copyTab(tab1, tab2, n);
//    wyswietl_tab(tab2, n);
// END

// Zadanie 8
//    int tab[10];
//    std::srand(std::time(nullptr));
//    for(int &i : tab)
//        i = rand() % 10;
//
//    wyswietl_tab(tab, 10);
//    std::cout << std::endl;
//    reverseTab(tab, 10);
//    wyswietl_tab(tab, 10);
//
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    reverseVec(vec);
//    wyswietl_vec(vec);
// END

// Zadanie 9
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    vec = evenVec(vec);
//    wyswietl_vec(vec);
// END

// Zadanie 10
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    std::cout << containsVal(vec, 6);
// END

// Zadanie 11
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    std::cout << indexAt(vec, 10);
// END

// Zadanie 12
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    std::cout << lastIndexAt(vec, 10);
// END

// Zadanie 13/14
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    oneR(vec);
//    oneL(vec);
//    wyswietl_vec(vec);
// END

// Zadanie 15
//    std::srand(std::time(nullptr));
//    std::vector<int> vec;
//    vec.reserve(10);
//    for(int i = 0; i < 10; ++i)
//        vec.push_back(rand() % 10 + 1);
//
//    wyswietl_vec(vec);
//    std::cout << std::endl;
//    rotate(vec, -1);
//    wyswietl_vec(vec);
// END

// Zadanie 16
//    std::vector<int> vec = {1, 2, 3, 4};
//    std::vector<int> vec2 = {1, -2, 3, 4};
//    std::cout << areEqual(vec, vec2);
// END

    std::cout << std::endl;
    return 0;
}
