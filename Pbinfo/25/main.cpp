#include <iostream>
#include <algorithm>

using namespace std;

int cmmnr(int x) {
    int cifre[10] = {0}, temp = 0, counter;
    while (x) {
        cifre[temp] = x % 10;
        x /= 10;
        temp++;
    }
    counter = temp;
    temp = 0;
    sort(cifre, cifre + 9);
    for (int i = 9; i >= (10 - counter - 1); i--) {
        temp *= 10;
        temp += cifre[i];
    }
    return temp;
}

int a;

int main()
{
    cin >> a;
    cout << cmmnr(a);
    return 0;
}
