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
const int maxn = 2e6, MOD = 1e9+7;
int dp[maxn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	dp[0] = 1;
	forn(j,1.5e6){
        forsn(i,1,7){
            dp[j+i] = (dp[j+i]+dp[j])%MOD;
        }
	}
	int n; cin>>n;
	cout<<dp[n]<<"\n";
	return 0;
}
