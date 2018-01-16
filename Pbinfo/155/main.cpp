#include <iostream>
#include <string.h>

using namespace std;

char s1[256];
int frecv[10], maxi;

int main()
{
    cin.get(s1, 256);
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (isdigit(s1[i])) {
            //cout << (int)s1[i] - 48 << " ";
            frecv[(int)s1[i] - 48]++;
            if (frecv[(int)s1[i] - 48] > maxi) maxi = frecv[(int)s1[i] - 48];
        }
    }
    //cout << maxi;
    if (maxi == 0) cout << "NU";
    else {
        for (int j = 0; j < 10; j++) {
            if (frecv[j] == maxi) {
                cout << j;
                break;
            }
            //cout << frecv[j] << " ";
        }
    }
    return 0;
}
