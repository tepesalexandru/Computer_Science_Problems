#include <iostream>
#include <string.h>

using namespace std;

char s[256], vow[] = "aeiou", *p;

int main()
{
    cin.get(s, 256);
    for (int i = 0; i < strlen(s); i++) {
        if (!strchr(vow, s[i])) cout << s[i];
    }
    return 0;
}
