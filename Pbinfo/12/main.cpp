#include <iostream>
#include <string.h>

using namespace std;

int x, n;
char text[256], text1[256], *p, p1[256], t[256] = "", separator[] = " ";

int main()
{
    int i = 0;
    cin.get(text, 256);
    strcpy(text1, text);
    while ((int)text1[i] == 32) {
        strcat(t, " ");
        i++;
    }
    p = strtok(text, separator);
    while (p) {
        x = p - text;
        n = strlen(p);
        strcpy(p1, p);
        p1[0] -= 32;
        p1[n - 1] -= 32;
        strcat(t, p1);
        i = x + n;
        while ((int)text1[i] == 32) {
            strcat(t, " ");
            i++;
        }
        p = strtok(NULL, separator);
    }
    cout << t;
    return 0;
}
