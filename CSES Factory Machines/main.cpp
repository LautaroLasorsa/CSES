#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
ll K[200000],N,T;
bool Posible(ll m)
{
    ll t = 0;
    for(int i = 0;i<N;i++)
        t += m/K[i];
  //  cout<<m<<" = "<<t<<" vs "<<T<<endl;
    return (t>=T);
}
int main()
{
    cin>>N>>T;
    for(int i = 0;i<N;i++)
        scanf("%lld",K+i);
    ll ini = 0, fin = 1e18 + 2;
    while(fin-ini>1)
    {
        ll m = (fin+ini)/2;
        if(Posible(m))
            fin = m;
        else
            ini = m;
    }
    cout<<fin<<endl;
}
