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

int nr_prim(int n) {
    do {
        if (n % 2) n += 2;
        else n++;
    } while (!isPrime(n));
    return n;
}

int main()
{
    cout << nr_prim(17);
    return 0;
}
