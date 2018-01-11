#include <iostream>

using namespace std;

int multiplu(int a[], int n, int k) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            if (a[i] % 10 == k) {
                counter++;
            }
        }
    }
    return counter;
}

int x[] = {9, 273, 63, 83, 93, 123};

int main()
{
    cout << multiplu(x, 6, 3);
    return 0;
}
