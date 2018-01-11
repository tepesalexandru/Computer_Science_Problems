#include <iostream>

using namespace std;

void sub(int n, int k) {
    for (int i = n; i > 0; i--) {
        cout << k * i << " ";
    }
}

int a, b;

int main()
{
    cin >> a >> b;
    sub(a, b);
    return 0;
}
