#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int n, maxCounter = -1, counter;
char s[256], temp[256];
ifstream fin("vocmax.in");
ofstream fout("vocmax.out");

int main()
{
    fin >> n;
    fin.get();
    for (int i = 0; i < n; i++) {
        fin.getline(s, 256);
        counter = 0;
        for (int j = 0; s[j] != '\0'; j++) {
            if (strchr("aeiou", s[j])) {
                counter++;
            }
        }
        if (counter > maxCounter) {
            maxCounter = counter;
            strcpy(temp, s);
        }
        ///cout << counter << " " << s << "\n";
    }
    fout << temp;
    return 0;
}
