#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

#define forn(i,n) for(int i = 0;i<int(n);i++)
#define dforn(i,n) for(int i = int(n)-1;i>=0;i--)
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define fore(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)

#define DBG(x) do{cout<<#x<<" = "<<x<<endl;}while(false)
#define get(mask,i) (mask&(1<<i))
#define set(mask,i) (mask|=(1<<i))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
typedef long long intl;
int dp[int(2e5)][200], in[int(2e5)], N,M, mod=1e9+7, res;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N>>M;
    forn(i,N)cin>>in[i];
    forsn(i,1,M+1)dp[0][i] = 1;
    forn(i,N){
        if(in[i]!=0){
            int j = in[i];
            forsn(k,j-1,j+2){
                dp[i+1][k] = (dp[i+1][k]+dp[i][j])%mod;
            }
        }
        else forsn(j,1,M+1){
            forsn(k,j-1,j+2){
                dp[i+1][k] = (dp[i+1][k]+dp[i][j])%mod;
            }
        }
    }
     if(in[N-1] !=0 ) res = dp[N-1][in[N-1]];
     else forsn(i,1,M+1) res =(res+dp[N-1][i])%mod;
     cout<<res<<"\n";
	return 0;
}
