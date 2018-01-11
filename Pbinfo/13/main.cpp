#include <iostream>

using namespace std;

string inputString;
int counter = 0;

int main()
{
    cin >> inputString;
    for (int i = 0; i < inputString.length(); i++) {
        for (int j = 0; j < inputString.length() - counter; j++) {
            cout << inputString[j];
        }
        cout << "\n";
        counter++;
    }
    counter = 0;
    for (int k = 0; k < inputString.length(); k++) {
        for (int l = counter; l < inputString.length(); l++) {
            cout << inputString[l];
        }
        cout << "\n";
        counter++;
    }
    return 0;
}
