#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int H[2001], S[2001], DP[2001][100002], N, X, R = 0;
int main()
{
    cin>>N>>X;
    for(int i = 0;i<N;i++)
        scanf("%lld",H+i);
    for(int i = 0;i<N;i++)
        scanf("%lld",S+i);
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<=X;j++)
        {
            DP[i+1][j] = max(DP[i+1][j],DP[i][j]);
            if((j + H[i]) <= X)
                DP[i+1][j+H[i]] = max(DP[i+1][j+H[i]], DP[i][j] + S[i]);
        }
    }
   // ll R = 0;
    for(int i = 0;i<=X;i++)
        R = max(R,DP[N][i]);
    cout<<R<<endl;
}
