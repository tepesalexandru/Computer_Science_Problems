#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> numere;
ifstream inputFile("halfsort.in");
ofstream outputFile("halfsort.out");

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
    }
    sort(numere.begin(), numere.begin() + n /2);
    sort(numere.begin() + n /2, numere.end());
    reverse(numere.begin() + n /2, numere.end());
    for (int j = 0; j < n; j++) {
        outputFile << numere[j] << " ";
    }
    return 0;
}
