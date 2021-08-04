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
intl dp[3005][3005];
int in[3005], pre[3005];
intl g(int n, int k, int i){
    if(i>n) return 1e18;
    //cout<<n<<" "<<k<<" "<<i<<" : "<<dp[i][k-1] + intl(pre[n]-pre[i])*(pre[n]-pre[i])<<endl;
    return dp[i][k-1] + intl(pre[n]-pre[i])*(pre[n]-pre[i]);
}
void Recur(int nini, int nfin, int k, int Iini = 0, int Ifin = 3000){
    if(nini>nfin) return;
    int n = (nini+nfin)/2;
    dp[n][k] = 1e18;
    int ires = Iini;
    forsn(i,Iini,Ifin+1){
        intl v = g(n,k,i);
        if(v<dp[n][k]){
            ires = i;
            dp[n][k] = v;
        }
    }
    Recur(nini,n-1,k,Iini,ires);
    Recur(n+1,nfin,k,ires,Ifin);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    forsn(i,1,n+1){
        cin>>in[i];
        pre[i] = in[i]+pre[i-1];
        dp[i][1] = pre[i]*1ll*pre[i];
    }

    forsn(i,2,k+1)
        Recur(0,n+1,i,0,n+1);
    /*forn(i,n+1)
    {
        forn(j,k+1) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[n][k]<<endl;
    return 0;
}
