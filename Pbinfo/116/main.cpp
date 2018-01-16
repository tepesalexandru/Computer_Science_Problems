#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

bool IsPrime(int x) {
    int counter = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            counter++;
            if (i != sqrt(x)) {
                counter++;
            }
        }
    }
    return (counter == 2);
}

int n, temp;
float S, counterino, S1;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (IsPrime(temp)) {
            S += temp;
            counterino++;
        }
    }
    S /= counterino;
    S1 = S * 100;
    S1 = (int)S1;
    S1 /= 100;
    cout << S1;
    return 0;
}
