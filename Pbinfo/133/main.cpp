#include <iostream>
#include <string.h>

using namespace std;

char nume[256], prenume[256], vowels[] = "AEIOUaeiou", t[256];
int len;

int main()
{
    cin >> nume >> prenume;
    len = strlen(prenume);
    for (int i = 0; prenume[i] != '\0'; i++) {
        if (strchr(vowels, prenume[i])) {
            strcpy(t, prenume + i + 1);
            strcpy(prenume + i, t);
            i--;
        }
    }
    strcat(prenume, " ");
    strcat(prenume, nume);
    cout << prenume;
    return 0;
}
