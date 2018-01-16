#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int n, counter;
bool onlyVow;
char s[31];
ifstream fin("doarvocale.in");
ofstream fout("doarvocale.out");

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> s;
        onlyVow = true;
        for (int j = 0; j < strlen(s); j++) {
            if (!strchr("aeiou", s[j])) {
                onlyVow = false;
                break;
            }
        }
        if (onlyVow) counter++;
    }
    fout << counter;
    return 0;
}
