#include <iostream>

using namespace std;

void afismat(int a[4][4], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int x[2][3] = {{3, 5, 6},{7, 9, 11}};

int main()
{
    cout << x[0][2];
    return 0;
}
