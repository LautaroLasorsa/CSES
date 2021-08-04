#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll DP[511][260000];
ll BinPow(ll x, ll e)
{
    if(e == 0)
        return 1;
    if(e%2 == 1)
        return (x * BinPow(x,e-1))%MOD;
    ll b = BinPow(x,e/2);
    return (b*b)%MOD;
}
int main()
{
    ll N;
    cin>>N;
    ll Inverso2 = BinPow(2,MOD-2);
    //cout<<2<<" * "<<Inverso2<<" = "<<2*Inverso2<<endl;
    ll S = (N*(N+1))/2;
    if(S%2 == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    S/=2;
    DP[1][0] = 1;
    for(int i = 1;i<=N;i++)
        for(int j = 0;j<=S;j++)
            DP[i+1][j] = (DP[i+1][j] + DP[i][j])%MOD,DP[i+1][j+i] = (DP[i+1][j+i] + DP[i][j])%MOD;
    cout<<(DP[N+1][S]*Inverso2)%MOD<<endl;
}
