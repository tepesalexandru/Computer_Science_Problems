#include <iostream>
#include <string.h>

using namespace std;

char s1[256];
int frecv[100], maxi;

int main()
{
    cin.get(s1, 256);
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (isalpha(s1[i]) && islower(s1[i])) {
            frecv[(int)s1[i] - 61] ++;
            if (frecv[(int)s1[i] - 61] > maxi) maxi = frecv[(int)s1[i] - 61];
        }
    }
    for (int i = 0; i < 100; i++) {
        if (frecv[i] == maxi) {
            cout << (char)(i + 61);
            break;
        }
    }
    return 0;
}
