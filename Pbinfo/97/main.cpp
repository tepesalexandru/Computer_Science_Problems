#include <iostream>
#include <string.h>

using namespace std;

char s[256], t[256];

bool Anagrame(char cuv1[], char cuv2[]) {
    int v[26] = {0}, i;
    for (i = 0; cuv1[i]; ++i) {
        v[cuv1[i] - 'a']++;
    }
    for (i = 0; cuv2[i]; ++i) {
        v[cuv2[i] - 'a']--;
    }
    for (i = 0; i < 26; i++) {
        if (v[i]) return false;
    }
    return true;
}

int main()
{
    cin >> s >> t;
    cout << Anagrame(s, t);
    return 0;
}
