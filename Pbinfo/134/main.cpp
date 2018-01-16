#include <iostream>
#include <fstream>
#define dMAX 100001

using namespace std;

unsigned long long int n, k, firstIndex = 1, maxSum;
unsigned short int arr[dMAX];
unsigned long long int sarr[dMAX];

ifstream fin("secvk.in");
ofstream fout("secvk.out");

int main()
{
    unsigned int i;
    fin >> n >> k;
    for (i = 1; i <= n; i++) {
        fin >> arr[i];
        sarr[i] = sarr[i - 1] + arr[i];
    }
    for (i = 1; i <= n - k; i++) {
        if (sarr[i + k - 1] - sarr[i - 1] > maxSum) {
            maxSum = sarr[i + k - 1] - sarr[i - 1];
            firstIndex = i;
        }
    }
    for (i = 1; i <= k; i++, firstIndex++) {
        fout << arr[firstIndex] << " ";
    }

    return 0;
}
