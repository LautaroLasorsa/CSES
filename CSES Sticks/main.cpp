#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll P[200001],N;
ll abss(ll x)
{
    if(x < 0)
        return -x;
    return x;
}
ll Probar(ll V)
{
    ll COST = 0;
    for(int i = 0;i<N;i++)
        COST += abss(V-P[i]);
    return COST;
}
int main()
{
    cin>>N;
    for(int i = 0;i<N;i++)
        scanf("%lld",P+i);
    sort(P,P+N);
    if(N%2)
        cout<<Probar(P[N/2])<<endl;
    else
        cout<<min(Probar(P[N/2]),Probar(P[N/2 - 1]))<<endl;
}
