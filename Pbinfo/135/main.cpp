#include <iostream>
#include <string.h>

using namespace std;

char cuv1[31], cuv2[31], voc[] = "aeiou", cons[] = "bcdfghjklmnpqrstvwxyz";

int main()
{
    cin >> cuv1 >> cuv2;
    for (int i = 0; cuv1[i]; ++i) {
        if (strchr(voc, cuv1[i]) != 0  && strchr(voc, cuv2[i])) {
            cout << '*';
        }
            else {
                if (strchr(cons, cuv1[i])!= 0 && strchr(cons, cuv2[i])) {
                    cout << '#';
                } else {
                    cout << '?';
                }
            }
    }
    return 0;
}
