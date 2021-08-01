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
int sz[maxn],nxt[maxn],in[maxn],out[maxn], pad[maxn], val[maxn];
int t = 0;
vector<int> g[maxn];
void dfs_sz(int v = 1, int p = 0) {
    sz[v] = 1;
    pad[v] = p;
    for(auto &u: g[v]) {
        if(u==p) continue;
        dfs_sz(u,v);
        sz[v] += sz[u];
        if(sz[u] > sz[g[v][0]]) {
            swap(u, g[v][0]);
        }
    }
}
void dfs_hld(int v = 1, int p = 0) {
    in[v] = t++;
    for(auto u: g[v]) {
        if(u==p) continue;
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u,v);
    }
    out[v] = ++t;
}
const int largo = 1<<20;
intl st[largo];
int L[largo], R[largo], ini, fin;
intl Query(int i){
    //cout<<i<<" en "<<L[i]<<" a "<<R[i]<<" que vale "<<st[i]<<endl;
    if(ini<=L[i] && R[i] <= fin) return st[i];
    if(L[i]>fin || ini>R[i]) return 0;
    return Query(i*2) + Query(i*2+1);
}
void Update(int p, int v){
    p+=largo/2;
    st[p] = v;
    while(p/=2) st[p] = st[p*2] + st[p*2+1];
}
intl Path(int a, int b){
    intl res = 0;
    while(nxt[a]!=nxt[b]){
        if(in[nxt[a]]>in[nxt[b]]) swap(a,b);
        ini = in[nxt[b]];
        fin = in[b];
        res+=Query(1);
        b = pad[nxt[b]];
    }
    if(in[a]>in[b]) swap(a,b);
    ini = in[a];
    fin = in[b];
    res+=Query(1);
    return res;
}
intl SubtTree(int n){
    ini = in[n];
    fin = out[n]-1;
    //cout<<ini<<" a "<<fin<<endl;
    return Query(1);
}
int N,Q;
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    forsn(i,largo/2,largo) L[i] = R[i] = i-largo/2;
    cin>>N>>Q;
    forn(i,N) cin>>val[i+1];
    forn(i,N-1){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs_sz();
    dfs_hld();
    forsn(i,1,N+1)
    {
        st[in[i]+largo/2] = val[i];
    //    cout<<in[i]<<" : "<<val[i]<<endl;
    }
    dforn(i,largo/2){
        L[i] = L[i*2];
        R[i] = R[i*2+1];
        st[i] = st[i*2] + st[i*2+1];
    }
   // forsn(i,1,N+1)cout<<i<<" > "<<in[i]<<" a "<<out[i]<<endl;
    forn(i,Q){
        int tip;
        cin>>tip;
        if(tip == 1){
            int s,x;
            cin>>s>>x;
            Update(in[s],x);
        }else{
            int s;
            cin>>s;
            cout<<Path(1,s)<<"\n";
        }
    }
	return 0;
}
/*
5 11
10 1 1 1 1
1 2
2 3
3 4
4 5
2 1
2 2
2 3
2 4
2 5
1 5 10
2 1
2 2
2 3
2 4
2 5

*/
