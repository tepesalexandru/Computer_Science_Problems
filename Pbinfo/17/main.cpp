#include <iostream>
#include <math.h>

using namespace std;

void sum_div(int x, int &n) {
    n = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            n += i;
            if (i != sqrt(x)) {
                n += x / i;
            }
        }
    }
}

int a, b;

int main()
{
    cin >> a;
    sum_div(a, b);
    cout << b;
    return 0;
}
