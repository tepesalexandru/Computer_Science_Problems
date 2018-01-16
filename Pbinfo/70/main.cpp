#include <iostream>

using namespace std;

int multipli(int a, int b, int c) {
    return (b / c) - ((a - 1) / c);
}

int x, y, z;

int main()
{
    cin >> x >> y >> z;
    cout << multipli(x, y, z);
    return 0;
}
