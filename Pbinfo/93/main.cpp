#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int n, counter, maxC = -1;
char s[256], *p, temp[256], d[256];
ifstream fin("cuvmax.in");
ofstream fout("cuvmax.out");

int main()
{
    fin >> n;
    fin.get();
    for (int i = 0; i < n; i++) {
        fin.getline(s, 256);
        strcpy(d, s);
        p = strtok(s, " ");
        counter = 0;
        while (p) {
            counter++;
            p = strtok(NULL, " ");
        }
        if (counter > maxC) {
            maxC = counter;
            strcpy(temp, d);
        }
    }
    fout << temp;
    return 0;
}
