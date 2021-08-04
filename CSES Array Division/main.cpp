#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
ll val[200000], N,K;
bool Intento(ll sum)
{
    ll v = 0, k = 1;
    for(int i = 0;i<N;i++)
    {
        if(v + val[i]  > sum)
        {
            k++;
            if(k > K)
                return false;
            v = 0;
        }
        v += val[i];
    }
    return true;
}
int main()
{
    cin>>N>>K;
    ll ini = 0, fin = 0;
    for(int i = 0;i<N;i++)
        scanf("%lld",&val[i]), ini = max(ini,val[i]), fin+= val[i];
    while(fin-ini > 1)
    {
        ll m = (fin+ini)/2;
        if(Intento(m))
            fin = m;
        else
            ini = m;
    }
    if(Intento(ini))
        cout<<ini<<endl;
    else
        cout<<fin<<endl;
}
