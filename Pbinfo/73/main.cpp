#include <iostream>
#include <algorithm>

using namespace std;

int x[] = {12, 7, 6, 3, 8, 5};

int suma(int v[], int n, int m) {
    int S = 0;
    sort(v, v + n);
    for (int i = 0; i < m; i++) {
        S += v[i];
    }
    return S;
}

int main()
{
    cout << suma(x, 6, 4);
    return 0;
}
