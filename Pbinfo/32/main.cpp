#include <iostream>

using namespace std;

void P(int &n, int c) {
    if (n == 0) cout << "0";
    else if (n < 10) {
        n == c ? cout << "" : cout << n;
    }
    else {
        if (n % 10 != c) cout << n % 10;
        n /= 10;
        P(n, c);
    }
}

int a, b;

int main()
{
    cin >> a >> b;
    P(a, b);
    return 0;
}
