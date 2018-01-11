#include <iostream>

using namespace std;

int count(float a[], int n) {
    float S = a[0];
    int counter = 0;
    for (int i = 1; i < n; i++) {
        S += a[i];
    }
    S /= n;
    for (int j = 0; j < n; j++) {
        if (a[j] >= S) {
            counter++;
        }
    }
    return counter;
}

float x[] = {12, 7.5, 6.5, 3, 8.5, 7.5};

int main()
{
    cout << count(x, 6);
    return 0;
}
