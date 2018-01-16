#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

unsigned short int n;
unsigned short int x[10];
unsigned short int V[10];

ifstream fin("permutari2.in");
ofstream fout("permutari2.out");

/// Can it appear twice?

bool Candidate(unsigned short int k) {

    for (unsigned short int i = 1; i < k; i++)
        if (x[k] == x[i]) return false;
    return true;

}

void BackTrack(unsigned short int k) {

    unsigned short int i, j;

    for (i = 1; i <= n; i++) {

        x[k] = V[i];

        if (Candidate(k)) {
            if (k == n) {
                for (j = 1; j <= n; j++) {
                    fout << x[j] << " ";
                }
                fout << "\n";
            } else {
                BackTrack(k + 1);
            }
        }

    }

}

int main()
{

    fin >> n;

    for (unsigned short int i = 1; i <= n; i++)
        fin >> V[i];


    sort(V, V + n + 1);

    BackTrack(1);

    return 0;
}
