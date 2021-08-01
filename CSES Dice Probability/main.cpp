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
#define get(mask,i) (bool(mask&(1<<(i))))
#define set(mask,i) (mask|=(1<<(i)))
#define invert(mask,i) (mask^=(1<<(i)))
#define popcount(mask) (__builtin_popcount(mask))
template<class T> ostream & operator<<(ostream & out, vector<T> & v){
	out<<"[";
	for(auto k : v) out<<k<<" ";
	out<<"]"<<"\n";
	return out;
}
template<class T> ostream & operator<<(ostream & out, set<T>  s){
	out<<"{";
	for(auto k : s) out<<k<<" ";
	out<<"}"<<"\n";
	return out;
}

template<class T, class U> ostream & operator<<(ostream & out, pair<T,U>  p){
	out<<"[ "<<p.first<<" , "<<p.second<<" ] ";
	return out;
}
template<class T, class U> istream & operator>>(istream & in, pair<T,U> & p){
	in>>p.first>>p.second;
	return in;
}


typedef long long intl;
typedef long double ld;

ld dp[105][605];
ld DP(int i, int j){
    if(j<0) return 0;
    if(i==0) return (j==0);
    if(dp[i][j]>-1) return dp[i][j];
    dp[i][j] = 0;
    forsn(k,1,7) dp[i][j] += DP(i-1,j-k)/6;
    return dp[i][j];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forn(i,105) forn(j,605) dp[i][j] = -2;
    int n,a,b; cin>>n>>a>>b;
    ld res = 0;
    forsn(i,a,b+1) res += DP(n,i);
    cout<<setprecision(6)<<fixed<<res<<endl;
    return 0;
}
