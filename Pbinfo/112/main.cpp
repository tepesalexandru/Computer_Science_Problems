#include <iostream>
#include <vector>

using namespace std;

int GDC(int a, int b) {
    return (b == 0) ? a : GDC(b, a % b);
}

int n, minimum, maximum, temp;
vector<int> numere;

int main()
{
    cin >> n;
    numere.resize(n);
    cin >> numere[0];
    maximum = numere[0];
    minimum = numere[0];
    for (int i = 1; i < n; i++) {
        cin >> numere[i];
        if (numere[i] > maximum) maximum = numere[i];
        else if (numere[i] < minimum) minimum = numere[i];
    }
    while (GDC(minimum, maximum) != 1) {
        temp = GDC(minimum, maximum);
        minimum /= temp;
        maximum /= temp;
    }
    cout << minimum << "/" << maximum;
    return 0;
}
