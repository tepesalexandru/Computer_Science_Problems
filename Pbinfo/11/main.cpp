#include <iostream>

using namespace std;

char vowels[] = {'a', 'e', 'i', 'o', 'u'};
string inputString;
int main()
{
    cin >> inputString;
    for (int i = 0; i < inputString.length(); i++) {
        for (int j = 0; j < 5; j++) {
            if (inputString[i] == vowels[j]) {
                inputString[i] = toupper(vowels[j]);
            }
        }
    }
    cout << inputString;
    return 0;
}
