#include <iostream>
#include <fstream>
#include <deque>
#include <cstring>
#define dMAX 1001

using namespace std;

unsigned short int n;
unsigned int matrix[dMAX][dMAX];
int newMatrix[dMAX][dMAX];
short int dx[] = {-1, 0, 1, 0};
short int dy[] = {0, 1, 0, -1};
unsigned short int new_x, new_y;
unsigned int pmin;

struct Position{
    unsigned short int x, y;
} pVerif, temp;

deque<Position> myDeque;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

void PrintFMatrix(unsigned short int k) {
    cout << "***************** CURRENT INDEX : " << k << " *****************\n\n\n";
    for (unsigned short int i = 1; i <= n; i++) {
        for (unsigned short int j = 1; j <= n; j++)
            cout << newMatrix[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool Lee(unsigned short int k) {
    memset(newMatrix, -1, sizeof(newMatrix));
    newMatrix[1][1] = 0;
    temp.x = temp.y = 1;
    myDeque.push_back(temp);
    while (!myDeque.empty()) {
        pVerif = myDeque.front();
        myDeque.pop_front();
        for (unsigned short int i = 0; i < 4; i++) {
            new_x = pVerif.x + dx[i];
            new_y = pVerif.y + dy[i];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= n)
                if (newMatrix[new_x][new_y] == -1) {
                    if (matrix[new_x][new_y] <= k) {
                        newMatrix[new_x][new_y] = newMatrix[pVerif.x][pVerif.y] + 1;
                        temp.x = new_x, temp.y = new_y;
                        myDeque.push_back(temp);
                    }
                }
        }
    }
    //cout << k << "\n";
    //PrintFMatrix(k);
    return newMatrix[n][n] != -1;
}

void BinarySearch(unsigned int l, unsigned int r) {
    if (l <= r) {
        unsigned int middle = (l + r) / 2;
        if (Lee(middle)) {
            pmin = middle;
            BinarySearch(l, middle - 1); ///middle + 1, r
        } else {
            BinarySearch(middle + 1, r); ///l, middle - 1
        }
    }
}

int main()
{
    unsigned short int i, j;
    fin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            fin >> matrix[i][j];
        }
    }
    BinarySearch(0, 100000);
    fout << pmin;
    return 0;
}
