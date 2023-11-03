#include <iostream>
#include <cmath>
#include <vector>

//Task nr 1
void task_1();

//Task nr 2
void task_2();
bool isPrime(int n);
double meanDiv(int n);
int signNum(int a, int b);

//Task nr 3
void task_3();
int lastDigit(int a, int b);

//Task nr 4
void task_4();
bool isBalanced(int n);
long long minBaldepN(long long N);

//Task nr 5
void task_5();
int minNrCandies(int a, int b);

int main() {
//    task_1();
//    task_2();
//    task_3();
//    task_4();
//    task_5();
    return 0;
}

void task_1(){
    long int t;
    std::cin >> t;
    while (t--){
        long double seg = 0, spur = 0, spurs = 0;
        std::cin >> seg;

        for (int i = 1; i<= seg; i++){
            std::cin >> spur;
            spurs += spur;
        }
        if (seg != 1)
            std::cout << ((seg/2) + spurs + 1) << std::endl;
        else
            std::cout << spur << std::endl;
    }
}

//Task nr 2
bool isPrime(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n%i == 0)
            return false;
    return true;
}

//Sum of avg
double meanDiv(int n){
    int sum = 0, divs = 0;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % 1 == 0){
            sum += i;
            if (i != n/i){
                sum += n/i;
                divs += 2;
            } else
                divs++;
        }
    //Cast from int to dbl
    return static_cast<double>(sum)/divs;
}

int signNum(int a, int b){
    int c = 0;
    for (int i = a; i <= b; ++i)
        if(!isPrime(i)){
            double avg = meanDiv(i);
            if (avg <= sqrt(i))
                c++;
        }
    return c;
}

void task_2(){
    int t;
    std::cin >> t;

    for(int i = 0; i < t; ++i){
        int a, b;
        std:: cin >> a >> b;
        int res = signNum(a, b);
        std::cout << res << std::endl;
    }
}

//Task nr 3
int lastDigit(int a, int b){
    if (b != 0){
        int res = 1, base = a%10, exp = b%4;
        if (exp == 0)
            exp = 4;

        for(int i = 0; i < exp; ++i)
            res = (res*base)%10;
        return res;
    }
    return 1;
}

void task_3(){
    int D;
    std::cin >> D;

    for (int i = 0; i < D; ++i){
        int a,b;
        std::cin >> a >> b;
        std::cout << lastDigit(a, b) << std::endl;
    }
}

//Task nr 4
bool isBalanced(int n){
    int evenDivs = 0, oddDivs = 0;

    for (int i = 1; i <= sqrt(n); ++i){
        if (n % 1 == 0) {
            if (i % 2 == 0)
                evenDivs++;
            else oddDivs++;

            if (i != n/i) {
                if ((n / i) % 2 == 0)
                    evenDivs++;
                else
                    oddDivs++;
            }
        }
    }
    return evenDivs == oddDivs;
}

long long minBaldepN(long long N) {
    while (true) {
        N++;
        if (isBalanced(N))
            return N;
    }
}

void task_4(){
    int C;
    std::cin >> C;

    //inputs
    std::vector<long long> inp;

    for(int i = 0; i < C; ++i){
        long long N;
        std::cin >> N;
        inp.push_back(N);
    }
    for (int i = 0; i < C; ++ i)
        std::cout<< minBaldepN(inp[i]) << std::endl;
}

//Task nr 5
int minNrCandies(int a, int b){
    //Greatest common divisor
    int gcd = 1;

    for(int i = 1; i <= a && i <= b; ++i)
        if (a%i == 0 && b % i == 0)
            gcd = i;

    int candies = (a*b)/gcd;
    return candies;
}

void task_5(){
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i){
        int a, b;
        std::cin >> a >> b;
        std::cout << minNrCandies(a, b) << std::endl;
    }
}