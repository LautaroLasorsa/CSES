#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int tam[200002], maxt = 0;
void Ubicar(int v)
{
    if(tam[maxt] <= v)
        maxt++, tam[maxt] = v;
    else
    {
        int pos = upper_bound(tam,tam+maxt,v) - tam;
        tam[pos] = v;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int h;
        scanf("%d",&h);
        Ubicar(h);
    }
    cout<<maxt<<endl;
}
/*
5
1 1 1 1 1
*/
