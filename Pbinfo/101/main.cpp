#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

int counter;
char s1[256], cuvinte[100][30], *p, temp[256], sep[] = " ,.!?;   ";
ifstream fin("sortcuv.in");
ofstream fout("sortcuv.out");

int main()
{
    int i, j;
    fin.get(s1, 256);
    p = strtok(s1, sep);
    while (p) {
        counter++;
        strcpy(cuvinte[counter], p);
        p = strtok(NULL, " ");
    }
    for (i = 1; i < counter; i++) {
        for (j = i + 1; j <= counter; j++) {
            if (strcmp(cuvinte[i], cuvinte[j]) > 0) {
                strcpy(temp, cuvinte[i]);
                strcpy(cuvinte[i], cuvinte[j]);
                strcpy(cuvinte[j], temp);
            }
        }
    }
    for (i = 1; i <= counter; i++) {
        fout << cuvinte[i] << "\n";
    }
    return 0;
}
