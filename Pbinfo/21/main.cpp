#include <iostream>

using namespace std;

void sum_cif(int &n, int &S) {
    S = 0;
    while (n) {
        S += n % 10;
        n /= 10;
    }
}

int n;

int main()
{
    cin >> n;
    sum_cif(n);
    return 0;
}
