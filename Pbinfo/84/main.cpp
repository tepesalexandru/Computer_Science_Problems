#include <iostream>
#include <string.h>

using namespace std;

int index1, index2, exista;
char s[256], vow[] = "aeiouAEIOU", cons[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", v, c, temp;

int main()
{
    int i;
    cin.get(s, 256);
    for (i = 0; s[i] != '\0'; i++) {
        if (strchr(vow, s[i])) {
            v = s[i];
            index1 = i;
            exista++;
            break;
        }
    }
    for (i = strlen(s) - 1; i >= 0; i--) {
        if (strchr(cons, s[i])) {
            c = s[i];
            index2 = i;
            exista++;
            break;
        }
    }
    if (exista == 2) {
        temp = v;
        s[index1] = c;
        s[index2] = temp;
        cout << s;
    } else {
        cout << "IMPOSIBIL";
    }
    return 0;
}
