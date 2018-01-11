#include <iostream>
#include <fstream>
#include <queue>
#define dMAX 1005

using namespace std;

unsigned short int n, m;
unsigned short int pOx, pOy;
unsigned short int dOx, dOy;
unsigned short int new_x, new_y;
unsigned int first, last;
unsigned int matrix[dMAX][dMAX];
unsigned long long int newMatrix[dMAX][dMAX];

short int dx[] = {-1, 0, 1, 0};
short int dy[] = {0, 1, 0, -1};

struct Pozitie{
    unsigned short int x, y;
} temp;

queue <Pozitie> myQueue;

ifstream fin("ubuph.in");
ofstream fout("ubuph.out");

void PrintFMatrix() {
    for (unsigned short int i = 1; i <= n; i++) {
        for (unsigned short int j = 1; j <= n; j++) {
            cout << newMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    unsigned short int i, j;

    fin >> n >> m;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            fin >> matrix[i][j];
            newMatrix[i][j] = 1000001;
        }
    }

    fin >> pOx >> pOy;
    fin >> dOx >> dOy;

    //PrintFMatrix();

    Pozitie pVerif;

    temp.x = pOx;
    temp.y = pOy;

    myQueue.push(temp);

    newMatrix[pOx][pOy] = matrix[pOx][pOy];

    while (!myQueue.empty()) {

        pVerif = myQueue.front();

        for (i = 0; i < 4; i++) {

            new_x = pVerif.x + dx[i];
            new_y = pVerif.y + dy[i];

            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= m) {

                if (newMatrix[new_x][new_y] > newMatrix[pVerif.x][pVerif.y] + matrix[new_x][new_y]) {

                    newMatrix[new_x][new_y] = newMatrix[pVerif.x][pVerif.y] + matrix[new_x][new_y];

                    temp.x = new_x;
                    temp.y = new_y;

                    myQueue.push(temp);

                }

            }

        }

        //PrintFMatrix();
        myQueue.pop();
    }

    fout << newMatrix[dOx][dOy];

    return 0;
}
