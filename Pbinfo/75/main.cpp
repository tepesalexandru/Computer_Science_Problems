#include <iostream>

using namespace std;

int sum3(int v[], int n) {
    if (n == 0) return 0;
    else return ((v[n - 1] % 3 == 0) ? v[n - 1] : 0) + sum3(v, n - 1);
}

int x[] = {12, 7, 6, 3, 8, 5};

int main()
{
    cout << sum3(x, 6);
    return 0;
}
