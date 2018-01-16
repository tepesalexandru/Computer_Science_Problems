#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n, temp;
vector<int> numere;
vector<int> digits;
ifstream inputFile("sortcif2.in");
ofstream outputFile("sortcif2.out");

int FirstDigit(int x) {
    while (x > 9) {
        x /= 10;
    }
    return x;
}

int main()
{
    inputFile >> n;
    numere.resize(n);
    digits.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
        digits[i] = FirstDigit(numere[i]);
    }
    sort(digits.begin(), digits.end());
    /*for (int a = 0; a < n; a++) {
        outputFile << digits[a] << " ";
    }*/
    //outputFile << "\n";
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            temp = FirstDigit(numere[k]);
            if (temp == digits[j]) {
                outputFile << numere[k] << " ";
                numere[k] = -1;
                break;
            }
        }
    }
    return 0;
}
