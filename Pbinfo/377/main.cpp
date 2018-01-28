#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

unsigned int n;
unsigned int divs[100000], counter;

void Divisors(unsigned int a) {
    unsigned int i;
    float r = sqrt(i);
    for (i = 1; i <= r; i++) {
        if (a % i == 0) {
            counter++;
            divs[counter] = i;
            counter++;
            divs[counter] = a / i;
        }
    }
}



int main()
{
    cin >> n;
    Divisors(n);
    sort(divs + 1, divs + 1 + counter);
    cout << divs[counter / 2] << " " << divs[counter / 2 + 1];
    return 0;
}
