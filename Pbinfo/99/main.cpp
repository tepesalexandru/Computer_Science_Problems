#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, counter;
vector<int> numere;
ifstream inputFile("nraparitii.in");
ofstream outputFile("nraparitii.out");

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
    }
    for (int j = 0; j < n; j++) {
        if (numere[j] == numere[n - 1]) counter++;
    }
    outputFile << counter;
    return 0;
}
