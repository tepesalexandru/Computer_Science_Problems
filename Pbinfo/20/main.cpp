#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int x) {
    int counter = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            counter++;
            if (i != sqrt(x)) {
                counter++;
            }
        }
    }
    return counter == 2;
}

void sum_div_prim(int x, int &n) {
    n = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (isPrime(i)) n += i;
        }
    }
}

int a, b;

int main()
{
    cin >> a;
    sum_div_prim(a, b);
    cout << b;
    return 0;
}
