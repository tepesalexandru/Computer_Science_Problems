#include <iostream>
#include <fstream>
#define dMAX 500001

using namespace std;

unsigned short int k, counter;
bool sieve[dMAX];

ifstream fin("kprim.in");
ofstream fout("kprim.out");

int main()
{
    fin >> k;
    if (k == 1) {
        fout << 1;
        return;
    }
    unsigned long long int i, j;
    sieve[0] = sieve[1] = true;
    for (i = 2; i <= dMAX; i++) {
        if (!sieve[i]) {
            counter++;
            if (counter == k + 1) {
                fout << i * i;
                break;
            }
            for (j = i + i; j <= dMAX; j += i) {
                sieve[j] = true;
            }
        }
    }
    return 0;
}
