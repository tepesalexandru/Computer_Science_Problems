#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, temp;
vector<int> numere;
vector<int> sumCif;
ifstream inputFile("sortcif.in");
ofstream outputFile("sortcif.out");

int SumOfDigits(int x) {
    int y = 0;
    while (x) {
        y += x % 10;
        x /= 10;
    }
    return y;
}

int main()
{
    inputFile >> n;
    numere.resize(n);
    sumCif.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
        sumCif[i] = SumOfDigits(numere[i]);
    }
    sort(sumCif.begin(), sumCif.end());
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            temp = SumOfDigits(numere[k]);
            if (temp == sumCif[j]) {
                outputFile << numere[k] << " ";
                numere[k] = -1;
                break;
            }
        }
    }
    return 0;
}
