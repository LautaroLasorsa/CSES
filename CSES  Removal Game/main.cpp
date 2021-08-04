#include <iostream>
#define ll long long
using namespace std;
ll DP[5001][5001], in[5001],N;
ll Query(int ini, int fin, bool cuenta)
{
    if(DP[ini][fin]!=-1e17)
        return DP[ini][fin];
    if(ini == fin)
        DP[ini][fin] = in[ini] * cuenta;
    else
    {
        if(cuenta)
            DP[ini][fin] = max(Query(ini+1,fin,!cuenta) + in[ini], Query(ini,fin-1,!cuenta)  + in[fin]);
        else
            DP[ini][fin] = min(Query(ini+1,fin,!cuenta)  ,Query(ini,fin-1,!cuenta));
    }
    return DP[ini][fin];
}
int main()
{
    for(int i = 0;i<=5000;i++)
        for(int j = 0;j<=5000;j++)
            DP[i][j] = -1e17;
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>in[i];
    cout<<Query(0,N-1,true)<<endl;
}
