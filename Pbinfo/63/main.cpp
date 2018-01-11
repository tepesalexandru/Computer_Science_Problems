#include <iostream>
#include <math.h>

using namespace std;

int n;

void PrimeFactors(int k) {
    int temp, counter, maxV, maxE;
    temp = counter = 0;

    if (k % 2 == 0) {
        temp = 2;
        do {
            counter++;
            k /= 2;
        } while (k % 2 == 0);
    }

    maxV = temp;
    maxE = counter;

    for (int i = 3; i <= sqrt(k); i += 2) {
        counter = 0;
        if (k % i == 0) {
            temp = i;
            do {
                counter++;
                k /= i;
            } while (k % i == 0);
            /*if (counter == maxE) {
                if (i > maxV) {
                    maxV = i;
                }
            } else if (counter > maxE) {
                maxE = counter;
                maxV = i;
            }
            */
            if (counter >= maxE) {
                maxE = counter;
                maxV = i;
            }
        }
    }

    if (k > 2) {
        if (1 >= maxE) {
            if (k > maxV) {
            	maxV = k;
            }
        }
    }

    cout << maxV;

}

int main()
{
    cin >> n;
    PrimeFactors(n);
    return 0;
}
