#include <iostream>
#include <string.h>

using namespace std;

int counter;
char s[256], t[256];

int main()
{
    cin.get(s, 256);
    for (int i = 0; s[i] != '\0'; i++) {
        if (strchr("aeiou", s[i])) {
            strcpy(t, s + i);
            strcpy(s + i + 1, t);
            s[i + 1] = '*';
            counter++;
            i++;
        }
    }
    counter == 0 ? cout << "FARA VOCALE" : cout << s;
    return 0;
}
