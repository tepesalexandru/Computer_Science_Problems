#include <iostream>
#include <algorithm>

using namespace std;

/*int NumarCifre(int n) { //TODO: Recursive
    int counter = 0;
    while (n) {
        counter++;
        n /= 10;
    }
    return counter;
}*/

int NumarCifre(int n) {
    if (n < 10) return 1;
    else return 1 + NumarCifre(n / 10);
}

void numar(int n, int a[], int &k) {
    sort(a, a + n);
    int temp = NumarCifre(a[n - 1]);
    int p10 = 1;
    for (int i = 0; i < temp; i++) {
        p10 *= 10;
    }
    p10 /= 10;
    k = a[n - 1] * p10 + a[0];

}

int x[] = {120, 34, 51, 26, 403, 71};
int c;

int main()
{
    numar(6, x, c);
    cout << c;
    return 0;
}
