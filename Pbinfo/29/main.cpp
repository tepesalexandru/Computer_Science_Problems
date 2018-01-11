#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
    int counter = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            counter++;
            if (i != sqrt(n)) {
                counter++;
            }
        }
    }
    return counter == 2;
}

void sub(int n, int &a, int &b) {
    if (n == 5) {
        a = 3;
        b = 2;
    } else {
    a = n;
    do {
        (a % 2 == 0) ? a-- : a-=2;
    } while (!isPrime(a));
    b = a;
    do {
        (b % 2 == 0) ? b-- : b-=2;
    } while (!isPrime(b));
    }
}

int x, y, z;

int main() {
    cin >> x;
    sub(x, y, z);
    cout << y << " " << z;
    return 0;
}
