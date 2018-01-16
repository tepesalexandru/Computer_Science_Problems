#include <iostream>

using namespace std;

int nr_cif(int x, int y) {
    int counter = 0, temp;
    while (x) {
        temp = x % 10;
        if (temp != 0) {
            if (y % temp == 0) counter++;
        }
        x /= 10;
    }
    return counter;
}

int main()
{
    cout << nr_cif(7203534,20);
    return 0;
}
