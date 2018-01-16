#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

int n, S;
vector<int> numere;
ifstream inputFile("nrapprime.in");
ofstream outputFile("nrapprime.out");

bool isPrime(int x) {
    int counter = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            counter++;
            if (i != sqrt(x)) {
                counter++;
            }
        }
    }
    return counter == 2;
}

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
        if (isPrime(numere[i])) S++;
    }
    outputFile << S;
    return 0;
}
