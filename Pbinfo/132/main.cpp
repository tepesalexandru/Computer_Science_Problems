#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

int n, temp;
vector<int> numere;
ifstream inputFile("elempp.in");
ofstream outputFile("elempp.out");

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
    }
    for (int j = 0; j < n; j++) {
        if (numere[j] > 10) {
            temp = numere[j];
            while (temp >= 100) temp /= 10;
            if (sqrt(temp) == (int)(sqrt(temp))) outputFile << numere[j] << " ";
        }
    }
    return 0;
}
