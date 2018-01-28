#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    if (divisors.size() % 2 == 1) {
        cout << divisors[divisors.size() / 2];
    } else {
        cout << divisors[divisors.size() / 2 - 1] << " " << divisors[divisors.size() / 2];
    }
}
