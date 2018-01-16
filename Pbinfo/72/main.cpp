#include <iostream>

using namespace std;

int suma(int v[], int n, int i, int j) {
    int S = 0;
    for (int a = 1; a <= i - 1; a++) {
        S += v[a];
    }
    for (int b = j + 1; b <= n; b++) {
        S += v[b];
    }
    return S;
}

int c[] = {12, 7, 6, 3, 8, 5};

int main()
{
    cout << suma(c, 6, 2, 4);
    return 0;
}
