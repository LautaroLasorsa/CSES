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
#define set(mask,i,v)  ( ((mask & ~( ( (1<<TAM_MASK)-1) << (TAM_MASK*(i)) )) | (v<<(TAM_MASK * (i))) ))
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
const int maxn = 5005;
intl pre[maxn];
intl dp[maxn][maxn];
int I[maxn][maxn];
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin>>n;
    forn(i,n){
        intl x; cin>>x;
        pre[i+1] = pre[i]+x;
        I[i+1][i+1] = i+1;
        dp[i+1][i+1] = 0;
    }
    forsn(j,1,n+1){
        dforsn(i,1,j){
            dp[i][j] = 1e18;
            //cout<<"Muevo entre "<<I[i][j-1]<<" y "<<I[i+1][j]<<endl;
            forsn(a,I[i][j-1],I[i+1][j]+1){
                intl v = dp[i][a]+dp[a+1][j];
            //    cout<<v<<" vs "<<dp[i][j]<<" en "<<a<<endl;
                if(v<dp[i][j]){
                    dp[i][j] = v;
                    I[i][j] = a;
                }
            }
            dp[i][j] += pre[j]-pre[i-1];
        }
    }
    /*forsn(i,1,n+1){
        forsn(j,1,n+1) printf(" %2lld | %d ||",dp[i][j],I[i][j]); //cout<<dp[i][j]<<" | "<<I[i][j]<<" || ";
        //forn(j,n+1) cout<<I[i][j]<<" || ";
        cout<<endl;
    }*/
    cout<<dp[1][n]<<endl;
    return 0;
}
