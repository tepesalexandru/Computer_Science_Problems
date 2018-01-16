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

bool a_prim(int n) {
    bool primeFactors = true;
    int counter = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            counter++;
            if (!isPrime(i) && i != 1) primeFactors = false;
            if (i != sqrt(n)) {
                counter++;
                if (!isPrime(n / i) && (n / i) != n) primeFactors = false;
            }
        }
    }
    return (counter == 4 && primeFactors);
}

int main()
{
    cout << a_prim(24);
    return 0;
}
