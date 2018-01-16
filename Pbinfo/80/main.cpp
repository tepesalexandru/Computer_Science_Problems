#include <iostream>
#include <vector>

using namespace std;

int GDC(int a, int b) {
    return (b == 0) ? a : GDC(b, a % b);
}

vector<int> numere;
int temp, counter;

int main()
{
    do {
        cin >> temp;
        numere.push_back(temp);
    } while (temp != 0);
    for (int i = 0; i < numere.size() - 1; i++) {
        if (GDC(numere[i], numere[i + 1]) == 1) {
            counter++;
        }
    }
    cout << counter;
    return 0;
}
