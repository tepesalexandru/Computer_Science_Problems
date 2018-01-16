#include <iostream>
#include <fstream>

using namespace std;

int n, temp, minimum, maximum;
ifstream inputFile("minmax.in");
ofstream outputFile("minmax.out");

int main()
{
    inputFile >> n;
    inputFile >> temp;
    minimum = temp;
    maximum = temp;
    for (int i = 1; i < n; i++) {
        inputFile >> temp;
        if (temp < minimum) {
            minimum = temp;
        } else if (temp > maximum) {
            maximum = temp;
        }
    }
    outputFile << minimum << " " << maximum;
    return 0;
}
