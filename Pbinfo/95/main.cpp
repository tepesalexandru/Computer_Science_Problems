#include <iostream>
#include <string.h>

using namespace std;

int counter;
char s[256];

int main()
{
    cin.get(s, 256);
    for (int i = 0; i < strlen(s) - 1; i++) {
        if (strchr("aeiou", s[i])) {
            if (strchr("aeiou", s[i + 1])) {
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}
