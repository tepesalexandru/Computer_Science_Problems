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

int i_prim(int n) {
    int p1, p2;
    p1 = p2 = n;
    if (isPrime(n)) return 0;
    else {
        do {
            if (p1 % 2) p1 -= 2;
            else p1 -= 1;
        } while (!isPrime(p1));
        do {
            if (p2 % 2) p2 += 2;
            else p2 += 1;
        } while (!isPrime(p2));
    }
    return p2 - p1;
}



int main()
{
    cout << i_prim(27);
    return 0;
}
