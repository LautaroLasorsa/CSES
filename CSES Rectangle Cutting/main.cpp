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
int dp[600][600];
int DPF(int a, int b){
    if(dp[a][b]!=0) return dp[a][b];
    if(a==b) return 0;
    dp[a][b] = 1e9;
    forsn(i,1,a){
        int v = DPF(i,b) + DPF(a-i,b) + 1;
        if(v<dp[a][b]) dp[a][b]=v;
    }
    forsn(i,1,b){
        int v = DPF(a,i) + DPF(a,b-i) + 1;
        if(v<dp[a][b]) dp[a][b]=v;
    }
    return dp[a][b];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	int a,b; cin>>a>>b;
	cout<<DPF(a,b)<<"\n";
	return 0;
}
