#include <iostream>
#include <string.h>

using namespace std;

char s[256], alfabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    cin.get(s, 256);
    for (int i = 0; i < strlen(s); i++) {
        if (strchr(alfabet, s[i])) cout << s[i];
    }
    return 0;
}
