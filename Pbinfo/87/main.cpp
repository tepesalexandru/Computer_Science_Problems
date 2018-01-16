#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

char s[256], t[256];
int x, maxL = -1, temp;
ifstream fin("lgmax.in");
ofstream fout("lgmax.out");

int main()
{
    fin >> x;
    for (int i = 0; i <= x; i++) {
        fin.getline(s, 256);
        temp = strlen(s);
        if (temp > maxL) {
            maxL = temp;
            strcpy(t, s);
        }
    }
    fout << t;
    return 0;
}
