#include <iostream>
#include <math.h>

using namespace std;

int sum_div(int x) {
    long long int S = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            S += i;
            if (i != sqrt(x)) {
                S += (x / i);
            }
        }
    }
    return S;
}

int main()
{
    cout << sum_div(6);
    return 0;
}
