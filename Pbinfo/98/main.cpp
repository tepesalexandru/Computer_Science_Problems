#include <fstream>
#include <vector>

using namespace std;

int n, maximum = -1, counter;
vector<int> numere;
ifstream inputFile("maxim4.in");
ofstream outputFile("maxim4.out");

int main()
{
    inputFile >> n;
    numere.resize(n);
    for (int i = 0; i < n; i++) {
        inputFile >> numere[i];
        if (numere[i] > maximum) {
            maximum = numere[i];
        }
    }
    for (int j = 0; j < n; j++) {
        if (numere[j] == maximum) counter++;
    }
    outputFile << counter;
    return 0;
}
