#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
int Res[2000000];
bitset<2000000> used;
int main()
{
    int n;
    cin>>n;
    int v = 3;
    Res[0] = 1;
    if(n == 2)
    {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    if(n == 4)
    {
        cout<<"3 1 4 2"<<endl;
        return 0;
    }
    for(int i = 1;i<n;i++)
    {
        Res[i] = v;
        if(Res[i]-Res[i-1] == -1 || Res[i]-Res[i-1] == 1||used[Res[i]])
        {
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
        used[Res[i]] = true;
        v = (v+2)%(n+1);
        if(v < 2)
            v = 2;
    }
    for(int i = 0;i<n;i++)
        printf("%d ",Res[i]);
}
