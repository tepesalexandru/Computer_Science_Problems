#include <iostream>
#include <math.h>

using namespace std;

void nr_div_imp(int x, int &n) {
    n = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (i % 2 == 1) {
                n++;
            }
            if (i != sqrt(x)) {
                if ((x / i) % 2 == 1) n++;
            }
        }
    }
}

int a, b;

int main()
{
    cin >> a;
    nr_div_imp(a, b);
    cout << b;
    return 0;
}
