#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> numere;
ifstream inputFile("sortare.in");
ofstream outputFile("sortare.out");

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
    }
    sort(numere.begin(), numere.end());
    for (int j = n - 1; j >= 0; j--) {
        outputFile << numere[j] << " ";
    }
    return 0;
}
