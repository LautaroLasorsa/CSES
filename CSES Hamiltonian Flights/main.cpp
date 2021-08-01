#include <iostream>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define DBG(x)do{cout<<#x<<" = "<<x<<endl;}while(false)
#define get(mask,i) ((mask)&(1<<(i)))
#define sett(mask,i) ((mask)|(1<<(i)))

/*template<class T> ostream  & operator<<(vector<T> v, ostream & out){
    out<<"[";
    for(auto k : v)out<<k<<" ";
    out<<"]";
    out<<endl;
    return out;
}*/

typedef long long intl;
int adj[21][21];
int dp[1<<21][20], N, M, mod = 1e9+7;
//bitset<1<<21> visto[21];
/*int TSP(int mask, int i){
    if(mask == (1<<(N))-1) return i == N-1;
    if(visto[i][mask]) return dp[mask][i];
    visto[i][mask] = true;
    dp[mask][i] = 0;
    forsn(j,1,N){
        if(!(get(mask,j)) && adj[i][j]){
            dp[mask][i] = (dp[mask][i]+intl(TSP(sett(mask,j),j))*adj[i][j])% mod;
        }
    }
    return dp[mask][i];
}*/
int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(0);
    //cin>>N>>M;
    scanf("%d %d",&N,&M);
    forn(i,M){
        int a,b; scanf("%d %d",&a,&b);
        a--,b--;
        adj[a][b]++;
    }
    int largo = 1<<N;
    dp[1][0] = 1;
    for(int i = 1;i<largo;i+=2){
        forn(j,N){
            if(get(i,j) && dp[i][j]){
                forsn(k,1,N){
                    if(!get(i,k) && adj[j][k]){
                        dp[sett(i,k)][k] = (dp[sett(i,k)][k]+intl(dp[i][j])*adj[j][k])%mod;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[largo-1][N-1]);
    //return 0;
   // cout<<dp[largo-1][N-1]<<endl;
   // cout<<TSP(1,0)<<"\n";
}
