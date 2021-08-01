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
#define TAM_MASK 1
#define get(mask,i) ((mask>>(TAM_MASK*(i)) & ( (1<<TAM_MASK)-1)))
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) )
#define popcount(mask) (__builtin_popcount(mask))
#define endl '\n'
#define ALL(x) x.begin(),x.end()
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
intl in[4000];
int n,k;
pair<intl,intl> dp[4000];
pair<intl,intl> Intento(intl m){
    forn(i,n+1) dp[i] = {(intl)1e18,(intl)1e18};
    dp[0] = {0ll,0ll};
    forn(i,n)
    {
        intl sum = in[i];
        forsn(j,i+1,n+1){
            dp[j] = min(dp[j],{1ll*sum*sum+m+dp[i].first,dp[i].second-1});
            sum += in[j];
        }
    }
    return dp[n];
}
intl dp2[100][100];
void DP(){
    forn(i,n+1)
        forn(j,2*k+1)
            dp2[i][j] = 1e18;
    dp2[0][0] = 0;
    forn(i,n)
        forn(j,2*k){
            intl sum = in[i];
            forsn(v,1,n-i+1){
                dp2[i+v][j+1] = min(dp2[i+v][j+1],sum*sum+dp2[i][j]);
                sum += in[i+v];
            }
        }
    forn(i,2*k+1){
        cout<<dp2[n][i]<<" - ";
        cout<<endl;
    }

}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k;
    forn(i,n) cin>>in[i];
    if(k==n){
        intl res = 0;
        forn(i,n) res += 1ll*in[i]*in[i];
        cout<<res<<endl;
    }
    intl l = 0, r = 1e18;
    while(r-l-1){
        intl m = (l+r)/2;
        auto val = Intento(m);
        /*DBG(val);
        DBG(l);
        DBG(r);
        DBG(m);
        forn(i,n+1) DBG(dp[i]);
        cout<<endl;*/
        if(-val.second>k) l = m;
        else r = m;
    }
    DP();
    forsn(v,r-2,r+2){
        auto ret = Intento(v);
        cout<<v<<" >> "<<ret<<" : "<<(ret.first+v*ret.second)<<endl;
        forsn(i,1,n+1) cout<<dp[i]<<"+";
        cout<<endl;
    }
    DBG(r);
    auto val = Intento(r);
    intl res = val.first + r*val.second;
    cout<<res<<endl;
    return 0;
}
/*
12 7
4 2 3 3 2 5 2 5 5 5 5 5

*/
