#include <iostream>

using namespace std;

int nz(int n) {
    int S = 0, p5 = 5;
    do {
        S += n / p5;
        p5 *= 5;
    } while (p5 <= n);
    return S;
}

int main()
{
    cout << nz(1000);
    return 0;
}
