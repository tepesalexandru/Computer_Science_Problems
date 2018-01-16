#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char s[256];
int n;
ifstream fin("palindrom.in");
ofstream fout("palindrom.out");

bool Palindrom(char *p) {
    for (int i = 0, j = strlen(p) - 1; i < j; i++, j--) {
        if (p[i] != p[j]) return false;
    }
    return true;
}

int main()
{
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> s;
        fout << Palindrom(s) << '\n';
    }
    return 0;
}
