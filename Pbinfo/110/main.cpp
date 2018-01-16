#include <iostream>
#include <string.h>

using namespace std;

int len;
char s1[256];

int main()
{
    cin.get(s1, 256);
    len = strlen(s1);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (j == i) continue;
            else cout << s1[j];
        }
        cout << "\n";
    }
    return 0;
}
