#include <bits/stdc++.h>
#define dMax 101
#define M 10001 //Suma in euro + 1
using namespace std;
int S,n,matrix[dMax][dMax],newmatrix[dMax][dMax];
ifstream fin("taxe2.in");
ofstream fout("taxe2.out");

int dx[] = {-1, 0, 1, 0},
    dy[] = { 0, 1, 0, -1};
int first,last;//coada
struct Pozitie{
    int x, y;
} c[90000];//100pct

void PrintFMatrix(int nn, int mm, int mtrx[][dMax]) {
    for (int i = 0; i <= nn + 1; i++) {
        for (int j = 0; j <= mm + 1; j++) {
         if(mtrx[i][j]==M) cout<<"M  ";

           else cout << mtrx[i][j] << "  ";
        }
        cout << "\n";
    }
cout<<"**************************************\n";
}
int main()
{
    fin>>S>>n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
               fin>> matrix[i][j];
               newmatrix[i][j]=M;//la citire initializez cu o valoare mai mare decat suma S, noua matrice
    }
    //PrintFMatrix(n,n,matrix);
    c[first].x=1;
    c[first].y=1;

    newmatrix[1][1]=matrix[1][1];

    Pozitie pverif;

    while(first<=last){
        pverif = c[first];//pozitia curenta
        first++;
        for(int i=0;i<4;++i)//vecinii
        {
            if(pverif.x+dx[i]>=1 && pverif.y+dy[i]>=1 && pverif.x+dx[i]<=n && pverif.y+dy[i]<=n)
            {
                if(newmatrix[pverif.x+dx[i]][pverif.y+dy[i]]>newmatrix[pverif.x][pverif.y] + matrix[pverif.x+dx[i]][pverif.y+dy[i]]){
                            //pun cea mai mica valoarea care imi iese
                            newmatrix[pverif.x+dx[i]][pverif.y+dy[i]]=newmatrix[pverif.x][pverif.y] + matrix[pverif.x+dx[i]][pverif.y+dy[i]];
                            ++last;
                            c[last].x=pverif.x+dx[i]; c[last].y=pverif.y+dy[i];

                }
            }
        }
        //PrintFMatrix(n,n,newmatrix);
    }
    //PrintFMatrix(n,n,newmatrix);
    if (newmatrix[n][n] <= S)//newmatrix[n][n] = suma cheltuita pe taxe
        fout<< S - newmatrix[n][n];
    else
       fout<<-1;
    return 0;
}
