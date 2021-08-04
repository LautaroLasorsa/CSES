#include <iostream>
#define ll long long
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
struct project{
    int a, b;
    long long p;
};
bool Comparer(const project & a, const project & b)
{
    return a.a < b.a;
}
project in[200000];
ll DP[450000];
map<int,int> mapa;
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i<N;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        in[i].a = a, in[i].b = b, in[i].p = c;
        mapa[a]++, mapa[b]++;
    }
    int val = 1;
    for(auto & k : mapa)
        k.second = val, val++;
    ll R = 0;
    sort(in,in+N,Comparer);
    for(int i = 0, j = 0;i<N;i++)
    {
        int a = mapa[in[i].a], b = mapa[in[i].b]+1;
        while(j<a)
        {
            DP[j+1] = max(DP[j],DP[j+1]);
            j++;
        }
        //cout<<a<<" - "<<b<<" ; "<<DP[a]<<" , "<<DP[b]<<" ( "<<in[i].p<<endl;
        DP[b] = max(DP[b],DP[a] + in[i].p);
        R = max(R,DP[b]);
    }
    cout<<R<<endl;
}
