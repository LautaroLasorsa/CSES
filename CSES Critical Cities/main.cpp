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
const int MAXN = 3e5;
const int lev = 19;
int ord[MAXN], LCA[MAXN][lev], ori = 0;
int id[MAXN];
vector<int> g[MAXN], g2[MAXN], gc[MAXN], comp[MAXN];
bitset<MAXN> visto;
void DFS(int n, vector<int> & lg){
    if(visto[n]) return;
    visto[n] = true;
    for(auto k : lg[n]) DFS(k);
    ord[ori] = n;
    ori++;
}
void Cond(int n, int c){
    if(visto[n]) return;
    visto[n] = true;
    id[n] = c;
    for(auto k : g2[n]) Cond(k,c);
}
int pad[MAXN], prof[MAXN];
void Add(int n){
    prof[n] = prof[LCA[n][0]]+1;
    forsn(i,1,lev) LCA[n][i] = LCA[LCA[n][i-1]][i-1];
}
int LCAF(int a, int b){
    if(a==-1) return b;
    if(b==-1) return a;
    if(a==b) return a;
    if(prof[a]>prof[b]) swap(a,b);
    dforn(i,lev) if(prof[LCA[b][i]]>=prof[a]) b = LCA[b][i];
    if(a == b) return a;
    dforn(i,lev){
        if(LCA[a][i] != LCA[b][i]){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    if(a==b) return a;
    return LCA[a][0];
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    forn(i,M){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g2[b].push_back(a);
    }
    DFS(1);
    memset(LCA,-1,sizeof(LCA));
    LCA[0][0] = 0;
    Add(0);
    LCA[1][0] = 0;
    visto.reset();
    dforn(i,ori) Cond(i,)
    dforn(i,ori){
        int n = ord[i];
        Add(n);
        cout<<"Padre de "<<n<<" : "<<LCA[n][0]<<endl;
        visto[n] = true;
        for(auto k : g[n])
            if(!visto[k])LCA[k][0] = LCAF(LCA[k][0],n);
    }
    vector<int> res;
    while(N!=0){
        res.push_back(N);
        N = LCA[N][0];
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<"\n";
    forn(i,res.size())cout<<res[i]<<((i==int(res.size()-1))?"\n":" ");
	return 0;
}
/*
7 14
1 2
2 1
2 3
3 2
3 4
4 3
3 5
5 3
4 6
6 4
5 6
6 5
6 7
7 6
*/
