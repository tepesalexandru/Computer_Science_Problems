#include <iostream>
#include <string.h>

using namespace std;

int len, t;
char s1[256];
bool appeared[50];

int main()
{
    cin.get(s1, 256);
    len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (s1[i] >= 97) {
            t = (int)s1[i] - 97;
            if (!appeared[t]) {
                cout << (char)(t + 97) << " ";
                appeared[t] = true;
            }
        }
    }
    return 0;
}
