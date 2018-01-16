#include <iostream>
#include <string.h>

using namespace std;

int counter = 0;
char s[256], voc[] = "aeiouAEIOU", *p;

int main()
{
    cin.get(s, 256);
    p = strtok(s, " ");
    while (p) {
        if (strchr(voc, p[0]) && strchr(voc, p[strlen(p) - 1])) counter++;
        p = strtok(NULL, " ");
    }
    cout << counter;
    return 0;
}
