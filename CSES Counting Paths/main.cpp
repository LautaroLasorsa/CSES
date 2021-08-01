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
const int maxn = 3e5, lev = 19;
vector<int> Adj[maxn];
int res[maxn], prof[maxn], LCA[maxn][lev], N, M;
int LCAF(int a, int b){
    if(a == b) return a;
    if(prof[a] > prof[b]) swap(a,b);
    dforn(i,lev){
        if(prof[LCA[b][i]]>=prof[a]) b = LCA[b][i];
    }
    if(a == b) return a;
    dforn(i,lev){
        if(LCA[a][i]!=LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    if(a == b) return a;
    return LCA[a][0];
}
void Calc(int n, int p){
    LCA[n][0] = p;
    prof[n] = prof[p]+1;
    forsn(i,1,lev) LCA[n][i] = LCA[LCA[n][i-1]][i-1];
    for(auto k : Adj[n]) if(k!=p) Calc(k,n);
}
int DFS(int n, int p){
    for(auto k : Adj[n])
        if(k!=p) res[n] += DFS(k,n);
    return res[n];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

	prof[0] = -1;
    cin>>N>>M;
    forn(i,N-1){
        int a,b;
        cin>>a>>b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    Calc(1,0);
    forn(i,M){
        int a,b;
        cin>>a>>b;
        res[a]++;
        res[b]++;
        int c = LCAF(a,b);
        res[c]--;
        res[LCA[c][0]]--;
    }
    DFS(1,1);
    forsn(i,1,N+1)cout<<res[i]<<((i==N)?"\n":" ");
}
