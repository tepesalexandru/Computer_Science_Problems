#include <iostream>
#include <math.h>
#define dMAX 1002

using namespace std;

int n, value = -1, maxD = -1;
int arr[dMAX];
int temp;

int PrimeFactors(int k) {
    int counter = 0;
    if (k % 2 == 0) counter++;
    while (k % 2 == 0) {
        ///counter++;
        k /= 2;
    }

    for (int i = 3; i <= sqrt(k); i += 2) {
        if (k % i == 0) {
            counter++;
            ///cout << k << " " << i << "\n";
        }
        while (k % i == 0) {
            ///counter++;
            k /= i;
        }
    }

    if (k > 2) counter++;

    return counter;

}

int main()
{
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
        temp = PrimeFactors(arr[i]);
        ///cout << temp;
        if (temp == maxD) {
            if (arr[i] < value) value = arr[i];
        } else if (temp > maxD) {
            maxD = temp;
            value = arr[i];
        }
    }

    cout << value;

    return 0;
}
