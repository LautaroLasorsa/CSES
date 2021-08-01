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
const int maxn = 3e5;
vector<int> Adj[maxn], Adj2[maxn], AdjC[maxn];
vector<pair<int,int> > aris;
int ord[maxn], ori = 0, comp[maxn], N, M, C = 1;
intl dp[maxn], res = 0, K[maxn], K2[maxn];
bitset<maxn> vis;
void DFS(int nod, vector<int> adj[maxn]){
    if(vis[nod]) return;
    vis[nod] = true;
    for(auto k : adj[nod]) DFS(k, adj);
    ord[ori] = nod;
    ori++;
}
void Color(int nod){
    if(comp[nod]!=0) return;
    comp[nod] = C;
    for(auto k : Adj2[nod]) Color(k);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin>>N>>M;
	forn(i,N) cin>>K[i+1];
    forn(i,M){
        int a,b;
        cin>>a>>b;
        Adj[a].push_back(b);
        Adj2[b].push_back(a);
        aris.push_back({a,b});
    }
    forn(i,N) if(vis[i+1]==0) DFS(i+1,Adj);
    dforn(i,ori)
    {
        int nod = ord[i];
        if(comp[nod]==0){
            Color(nod);
            C++;
        }
   //     cout<<nod<<" : "<<comp[nod]<<"\n";
        K2[comp[nod]]+=K[nod];
    }
    ori = 0;
    for(auto p : aris){
        int a = comp[p.first],b = comp[p.second];
        AdjC[a].push_back(b);
    }
    vis.reset();
    forsn(i,1,N+1){
        int nod = comp[i];
        if(vis[nod]==0)
            DFS(nod,AdjC);
    }
    dforn(i,ori){
        int nod = ord[i];
        dp[nod] += K2[nod];
        res = max(res,dp[nod]);
        for(auto k : AdjC[nod])
            dp[k] = max(dp[k],dp[nod]);
    }
    cout<<res<<"\n";
	return 0;
}
