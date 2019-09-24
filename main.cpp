#include <iostream>
#include<fstream>
using namespace std;
//
ifstream f("atestat.in");
ofstream g("atestat.out");

void citire(int &n , int a[])
{
    f>>n;
    for(int i=1; i<=n; i++)
        f>>a[i];
}

void pcta(int n, int a[])
{
    for(int i=1; i<=n; i++)
    {
        if(a[i]%2==0)
            cout<<a[i]<<" ";
    }
    cout<<endl;
}

int mini,maxi;

void pctb(int n, int a[])
{
    mini=1000000000;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<mini)
            mini=a[i];
        if(a[i]>maxi)
            maxi=a[i];
    }
    cout<<mini<<endl<<maxi;
}

void pctc(int mini, int maxi)
{
    while(mini!=maxi)
    {
        if(maxi>mini)
            maxi=maxi-mini;
        else
            mini=mini-maxi;
    }
    g<<mini;
}

int main()
{
    int n, a[31];
    citire(n,a);
    pcta(n,a);
    pctb(n,a);
    pctc(mini,maxi);
    return 0;
}
