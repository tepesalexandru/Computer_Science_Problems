#include <iostream>

using namespace std;

void oglindit(int x, int &n) {
    n = 0;
    while (x) {
        n *= 10;
        n += x % 10;
        x /= 10;
    }
}

int a, b;

int main()
{
    cin >> a;
    oglindit(a, b);
    cout << b;
    return 0;
}
