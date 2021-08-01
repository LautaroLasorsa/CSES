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
const int maxn = 2e5 + 1;
set<int> col[maxn];
int pos[maxn], c[maxn], N, res[maxn];
vector<int> g[maxn];
int DFS(int n = 1, int p = 0){
    if(g[n].size() == 1 && n!=1 || g[n].size()==0){
        pos[n] = n;
        col[n].insert(c[n]);
        res[n] = 1;
        return n;
    }
    for(auto k : g[n])
        if(k!=p){
        int v = DFS(k,n);
        if(col[v].size()>col[pos[n]].size()) pos[n] = v;
    }
    for(auto k : g[n])
        if(k!=p && pos[k]!=pos[n])
            for(auto j : col[pos[k]])
                col[pos[n]].insert(j);
    col[pos[n]].insert(c[n]);
    res[n] = col[pos[n]].size();
    return pos[n];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>N;
    forsn(i,1,N+1)cin>>c[i];
    forn(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS();
    forsn(i,1,N+1)cout<<res[i]<<((i==N)?"\n":" ");
	return 0;
}
