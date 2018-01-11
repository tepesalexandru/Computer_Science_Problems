#include <iostream>

using namespace std;

int interval(int a[], int n) {
    int firstTerm = a[0], lastTerm = a[n - 1];
    int minimum = firstTerm;
    int maximum = firstTerm;
    if (lastTerm < minimum) minimum = lastTerm;
    if (lastTerm > maximum) maximum = lastTerm;
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= minimum && a[i] <= maximum) {
            counter++;
        }
    }
    return counter;
}

int x[] = {123, 273, 9, 83, 93, 63};

int main()
{
    cout << interval(x, 6);
    return 0;
}
