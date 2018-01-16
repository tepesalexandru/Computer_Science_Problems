#include <iostream>
#include <string.h>

using namespace std;

int maxiLen = -1;
char s1[256], *p, sep[] = " :;,.    ", temp[256];
char maxiPal[256];

char* Lower(char *sir) {
    int len = strlen(sir);
    for (int i = 0; i < len; i++) {
        if (sir[i] <= 90 && sir[i] >= 65) sir[i] += 32;
    }
    return sir;
}

bool isPalindrome(char *sir) {
    int len = strlen(sir);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (sir[i] != sir[j]) return false;
    }
    return true;
}

int main()
{
    cin.get(s1, 256);
    p = strtok(s1, sep);
    while (p) {
        strcpy(temp, p);
        //cout << Lower(p) << " ";
        int len = strlen(temp);
        if (len > maxiLen) {
            if (isPalindrome(Lower(p))) {
                maxiLen = len;
                strcpy(maxiPal, temp);
            }
        }
        p = strtok(NULL, sep);
    }
    cout << maxiPal;
    return 0;
}
