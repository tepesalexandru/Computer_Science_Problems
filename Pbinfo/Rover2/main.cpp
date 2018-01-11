#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <deque>
#define dMAX 501
#define infinity 20000

using namespace std;

unsigned short int V, n;
unsigned short int greutate, danger;
unsigned short int matrix[dMAX][dMAX];
int newMatrix[dMAX][dMAX];
unsigned int tempC;
short int l = 1, r = 10000, gmin = -1, middle;
unsigned short int new_x, new_y;
short int dx[] = {-1, 0, 1, 0};
short int dy[] = {0, 1, 0, -1};

struct Position{
    unsigned short int x, y;
} start, stop, pVerif, temp;

queue<Position> myQueue;
deque<Position> myDeque;

ifstream fin("rover.in");
ofstream fout("rover.out");

void PrintFMatrix() {
    for (unsigned short int i = 1; i <= n; i++) {
        for (unsigned short int j = 1; j <= n; j++)
            cout << newMatrix[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void SolveFirst(unsigned short int a, unsigned short int b) {
    memset(newMatrix, -1, sizeof(newMatrix));
    temp.x = a, temp.y = b;
    myDeque.push_back(temp);
    newMatrix[1][1] = 0;
    while (!myDeque.empty()) {
        pVerif = myDeque.front();
        myDeque.pop_front();
        for (unsigned short int i = 0; i < 4; i++) {
            new_x = pVerif.x + dx[i];
            new_y = pVerif.y + dy[i];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= n)
                if (newMatrix[new_x][new_y] == -1) {
                    if (matrix[new_x][new_y] < greutate) {
                        newMatrix[new_x][new_y] = newMatrix[pVerif.x][pVerif.y] + 1;
                        temp.x = new_x, temp.y = new_y;
                        myDeque.push_back(temp);
                    } else {
                        newMatrix[new_x][new_y] = newMatrix[pVerif.x][pVerif.y];
                        temp.x = new_x, temp.y = new_y;
                        myDeque.push_front(temp);
                    }
                }
        }
    }
    if (V == 1) fout << newMatrix[n][n];
}

bool Lee(unsigned short int k) {
    memset(newMatrix, -1, sizeof(newMatrix));
    temp.x = temp.y = 1;
    myDeque.push_back(temp);
    newMatrix[1][1] = 0;
    while (!myDeque.empty()) {
        pVerif = myDeque.front();
        myDeque.pop_front();
        for (unsigned short int i = 0; i < 4; i++) {
            new_x = pVerif.x + dx[i];
            new_y = pVerif.y + dy[i];
            if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= n)
                if (newMatrix[new_x][new_y] == -1)
                    if (matrix[new_x][new_y] >= k) {
                        newMatrix[new_x][new_y] = newMatrix[pVerif.x][pVerif.y] + 1;
                        temp.x = new_x, temp.y = new_y;
                        myDeque.push_back(temp);
                    }
        }

    }
    return newMatrix[n][n] != -1;
}

void SolveSecond() {
    while (l <= r) {
        middle = (l + r) / 2;
        if (Lee(middle)) {
            gmin = middle;
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
    fout << gmin;
}

int main()
{
    fin >> V;
    V == 1 ? fin >> n >> greutate : fin >> n;
    for (unsigned short int i = 1; i <= n; i++)
        for (unsigned short int j = 1; j <= n; j++) {
            fin >> matrix[i][j];
            newMatrix[i][j] = infinity;
        }
    V == 1 ? SolveFirst(1, 1) : SolveSecond();
    return 0;
}
